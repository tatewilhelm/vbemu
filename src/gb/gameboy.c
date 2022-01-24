#include "gameboy.h"
#include "cpu/cpu.h"
#include "clock/clock.h"
#include "gfx/gfx.h"
#include "window/window.h"
#include <time.h>
#include <stdbool.h>


int start_gameboy(struct Arguments arguments)
{
    bool should_exit = false;

    // init
    gb_init_gfx();
    gb_open_rom(arguments.path);

    while (!should_exit)
    {
        gb_execute();
        should_exit = 1;
    }
    return 0;
}
