#include "cpu.h"




// These are used by the instructions,
uint8_t gb_get_high(uint16_t reg)
{
    return (reg & 0b1111111100000000) >> 8;
}

uint8_t gb_get_low(uint16_t reg)
{
    return reg & 0b0000000011111111;
}

void gb_set_high(uint16_t *reg, uint8_t value)
{
    *reg = (value << 8) + gb_get_low(*reg);
}

void gb_set_low(uint16_t *reg, uint8_t value)
{
    *reg = gb_get_high(*reg) + value;
}
void gb_simulate_cycles(int cycles)
{
    
}

void gb_set_zero_flag(bool state)
{
    if (state)
    {
        gb_set_low(&registers.af, gb_get_low(registers.af) | 0b1000000);
    } else {
        gb_set_low(&registers.af, gb_get_low(registers.af) & 0b01111111);
    }
}

void gb_set_subtraction_flag(bool state)
{
    if (state)
    {
        gb_set_low(&registers.af, gb_get_low(registers.af) | 0b0100000);
    } else {
        gb_set_low(&registers.af, gb_get_low(registers.af) & 0b10111111);
    }
}

void gb_set_carry_flag(bool state)
{
    if (state)
    {
        gb_set_low(&registers.af, gb_get_low(registers.af) | 0b0001000);
    } else {
        gb_set_low(&registers.af, gb_get_low(registers.af) & 0b11101111);
    }

}

void gb_set_half_carry_flag(bool state)
{
    if (state)
    {
        gb_set_low(&registers.af, gb_get_low(registers.af) | 0b0010000);
    } else {
        gb_set_low(&registers.af, gb_get_low(registers.af) & 0b11011111);
    }
}

// These functions below will be interfaced with the mainloop
void gb_open_rom(const char *path)
{

}




/*
 * Instructions on Game Boy follow an overlap fetch/execute cycle. But instead of simulating the fetch
 * and the last instructions execute at the same time. We can just simulate an instruction without
 * fetch and just execute it after the last instruction has finished. That makes the overlap a lot easier to deal with.
 */


// NOP
void gb_0x00()
{
    gb_start_clock();
    registers.program_counter++;
    gb_stop_simulate_clock(4);
}

// RLC B
void gb_CB_0x00()
{
    uint16_t byte;
    byte = gb_get_high(registers.bc) << 1;
    if (byte > 0xFF)
    {
        byte -= 0xFF;
        gb_set_carry_flag(true);
    } else {
        gb_set_carry_flag(false);
    }

    if (byte == 0x00) {
        gb_set_zero_flag(true);
    } else {
        gb_set_zero_flag(false);
    }

    gb_set_high(&registers.bc, byte);


    registers.program_counter++;
}

// LD BC, u16
void gb_0x01()
{
    gb_start_clock();
    gb_set_low(&registers.af, ram[registers.program_counter + 1]);
    gb_set_high(&registers.af, ram[registers.program_counter + 2]);
    registers.program_counter += 3;
    gb_stop_simulate_clock(12);
}

// LD (BC), A
void gb_0x02()
{
    gb_start_clock();
    ram[registers.bc] = gb_get_high(registers.af);
    registers.program_counter++;
    gb_stop_simulate_clock(8);
}

// INC BC
void gb_0x03()
{
    gb_start_clock();
    registers.af++;
    registers.program_counter++;
    gb_stop_simulate_clock(8);
}

// INC B
void gb_0x04()
{
    gb_start_clock();

    // Increment
    gb_set_high(&registers.bc, gb_get_high(registers.bc) + 1);

    // Zero flag
    if (gb_get_high(registers.bc) == 0)
    {
        gb_set_zero_flag(1);
    } else {
        gb_set_zero_flag(0);
    }
    // Subtraction / Negative Flag
    gb_set_subtraction_flag(0);

    // Half Carry flag
    if (((gb_get_high(registers.bc) - 1) & 0xF) + 1 == 0x10)
    {
        gb_set_half_carry_flag(1);
    } else {
        gb_set_half_carry_flag(0);
    }


    registers.program_counter++;
    gb_stop_simulate_clock(4);
}


// DEC B
void gb_0x05()
{
    gb_start_clock();

    // Decrement
    gb_set_high(&registers.bc, gb_get_high(registers.bc) - 1);

    // Zero flag
    if (gb_get_high(registers.bc) == 0)
    {
        gb_set_zero_flag(1);
    } else {
        gb_set_zero_flag(0);
    }
    // Subtraction / Negative Flag
    gb_set_subtraction_flag(0);

    // Half Carry flag
    if (gb_get_high(registers.bc) == 0xF)
    {
        gb_set_half_carry_flag(1);
    } else {
        gb_set_half_carry_flag(0);
    }

    registers.program_counter++;
    gb_stop_simulate_clock(4);
}

// LD B, u8
void gb_0x06()
{
    gb_start_clock();
    gb_set_high(&registers.bc, ram[registers.program_counter + 1]);
    registers.program_counter += 2;
    gb_stop_simulate_clock(4);
}

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
            registers.program_counter++;
            break;

        case (0x00):
            gb_0x00();
            break;

    }

    // CB prefix instructions
    if (cb_prefix_activated)
    {
        switch (ram[registers.program_counter])
        {

            case (0x00):
                gb_CB_0x00();
                break;

        }

    }

}



