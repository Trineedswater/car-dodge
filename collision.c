/*Some functions may be unused but are kept for sake of modularity and flexibility :>*/
#include <stdio.h>
#include <stdlib.h>
#include "collision.h"

void update_position(position *pos)
{
    pos->x = (pos->x + pos->dx);
    pos->y = (pos->y + pos->dy);
}

void check_road_car(position *pos, char **map)
{
    int cur_x = 0, cur_y = 0, next_x = 0, next_y = 0, temp;

    /*Car will only move if its current position and next position (after velocities are added) are on a road tile*/
    cur_x = pos->x;
    cur_y = pos->y;
    next_x = pos->x + pos->dx;
    next_y = pos->y + pos->dy;
    /*Check forward relative to the car*/
    /*If no road exists where car is heading*/
    if (map[cur_y][next_x] != '.' || map[next_y][cur_x] != '.') /*since either dx or dy will be 0, one of condition will be on the car*/
    {
        /*Check anticlockwise of car for road*/
        next_x = cur_x + pos->dy;
        next_y = cur_y - pos->dx;
        if (map[cur_y][next_x] != '.' || map[next_y][cur_x] != '.') /*should define this function*/
        {
            /*Check clockwise of car for road*/
            next_x = cur_x - pos->dy;
            next_y = cur_y + pos->dx;
            if (map[cur_y][next_x] != '.' || map[next_y][cur_x] != '.')
            {
                /*Car meets a dead end x.x */
                /*Reverse the velocity of car (so it either goes back or stays still)*/
                pos->dx = -(pos->dx);
                pos->dy = -(pos->dy);
                next_x = cur_x + pos->dx;
                next_y = cur_y + pos->dy;
            }
            else
            {
                /*rotate car clockwise*/
                temp = pos->dx;
                pos->dx = -(pos->dy);
                pos->dy = temp;
            }
        }
        else
        {
            /*rotate car anticlockwise*/
            temp = pos->dx;
            pos->dx = pos->dy;
            pos->dy = -(temp);
        }
    }
    /*I don't like nested ifs but since order of these checks is important, the 'matrix transformations' have a specific order so I can't just loop it :<*/
    pos->x = next_x;
    pos->y = next_y;
}

void update_car_position(car *car, char **map)
{
    check_road_car(&(car->position), map);
    if (car->position.dx > 0)
    {
        car->image = '>';
    }
    else if (car->position.dx < 0)
    {
        car->image = '<';
    }
    else if (car->position.dy > 0)
    {
        car->image = 'v';
    }
    else if (car->position.dy < 0)
    {
        car->image = '^';
    }
}

int check_collision(position *pos_a, position *pos_b)
{
    int collided = 0;

    if (pos_a->x == pos_b->x && pos_a->y == pos_b->y)
    {
        collided = 1;
    }
    else
    {
        collided = 0;
    }

    return collided;
}

int check_bounds(position *pos, int ylim, int xlim)
{
    int in_bound = 0, next_x, next_y;
    next_x = pos->x + pos->dx;
    next_y = pos->y + pos->dy;

    if (next_x > xlim || next_y > ylim || next_x <= 0 || next_y <= 0)
    {
        in_bound = 0;
    }
    else
    {
        in_bound = 1;
    }

    return in_bound;
}

/*If player position and car position match*/
void player_car_collision(player *player, car *car)
{
    if(check_collision(&(player->position), &(car->position)))
    {
        player->collision_state = 1;
        player->dead_state = 1;
        car->collision_state = 1;
    }
}

void player_goal_collision(player *player, goal *goal)
{
    if (check_collision(&(player->position), &(goal->position)))
    {
        player->collision_state = 1;
        player->win_state = 1;
        goal->collision_state = 1;
    }
}

int is_stationary(position *position)
{
    int stationary = 0;

    if ((position->dx + position->dy) == 0)
    {
        stationary = 1;
    }
    else
    {
        stationary = 0;
    }
    return stationary;
}
