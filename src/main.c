#include <stdio.h>
#include "arguments.h"

int main(int argc, char **argv) {

    struct Arguments arguments = argument_lexicalizer(argc, argv);

    // Error management
    if (arguments.error != 0)
    {
        printf("vbemu: Given arguments threw a internal %d error.\n", arguments.error);
        switch(arguments.error)
        {
            // Make sure to be compliant with posix exit codes.
            case 1:
                return 7;
            case 2:
                return 22;
            case 3:
                return 2;
        }
    }

    // Start system
    switch (arguments.system) {
        int return_code;
        case GAME_BOY:
            printf("vbemu: Starting Game Boy mode\n");
            break;
        case CHIP_8:
            printf("vbemu: Starting Chip 8 mode\n");
            break;
        case SUPER_CHIP:
            printf("vbemu: Starting Super Chip 8 mode\n");
            break;
        case UNDEFINED:
            printf("vbemu: Undefined system\n");
            return -1;
    }
}



