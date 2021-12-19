#include "cpu.h"
#include <stdint.h>
#include <stdio.h>

byte strip(byte val, byte keep_mask) {
    return val & keep_mask;
}

int match(byte v1, byte v2) {
    return (v1 & v2) == v1;
}

int imatch(byte v1, byte v2, byte keep_mask) { 
    v1 = strip(v1, keep_mask);
    v2 = strip(v2, keep_mask);
    return match(v1, v2);
}

int imatch16 (uint16_t v1, uint16_t v2, uint16_t keep_mask) {
    
}

void parse(uint16_t ptr) {
    printf("\n");
}
