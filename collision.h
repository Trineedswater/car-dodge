#ifndef COLLISION_H
#define COLLISION_H
#include "structs.h"

#define swap(a,b) a^=b^=a^=b;

void update_position(position *pos);
void check_road_car(position *pos, char **map);
void update_car_position(car *car, char **map);
int check_collision(position *pos_a, position *pos_b);
int check_bounds(position *pos, int xlim, int ylim);
void update_collision_state(player *player);
void player_car_collision(player *player, car *car);
void player_goal_collision(player *player, goal *goal);
int is_stationary(position *position);
#endif