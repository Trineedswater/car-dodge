#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main(int argc, char** argv)
{
    /*Expecting user to input 2 ints as arguments, rows and columns length*/
    if (argc < 2)
    {
        printf("Please enter the file name to read the map from as an argument\n");
    }
    else
    {
        game_start(argv[1]);
    }

    return 0;
}