# Car-dodge
Little game in C used to demonstrate basic C programming principles. This repository contains struct, pointer, linked lists, file io, user input, terminal printing, and makefile implementation. The game has been tested with valgrind and shows 0 memory leaks, but do test it on your own device for safety.

## Table of Contents

- [Car dodge](Car-dodge)
  - [Table of Contents](##table-of-contents)
  - [How to run](#how-to-run)
  - [How to play](#how-to-play)
  - [Making your own map](#making-your-own-map)

# How to run:
  Compile c files with make and then run executable file with ./traffic
  
  ``` bash
  make
  ./traffic <name of map file eg. map.txt>
  ```

# How to play:
*Keyboard only!*

## movement
w  up
a left
s down
d right
u undo movement

## game
P player
G goal *move to this thing!*
\> car *dodge this thing!*

# Making your own map:
Maps are represented as a 2D string array where each character in the strings are a different game object.

0 empty space
1 road for car
2 car starting position
3 player starting position
4 goal starting position

Creating a map can be made from a txt file. The first line of the file is **super important** the 1st number should be the number of rows the map has and the 2nd number should be the number of columns the map has.
**Make sure to separate each character with a space!**
Look at map.txt for an example!

Once you're done give the map a name and load it into the game!!