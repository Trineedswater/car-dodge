/*Handles game logic*/

#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "map.h"
#include "linkedList.h"
#include "save.h"
#include "userInput.h"
#include "collision.h"
#include "animate.h"

/*Create game items and their initial values*/
void game_start(char *file_name)
{
    everything *game_objects = NULL;

    game_objects = game_load(file_name);

    if (!game_objects)
    {
        perror("Error loading in game");
    }
    else
    {
        printf("Starting game\n");
        game_objects = game_loop(game_objects);
        free_map(game_objects->map, game_objects->rows);
        free_game_objects(game_objects);
    }
}

everything *build_from_file(FILE *file, everything *game_objects)
{
    int done = 0, stream_char = 0, posx = 1, posy = 1;
    char **map = game_objects->map;
    
    do
    {
        stream_char = fgetc(file);

        if (stream_char < 0)
        {
            if (ferror(file))
            {
                perror("Error reading from map file");
            }
            done = 1;
        }
        else
        {
            switch (stream_char)
            {
                case ' ':
                    break;
                case '\n':
                    posy++;
                    posx = 1;
                    break;
                case '3': /*player*/
                    game_objects->player = set_player(posx, posy);
                    map[posy][posx] = ' ';
                    posx++;
                    break;
                case '4': /*goal*/
                    game_objects->goal = set_goal(posx, posy);
                    map[posy][posx] = ' ';
                    posx++;
                    break;
                case '2': /*car (always faces east)*/
                    game_objects->car = set_car(posx, posy);
                    map[posy][posx] = '.';               
                    posx++;
                    break;
                case '1': /*road*/
                    map[posy][posx] = '.'; 
                    posx++;
                    break;
                case '0': /*white space*/
                    map[posy][posx] = ' ';
                    posx++;
                    break; /*Regret not making these characters constants*/
                default:
                    printf("Invalid character '%c' in file at position: %d,%d\n",stream_char,posx,posy);
                    break;
            }
        }
    }while (!done);

    return game_objects;
}

everything *game_load(char *file_name)
{
    FILE *file = NULL;
    everything *game_objects = NULL;
    int rows = 0, cols = 0;

    file = fopen(file_name, "r");
    if (!file)
    {
        perror("Error opening file");
    }
    else
    {
        fscanf(file, "%d %d\n", &rows, &cols); /*No error checking for this read :> i hope nothing goes wrong :>*/
        if (rows < 1 || cols < 1)
        {
            printf("Rows and column sizes are invalid - row and column sizes must be greater than 0 and formatted <rows> <columns> at the start of the file.\n");
        }
        else
        {
            game_objects = (everything*)malloc(sizeof(everything));
            game_objects->map = set_map(rows, cols);
            game_objects->rows = rows;
            game_objects->columns = cols;
            game_objects = build_from_file(file, game_objects);
        }
        fclose(file);
    }
    file = NULL;

    return game_objects;
}

everything *game_loop(everything *game_objects)
{
    int game_over = 0;
    LinkedList *game_history = createLinkedList();

    save_state(game_history, game_objects);

    while (!game_over)
    {
        /*Animate*/
        draw_frame(game_objects->map, game_objects);
        print_controls();

        /*Player movement*/
        reset_player_movement(game_objects->player);
        do 
        {
            reset_player_movement(game_objects->player);
            player_move(game_objects->player);
        }while (!check_bounds(&(game_objects->player->position), game_objects->rows, game_objects->columns));

        if (!is_stationary(&(game_objects->player->position)))/*wish I didn't couple player movement and user input so much in assignment 1*/
        {
            save_state(game_history, game_objects);

            /*Update positions of everything*/
            update_position(&(game_objects->player->position));
            update_car_position(game_objects->car, game_objects->map);

            /*Check collisions*/
            player_car_collision(game_objects->player, game_objects->car);
            player_goal_collision(game_objects->player, game_objects->goal);
        }
        else
        {
            /*load game from list*/
            if(game_history->size > 0)
            {
                game_objects = load_state(game_history, game_objects);
            }
        }

        if (game_objects->player->win_state)
        {
            /*Win screen?*/
            draw_frame(game_objects->map, game_objects);
            printf("you win yay!\n");
            game_over = 1;
        }
        else if (game_objects->player->dead_state)
        {
            /*Lost screen?*/
            draw_frame(game_objects->map, game_objects);
            printf("you lose no!\n");
            game_over = 1;
        }
    }

    free_history(game_history);
    return game_objects;
}

/*Regretting not having split game_loop() off into another file*/
