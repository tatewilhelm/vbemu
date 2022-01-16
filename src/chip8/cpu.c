#include "cpu.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


Cmd parse(byte b1, byte b2) {
    Cmd c = {};
    // Combine both bytes of instruction to single variable
    c.full = (b1 << 8) | b2;
    // Separate instruction into 4 bit chunks to aid interpreting
    c.hx1 = (c.full & 0xF000) >> 12;
    c.hx2 = (c.full & 0x0F00) >> 8;
    c.hx3 = (c.full & 0x00F0) >> 4;
    c.hx4 = (c.full & 0x000F);

   c.op = NOP; 

    if (c.full == 0) c.op = NOP; // NOP
    if (c.full == 0x00E0) c.op = CLS; 
    if (c.full == 0x00EE) c.op = RET; 
    if (c.hx1 == 0x1) c.op = JP; 
    if (c.hx1 == 0x2) c.op = CALL; 
    if (c.hx1 == 0x3) c.op = SE_VX; 
    if (c.hx1 == 0x4) c.op = SNE_VX; 
    if (c.hx1 == 0x5) c.op = SE_VXVY; 
    if (c.hx1 == 0x6) c.op = LD_VX; 
    if (c.hx1 == 0x7) c.op = ADD_VX; 
    if (c.hx1 == 0x8) {
        if (c.hx4 == 0x0) c.op = LD_VXVY; 
        if (c.hx4 == 0x1) c.op = OR_VXVY; 
        if (c.hx4 == 0x2) c.op = AND_VXVY; 
        if (c.hx4 == 0x3) c.op = XOR_VXVY; 
        if (c.hx4 == 0x4) c.op = ADD_VXVY; 
        if (c.hx4 == 0x5) c.op = SUB_VXVY; 
        if (c.hx4 == 0x6) c.op = SHR_VXVY; 
        if (c.hx4 == 0x7) c.op = SUBN_VXVY; 
        if (c.hx4 == 0xE) c.op = SHL_VXVY; 
    }
    if (c.hx1 == 0x9 && c.hx4 == 0x0) c.op = SNE_VXVY; 
    if (c.hx1 == 0xA) c.op = LD_I;
    if (c.hx1 == 0xB) c.op = JP_V0;
    if (c.hx1 == 0xC) c.op = RND_VX;
    if (c.hx1 == 0xD) c.op = DRW_VXVY;
    if (c.hx1 == 0xE && c.hx3 == 0x9 && c.hx4 == 0xE) c.op = SKP_VX;
    if (c.hx1 == 0xE && c.hx3 == 0xA && c.hx4 == 0x1) c.op = SKNP_VX;
    if (c.hx1 == 0xF) {
        if (c.hx3 == 0x0 && c.hx4 == 0x7) c.op = LD_VXDT;
        if (c.hx3 == 0x0 && c.hx4 == 0xA) c.op = LD_VXK;
        if (c.hx3 == 0x1 && c.hx4 == 0x5) c.op = LD_DTVX;
        if (c.hx3 == 0x1 && c.hx4 == 0x8) c.op = LD_STVX;
        if (c.hx3 == 0x1 && c.hx4 == 0xE) c.op = ADD_IVX;
        if (c.hx3 == 0x2 && c.hx4 == 0x9) c.op = LD_FVX;
        if (c.hx3 == 0x3 && c.hx4 == 0x3) c.op = LD_BVX;
        if (c.hx3 == 0x5 && c.hx4 == 0x5) c.op = LD_IVX;
        if (c.hx3 == 0x6 && c.hx4 == 0x5) c.op = LD_VXI;
    }
    // Debug print
    printf("%04X\n", c.full);
    return c;
}

int step(Program* p) {
    printf("line: %u", p->PC); // Debug print
    byte b1 = p->ram[p->PC];
    byte b2 = p->ram[p->PC+1];
    Cmd c = parse(b1, b2); // Instruction at program counter
    byte* Vx = &p->registers[c.hx2];
    byte* Vy = &p->registers[c.hx3];
    byte* Vf = &p->registers[0xF];

    switch (c.op) {
        case NOP:
            return 0;
        case CLS: // TODO
            break;
        case RET:
           p->PC = p->stack[p->stack_top];
           p->stack_top -= 1;
           break;
        case JP:
           p->PC = c.full & 0x0FFF;
           break;
        case CALL:
           p->stack_top += 1;
           p->stack[p->stack_top] = p->PC;
           p->PC = c.full & 0x0FFF;
           break;
        case SE_VX:
           p->PC += (*Vx == (c.full & 0x00FF));
            break;
        case SNE_VX:
            p->PC += (*Vx != (c.full & 0x00FF));
            break;
        case SE_VXVY:
            p->PC += (*Vx == *Vy);
            break;
        case LD_VX:
            *Vx = c.full & 0x00FF;
            break;
        case ADD_VX:
            *Vx += c.full & 0x00FF;
            break;
        case LD_VXVY:
            *Vx = *Vy; 
            break;
        case OR_VXVY:
            *Vx |= *Vy;
            break;
        case AND_VXVY:
            *Vx &= *Vy;
            break;
        case XOR_VXVY:
            *Vx ^= *Vy;
            break;
        case ADD_VXVY:
            *Vx += *Vy;
            *Vf = (*Vx <= *Vy);
            break;
        case SUB_VXVY:
            *Vf = (*Vx > *Vy);
            *Vx -= *Vy;
            break;   
        case SHR_VXVY:
            *Vf = *Vx & 1;
            *Vx >>= 1;
            break;
        case SUBN_VXVY:
           *Vf = (*Vy > *Vx);
           *Vx = (*Vy - *Vx);
           break;
        case SHL_VXVY:
           *Vf = (*Vx & 128);
           *Vx <<= 1;
           break;
        case SNE_VXVY:
           p->PC += (*Vx != *Vy);
           break;
        case LD_I:
           p->I = (c.full &= 0x0FFF);
           break;
        case JP_V0:
           p->PC = (c.full &= 0x0FFF) + p->registers[0x0];
           break;
        case RND_VX:
            *Vx = (c.full & 0x00FF) & (rand() % 256);
            break;
        case DRW_VXVY: // TODO
            break;
        case SKP_VX: // TODO
            break;
        case SKNP_VX: // TODO
            break;
        case LD_VXDT:
            *Vx = p->dt;
            break;
        case LD_VXK: // TODO
            break;
        case LD_DTVX:
            p->dt = *Vx;
            break;
        case LD_STVX:
            p->st = *Vx;
            break;
        case ADD_IVX:
            p->I += *Vx;
            break;
        case LD_FVX: // TODO
            break;
        case LD_BVX:
            p->ram[p->I]   = *Vx / 100;
            p->ram[p->I+1] = (*Vx % 100) / 10;
            p->ram[p->I+2] = *Vx % 10;
            break;
        case LD_IVX:
            for (int i = 0; i < c.hx2; i++) {
                p->ram[p->I + i] = p->registers[i];
            } 
            break;
        case LD_VXI:
            for (int i = 0; i < c.hx2; i++) {
                p->registers[i] = p->ram[p->I + i];
            }
    }
    p->PC += 1;
    p->dt -= (p->dt > 0);
    p->st -= (p->st > 0);
    return 0;
}

