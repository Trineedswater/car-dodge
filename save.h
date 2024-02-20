#ifndef SAVE_H
#define SAVE_H
#include "structs.h"

void save_state(LinkedList *game_history, everything *game_objects);
everything *load_state(LinkedList *game_history, everything *game_objects);
void free_game_objects(void *data);
void free_history(LinkedList *game_history);

#endif