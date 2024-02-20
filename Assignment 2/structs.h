#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct position
{
    int x; 
    int y;
    int dx; /*Velocities*/
    int dy;
} position;

/*Treating player, cars and goal structs as objects sort of*/
typedef struct player
{
    struct position position;
    int win_state;
    int dead_state;
    int collision_state;
    char image;
} player;

typedef struct car
{
    struct position position;
    int collision_state;
    char image;
} car;

typedef struct goal
{
    struct position position;
    int collision_state;
    char image;
} goal;

typedef struct everything /*"The everything struct" makes sense to me even though it's not conventional*/
{
    struct player *player;
    struct car *car;
    struct goal *goal;
    char **map;
    int rows;
    int columns;
} everything;

player *set_player(int x, int y);
goal *set_goal(int x, int y);
car *set_car(int x, int y);
player *copy_player(player *old_player);
goal *copy_goal(goal *old_goal);
car *copy_car(car *old_car);

#endif