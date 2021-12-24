#include "cpu.h"

uint8_t ram[0xFFFF];
struct gb_registers_t registers;


// These are used by the instructions,
uint8_t gb_get_high(uint16_t reg)
{
    return (reg & 0b1111111100000000) >> 8;
}

uint8_t gb_get_low(uint16_t reg)
{
    return reg & 0b0000000011111111;
}

uint8_t gb_get_single_register(struct gb_registers_t registers, char reg)
{
    switch (reg) {
        case 'a':
            return gb_get_high(registers.af);

        case 'A':
            return gb_get_high(registers.af);


        case 'f':
            return gb_get_low(registers.af);

        case 'F':
            return gb_get_low(registers.af);


        case 'b':
            return gb_get_high(registers.bc);

        case 'B':
            return gb_get_high(registers.bc);


        case 'c':
            return gb_get_low(registers.bc);
        case 'C':
            return gb_get_low(registers.bc);

        case 'd':
            return gb_get_high(registers.de);
        case 'D':
            return gb_get_high(registers.de);

        case 'e':
            return gb_get_low(registers.de);
        case 'E':
            return gb_get_low(registers.de);

        case 'h':
            return gb_get_high(registers.hl);
        case 'H':
            return gb_get_high(registers.hl);

        case 'l':
            return gb_get_low(registers.hl);
        case 'L':
            return gb_get_low(registers.hl);

        default:
            return 00000000; // Null
    }
}

uint8_t gb_simulate_cycles(int cycles)
{
    
}

// These functions below will be interface with the mainloop

void gb_open_rom(char *path)
{

}



/*
 * Instructions on Game Boy follow an overlap fetch/execute cycle. But instead of simulating the fetch
 * and the last instructions execute at the same time. We can just simulate an instruction without
 * fetch and just execute it after the last instruction has finished. That makes the overlap a lot easier to deal with.
 */

// NOP
// This is under control functions, but it's just here as an example

void gb_0x00()
{
    gb_simulate_cycles(4);
    registers.program_counter++;
}

/**********
 * 8 Bit LD
 **********/



// Instead of including all the functions below into the mainloop,
// we're just going to make a function that decodes it here.

void gb_execute()
{
    bool cb_prefix_activated = false;

    switch (ram[registers.program_counter])
    {
        // CB Prefix
        case (0xCB):
            cb_prefix_activated = true;
            break;

        case (0x00):
            gb_0x00();
            break;

    }

    // CB prefix instructions
    if (cb_prefix_activated)
    {

    }

}