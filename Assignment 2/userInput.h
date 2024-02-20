#ifndef USERINPUT_H
#define USERINPUT_H
#include "structs.h"

void print_controls();
int is_valid_input(char input);
void char_to_move(player *player, char movement);
void get_user_input(char *input_address);
void player_move(player* player);
void reset_player_movement(player* player);

#endif