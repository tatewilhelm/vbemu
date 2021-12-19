#include "memory.h"
#include <stdint.h>

uint16_t I = 0;
byte dt = 0;
byte st = 0;
uint16_t PC = CH8_START_INDEX;
byte stack_top = 0;

void mem_wipe() {
    for (int i = 0; i < CH8_MEMORY; i++)
        mem_set(i, 0); 
}

void reg_wipe() {
    for (int i = 0; i < CH8_REGISTERS; i++)
        reg_set(i, 0);
}

byte mem_get(int i) {
    //if (i < CH8_START_INDEX) return 0;
    if (i > CH8_MEMORY) return 0;
    return _ram[i];
}

void mem_set(int i, byte val) {
    //if (i < CH8_START_INDEX) return;
    if (i > CH8_MEMORY) return;
    _ram[i] = val;
}

void* mem_ptr(int i) {
    return _ram+i;
}

byte reg_get(int i) {
    if (i < 0) return 0;
    if (i > CH8_REGISTERS) return 0;
    return _regs[i]; 
}

void reg_set(int i, byte val) {
    if (i < 0) return;
    if (i > CH8_REGISTERS) return;
    _regs[i] = val;
}

void stack_push(uint16_t addr) {
    if (stack_top + 1 >= CH8_STACK) return;
    stack_top += 1;
    stack[stack_top] = addr;
}

void stack_pop() {
    if (stack_top < 0) stack_top = 0;
    if (stack_top == 0) return;
    stack_top -= 1;
    PC = stack[stack_top];
}



