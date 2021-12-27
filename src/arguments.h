#ifndef VBEMU_ARGUMENTS_H
#define VBEMU_ARGUMENTS_H

#include <stdbool.h>

enum System
{
    UNDEFINED, CHIP_8, SUPER_CHIP, GAME_BOY
};



struct Arguments
{

    int argc;
    char **argv;
    const char *path;
    enum System system;
    bool verbose;
};

struct Arguments argument_lexicalizer(int argc, char **argv);


#endif //VBEMU_ARGUMENTS_H
