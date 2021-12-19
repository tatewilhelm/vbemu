#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "arguments.h"


struct Arguments argument_lexicalizer(int argc, char **argv)
{
    struct Arguments buffer;
    buffer.argv = argv;
    buffer.argc = argc;

    // if too many Arguments or too less
    if (argc != 3)
    {
        buffer.error = 1;
        buffer.system = UNDEFINED;
        buffer.path = "null";
        return buffer;
    }

    // check if file exists
    FILE *file;
    if ((file = fopen(argv[1], "r")))
    {
        buffer.path = argv[1];
    } else {
        buffer.error = 3;
        buffer.system = UNDEFINED;
        buffer.path = argv[1];
        return buffer;
    }



    if (strcmp(argv[2], "--chip-8") == false)
    {
        buffer.system = CHIP_8;
    } else if (strcmp(argv[2], "--super-chip") == false) {
        buffer.system = SUPER_CHIP;
    } else if (strcmp(argv[2], "--game-boy") == false) {
        buffer.system = GAME_BOY;
    } else {
        buffer.error = 2;
    }

    // all good
    buffer.error = 0;
    return buffer;
}

