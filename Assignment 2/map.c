/*Handles loading game objects into a map (2D array)*/
/*Also handles freeing data*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

char **set_map(int rows, int cols)
{
    int i = 0;
    char **map;
    map = (char**)malloc(sizeof(char*) * (rows + 2));

    for (i = 0; i < (rows + 2); i++)
    {
        map[i] = (char*)malloc(sizeof(char) * (cols + 2));
        map[i][0] = '*'; /*Making the left and right borders*/
        map[i][cols + 1] = '*';
    }

    for (i = 1; i < (cols + 1); i++)
    {
        /*top and bottom borders*/
        map[0][i] = '*';
        map[(rows + 1)][i] = '*';
    }
    
    return map;
}

void free_map(char **map, int rows)
{
    int i = 0;
    
    for (i = 0; i < (rows + 2); i++)
    {
        free(map[i]);
        map[i] = NULL;
    }
    free(map);
    map=NULL;
}