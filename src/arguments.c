#include <stdio.h>
#include <string.h>
#include "arguments.h"


struct Arguments argument_lexicalizer(int argc, char **argv)
{
    struct Arguments buffer;
    buffer.argv = argv;
    buffer.argc = argc;
    buffer.system = UNDEFINED;
    buffer.path = NULL;

    for (int i = 1; i < argc; i++)
    {
        // Check if file exists, if so, setting that to the path.
        FILE *file = fopen(argv[i], "r");
        if (file)
        {
            // File exists
            fclose(file);
            buffer.path = argv[i];
        }

        // Check for systems
        if ((strcmp(argv[i], "--chip-8") == 0)  || (strcmp(argv[i], "-8") == 0)) {
            buffer.system = CHIP_8;
        } else if ((strcmp(argv[i], "--super-chip") == 0)  || (strcmp(argv[i], "-s") == 0)) {
            buffer.system = SUPER_CHIP;
        } else if ((strcmp(argv[i], "--game-boy") == 0)  || (strcmp(argv[i], "-g") == 0)) {
            buffer.system = GAME_BOY;
        }

    }
    return buffer;
}
