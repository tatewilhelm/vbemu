#pragma once 
#include <inttypes.h>

// 4096 bytes of ram, first 512 reserved
#define CH8_MEMORY 4096
#define CH8_START_INDEX 512
// 16 8-bit registers
#define CH8_REGISTERS 16
// 16 levels of stack
#define CH8_STACK 16
// 64x32 Screen
#define CH8_SCREEN_WIDTH 64 
#define CH8_SCREEN_HEIGHT 32
// Max sprite size
#define CH8_MAX_SPRITE 5

typedef uint8_t byte;

typedef struct {
    byte ram[CH8_MEMORY]; 
    uint64_t vram[CH8_SCREEN_HEIGHT]; 
    byte registers[CH8_REGISTERS];
    uint16_t I; // Special register for addresses
    uint16_t PC; // Program counter
    uint16_t stack[CH8_STACK];
    byte dt; // Delay timer 
    byte st; // Sound timer
    byte stack_top;
} Program;

Program* create_program();

