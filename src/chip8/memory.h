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

extern byte _ram[CH8_MEMORY]; // Ram
extern byte _regs[CH8_REGISTERS]; // Registers
extern uint16_t I; // Special register for addresses
extern byte dt; // Delay timer 
extern byte st; // Sound timer
extern uint16_t PC; // Program counter
extern uint16_t stack[CH8_STACK];
extern byte stack_top;

void mem_wipe();
void reg_wipe();
byte mem_get(int i); // Access ram
void mem_set(int i, byte val);
void* mem_ptr(int i);
byte reg_get(int i); // Access registers
void reg_set(int i, byte val);

void stack_push(uint16_t addr);
void stack_pop();

