#include "cpu.h"
int mhz = 1;
uint8_t get_high(uint16_t reg)
{
    return (reg & 0b1111111100000000) >> 8;
}

uint8_t get_low(uint16_t reg)
{
    return reg & 0b0000000011111111;
}

uint8_t get_single_register(struct gb_registers_t registers, char reg)
{
    switch (reg) {
        case 'a':
            return get_high(registers.af);

        case 'A':
            return get_high(registers.af);


        case 'f':
            return get_low(registers.af);

        case 'F':
            return get_low(registers.af);


        case 'b':
            return get_high(registers.bc);

        case 'B':
            return get_high(registers.bc);


        case 'c':
            return get_low(registers.bc);
        case 'C':
            return get_low(registers.bc);

        case 'd':
            return get_high(registers.de);
        case 'D':
            return get_high(registers.de);

        case 'e':
            return get_low(registers.de);
        case 'E':
            return get_low(registers.de);

        case 'h':
            return get_high(registers.hl);
        case 'H':
            return get_high(registers.hl);

        case 'l':
            return get_low(registers.hl);
        case 'L':
            return get_low(registers.hl);

        default:
            return 00000000; // Null
    }
}

uint8_t simulate_cycles(int cycles)
{
    
}

/*
 * Instructions,
 *
 * Instructions on Game Boy follow an overlap fetch/execute cycle. But instead of simulating the fetch
 * and the last instructions execute at the same time. We can just simulate an instruction without
 * fetch and just execute it after the last instruction has finished.
 */


