#include <stdbool.h>
#include "gameboy.h"
#include "ram.h"
#include "cpu.h"



int start_gameboy(struct Arguments arguments) {
    if (gb_load_rom(arguments.path)) {

    }
}
