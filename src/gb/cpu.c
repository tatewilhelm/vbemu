#include "cpu.h"
#include <stdint.h>



struct Registers {
    uint16_t af;
    uint16_t bc;
    uint16_t de;
    uint16_t hl;
    uint16_t stack_pointer;
    uint16_t program_counter;
};



bool load_rom(char *path)
{

}