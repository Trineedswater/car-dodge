#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"
#include "save.h"

void save_state(LinkedList *game_history, everything *game_objects)
{
    everything *new_instance = (everything*)malloc(sizeof(everything));
    new_instance->player = copy_player(game_objects->player);
    new_instance->goal = copy_goal(game_objects->goal);
    new_instance->car = copy_car(game_objects->car);
    new_instance->map = game_objects->map;
    new_instance->rows = game_objects->rows;
    new_instance->columns = game_objects->columns;
    insertStart(game_history, new_instance);
}

everything *load_state(LinkedList *game_history, everything *game_objects)
{
    everything *temp;
    free_game_objects(game_objects);
    temp = (everything*)removeStart(game_history);
    return temp;
}

void free_game_objects(void *data)
{
    everything *game_objects = (everything*)data;
    free(game_objects->player);
    free(game_objects->goal);
    free(game_objects->car);
    game_objects->player = NULL;
    game_objects->goal = NULL;
    game_objects->car = NULL;
    game_objects->map = NULL;
    free(game_objects);
    game_objects = NULL;
    data = NULL;
}

void free_history(LinkedList *game_history)
{
    freeLinkedList(game_history, &free_game_objects);
}