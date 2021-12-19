#ifndef VBEMU_CONFIGURATION_H
#define VBEMU_CONFIGURATION_H

#include <stdio.h>

struct configuration_t
{
    char *path_to_rom;
};

struct configuration_t gb_get_configuration(char *path)
{
    FILE *file = fopen("~/.vbemu/dgb/config/dgb.conf", "r");
    char *buffer;
    fgets( buffer, 255, file);

    // Find colon
    for (int i = 0; i < sizeof(buffer); i++)
    {
        if (buffer[i] == ':')
        {

        }
    }
    return null;
}
#endif //VBEMU_CONFIGURATION_H
