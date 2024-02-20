#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animate.h"

/*Takes in all structs and clears the screen, printing the map out line by line while subsituting in the struct if it is in the same line position*/
void draw_frame(char **map, everything *game_objects)
{
    int i = 0;
    char **frame = (char**)malloc((game_objects->rows + 2) * sizeof(char*));

    system("clear");
    for (i = 0; i < (game_objects->rows + 2); i++)
    {
        frame[i] = (char*)malloc((game_objects->columns + 2) * sizeof(char));
        strncpy(frame[i], map[i], game_objects->columns + 2);
    }

    frame[game_objects->player->position.y][game_objects->player->position.x] = game_objects->player->image;
    frame[game_objects->goal->position.y][game_objects->goal->position.x] = game_objects->goal->image;
    frame[game_objects->car->position.y][game_objects->car->position.x] = game_objects->car->image;

    for (i = 0; i < (game_objects->rows + 2); i++)
    {
        printf("%s\n",frame[i]);
        free(frame[i]);
        frame[i] = NULL;
    }
    free(frame);
    frame = NULL;
}
