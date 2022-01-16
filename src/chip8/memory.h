#pragma once 
#include <inttypes.h>

// 4096 bytes of ram, first 512 reserved
#define CH8_MEMORY 4096
#define CH8_START_INDEX 512
// 16 8-bit registers
#define CH8_REGISTERS 16
// 16 levels of stack
#define CH8_STACK 16

typedef uint8_t byte;

typedef struct {
    byte ram[CH8_MEMORY]; // Ram
    byte registers[CH8_REGISTERS]; // Registers
    uint16_t I; // Special register for addresses
    byte dt; // Delay timer 
    byte st; // Sound timer
    uint16_t PC; // Program counter
    uint16_t stack[CH8_STACK];
    byte stack_top;
} Program;

Program create_program();

