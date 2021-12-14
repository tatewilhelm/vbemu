#include "cpu.h"
#include <stdint.h>

void parse(uint16_t ptr) {
    byte b1 = mem_get(ptr);
    byte b2 = mem_get(ptr+1);
    
}
