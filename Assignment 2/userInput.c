#include <stdlib.h>
#include <stdio.h>
#include "terminal.h"
#include "collision.h"
#include "userInput.h"

void print_controls()
{
    printf("Press w to move up\nPress s to move down\nPress a to move left\nPress d to move right\n");
}

int is_valid_input(char input)
{
    int valid = 0;
    switch (input)
    {
        case 'w':
        case 'a':
        case 's':
        case 'd':
        case 'u':
            valid = 1;
            break;
        default:
            valid = 0;
            break;
    }
    return valid;
}

void char_to_move(player *player, char movement)
{
    switch (movement)
    {
        case 'w':
            player->position.dy = -1;
            break;
        case 'a':
            player->position.dx = -1;
            break;
        case 's':
            player->position.dy = 1;
            break;
        case 'd':
            player->position.dx = 1;
            break;
        case 'u':
            reset_player_movement(player);
            break;
        default:
            printf("Error updating player movement\n");
            break;
    }
}

void get_user_input(char *input_address)
{
    int valid = 0;
    while(!valid)
    {
        disableBuffer();
        scanf(" %c",input_address);
        enableBuffer();
        valid = is_valid_input(*input_address);
    }
}

void player_move(player* player)
{
    char movement;
    get_user_input(&movement);
    char_to_move(player, movement);
}

void reset_player_movement(player* player) /*Should've put this in collision.c*/
{
    player->position.dx = 0;
    player->position.dy = 0;
}
