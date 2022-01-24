#ifndef VBEMU_CPU_H
#define VBEMU_CPU_H

#include <stdbool.h>
#include <stdint.h>
#include "../clock/clock.h"

struct gb_registers_t {
    uint16_t af;
    uint16_t bc;
    uint16_t de;
    uint16_t hl;
    uint16_t stack_pointer;
    uint16_t program_counter;
};

// GFX needs access to ram and registers, so we are just gonna make them open
// Ram contains both cpu ram & vram.
uint8_t ram[0xFFFF];
struct gb_registers_t registers;


// Interfaces with mainloop
void gb_execute();
void gb_open_rom(const char *path);


#endif //VBEMU_CPU_H
