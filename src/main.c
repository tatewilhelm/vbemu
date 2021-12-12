#include <stdio.h>
#include <stdbool.h>

enum System
{
    CHIP_8, SUPER_CHIP, GAME_BOY
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

struct Arguments argument_lexicalizer(int argc, char **argv)
{
    struct Arguments buffer;
    buffer.argv = argv;
    buffer.argc = argc;

    // if too many Arguments or too less
    if (argc != 3)
    {
        buffer.error = 1;
        return buffer;
    }

    // check if file exists
    FILE *file;
    if ((file = fopen(argv[1], "r")))
    {
        buffer.path = argv[1];
    } else {
        fclose(file);
        buffer.error = 3;
        return buffer;
    }

    if (argv[2] == "-8" || argv == "--chip-8")
    {
        buffer.system = CHIP_8;
    } else if (argv[2] == "-s" || argv == "--super-chip") {
        buffer.system = SUPER_CHIP;

    } else {
        buffer.error = 2;
    }
    // all good
    buffer.error = 0;
    return buffer;
}


int main(int argc, char **argv)
{
    printf("ARGC %i\n", argc);
    struct Arguments test = argument_lexicalizer(argc, argv);
    printf("Error code %i\n", test.error);
}



