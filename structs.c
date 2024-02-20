#include <stdlib.h>
#include <stdio.h>
#include "structs.h"

/*It's like they're constructors*/

player *set_player(int x, int y)
{
    struct player *player;
    player = (struct player*)malloc(sizeof(struct player));
    player->position.x = x;
    player->position.y = y;
    player->position.dx = 0;
    player->position.dy = 0;
    player->dead_state = 0;
    player->win_state = 0;
    player->collision_state = 0;
    player->image = 'P';
    return player;
}

goal *set_goal(int x, int y)
{
    struct goal *goal;
    goal = (struct goal*)malloc(sizeof(struct goal));
    goal->position.x = x;
    goal->position.y = y;
    goal->position.dx = 0;
    goal->position.dy = 0;
    goal->collision_state = 0;
    goal->image = 'G';
    return goal;
}

car *set_car(int x, int y)
{
    struct car *car;
    car = (struct car*)malloc(sizeof(struct car));
    car->position.x = x;
    car->position.y = y;
    car->position.dx = 1;
    car->position.dy = 0;
    car->collision_state = 0;
    car->image = '>';
    return car;
}

player *copy_player(player *old_player)
{
    player *new_player = (player*)malloc(sizeof(player));
    new_player->position = old_player->position;
    new_player->dead_state = old_player->dead_state;
    new_player->win_state = old_player->win_state;
    new_player->collision_state = old_player->collision_state;
    new_player->image = old_player->image;
    return new_player;
}

goal *copy_goal(goal *old_goal)
{
    goal *new_goal = (goal*)malloc(sizeof(goal));
    new_goal->position = old_goal->position;
    new_goal->collision_state = old_goal->collision_state;
    new_goal->image = old_goal->image;
    return new_goal;
}

car *copy_car(car *old_car)
{
    car *new_car = (car*)malloc(sizeof(car));
    new_car->position = old_car->position;
    new_car->collision_state = old_car->collision_state;
    new_car->image = old_car->image;
    return new_car;
}