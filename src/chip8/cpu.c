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
    return 0;    
}

void parse(uint16_t ptr) {
    byte b1 = mem_get(ptr);
    byte b2 = mem_get(ptr+1);
    if (!b1 && !b2) return;
    printf("%02X%02X", b1, b2);
    printf("\n");
}
