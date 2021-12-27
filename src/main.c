#include <stdio.h>
#include <errno.h>
#include "arguments.h"



int main(int argc, char **argv) {

    struct Arguments arguments = argument_lexicalizer(argc, argv);

    // Error management
    if (arguments.path == NULL)
    {
        return EBADF;
    } else if (arguments.argc > 4) {
        return E2BIG;
    } else if (arguments.system == UNDEFINED) {
        return EINVAL;
    }

    // Start system
    int return_code = 0;
    switch (arguments.system) {
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
            break;
    }
    return return_code;
}



