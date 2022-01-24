#include <SDL2/SDL.h>
#include "window.h"

int gb_init_window()
{


    if((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)) {
        printf("gameboy: Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }


}


void gb_kill_window()
{
    SDL_Quit();
}
