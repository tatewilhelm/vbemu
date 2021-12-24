#include <stdbool.h>
#include <stdint.h>
#include "../ram/ram.h"


#ifndef VBEMU_CPU_H
#define VBEMU_CPU_H

int gb_hz = 4000000;

struct gb_registers_t {
    uint16_t af;
    uint16_t bc;
    uint16_t de;
    uint16_t hl;
    uint16_t stack_pointer;
    uint16_t program_counter;
};


// Interfaces with mainloop


#endif //VBEMU_CPU_H
