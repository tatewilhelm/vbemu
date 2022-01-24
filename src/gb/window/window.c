#include <SDL2/SDL.h>
#include "window.h"

int gb_init_gfx()
{


    if((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)) {
        printf("gameboy: Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }

    SDL_Quit();


}

