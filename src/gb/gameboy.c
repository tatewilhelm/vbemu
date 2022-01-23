#include <stdbool.h>
#include "gameboy.h"
#include "cpu/cpu.h"
#include "clock/clock.h"
#include <SDL2/SDL.h>
#include <time.h>


int start_gameboy(struct Arguments arguments)
{

    printf("Initializing SDL.\n");

    /* Initialize defaults, Video and Audio */
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) {
        printf("gameboy: Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }

    printf("SDL initialized.\n");

    printf("Quiting SDL.\n");

    /* Shutdown all subsystems */
    SDL_Quit();

    printf("Quiting....\n");

    exit(0);
}
