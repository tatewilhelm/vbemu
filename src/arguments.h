#ifndef VBEMU_ARGUMENTS_H
#define VBEMU_ARGUMENTS_H


enum System
{
    UNDEFINED, CHIP_8, SUPER_CHIP, GAME_BOY
};


struct Arguments
{
    int error;
    /*
     * 0 is all good,
     * 1 is insufficient/too many Arguments,
     * 2 is arg(s) are not understood
     * 3 is file not found
     */
    int argc;
    char **argv;
    const char *path;
    enum System system;
};

struct Arguments argument_lexicalizer(int argc, char **argv);


#endif //VBEMU_ARGUMENTS_H
