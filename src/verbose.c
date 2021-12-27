#include <stdio.h>
#include "verbose.h"

struct Arguments args;


void verbose_init(struct Arguments *args)
{

}

void verbose_print(char *str)
{
    if (args.verbose)
    {
        printf("%s", str);
    }
}