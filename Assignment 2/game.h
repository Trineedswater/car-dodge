#ifndef GAME_H
#define GAME_H
#include "structs.h"

void game_start(char *file_name);
everything *build_from_file(FILE *file, everything *game_objects);
everything *game_load(char *file_name);
everything *game_loop(everything *game_objects);

#endif
