#include "memory.h"
#include <stdint.h>

Program create_program() { 
    Program ret = {};
    // Initialize all as zero
    for (int i = 0; i < CH8_MEMORY; i++)
        ret.ram[i] = 0; 
    for (int i = 0; i < CH8_REGISTERS; i++)
        ret.registers[i] = 0;
    for (int i = 0; i < CH8_STACK; i++)
        ret.stack[i] = 0;
    ret.I = 0;
    ret.dt = 0;
    ret.st = 0;
    ret.PC = 0;
    ret.stack_top = 0;
    return ret;
}

