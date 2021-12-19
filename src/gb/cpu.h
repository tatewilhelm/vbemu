#include <stdbool.h>
#include <stdint.h>

#ifndef VBEMU_CPU_H
#define VBEMU_CPU_H


struct gb_registers_t {
    uint16_t af;
    uint16_t bc;
    uint16_t de;
    uint16_t hl;
    uint16_t stack_pointer;
    uint16_t program_counter;
};




#endif //VBEMU_CPU_H
