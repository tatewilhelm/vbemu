#include <stdio.h>
#include "arguments.h"
#include "gb/gameboy.h"
#include "chip8/interp.h"


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
    int return_code = -1;
    printf("%i\n", arguments.system);
    switch (arguments.system) {
        case GAME_BOY:
            printf("vbemu: Starting Game Boy mode\n");
            return_code = start_gameboy(arguments);
            break;
        case CHIP_8:
            printf("vbemu: Starting Chip 8 mode\n");
            return_code = 0;
            return_code = start_chip8(arguments);
            break;
        case SUPER_CHIP:
            printf("vbemu: Starting Super Chip 8 mode\n");
            break;
        case UNDEFINED:
            printf("vbemu: Undefined system\n");
        return return_code;
    }
}



