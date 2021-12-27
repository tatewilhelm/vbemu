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
    // Painful but necessary block. Cannot recast to uint16_t due to little/big endian issues
    byte byte1 = mem_get(ptr); // First half of instruction
    byte hx1 = byte1 & 0x0F;
    byte hx2 = (byte1 & 0xF0) >> 4;
    byte byte2 = mem_get(ptr+1); // Second half
    byte hx3 = byte2 & 0x0F;
    byte hx4 = (byte2 & 0xF0) >> 4;
    uint16_t full = (byte1 << 8) | byte2; // Full instruction

    if (!byte1 && !byte2) return;
    printf("%04X - ", full);
    printf("%X %X %X %X \n", hx1, hx2, hx3, hx4);
    return;
    if (full == 0x00E0) printf("cls");
    if (full == 0x00EE) printf("ret");
    printf("\n");
}
