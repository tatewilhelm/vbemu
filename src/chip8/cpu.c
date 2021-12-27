#include "cpu.h"
#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint16_t full;
    byte hx1;
    byte hx2;
    byte hx3;
    byte hx4;
} Cmd;

Cmd parse(uint16_t ptr) {
    Cmd ret = {};
    // Combine both bytes of instruction to single variable
    ret.full = (mem_get(ptr) << 8) | mem_get(ptr+1);
    // Seperate instruction into 4 bit chunks to aid interpreting
    ret.hx1 = (ret.full & 0xF000) >> 12;
    ret.hx2 = (ret.full & 0x0F00) >> 8;
    ret.hx3 = (ret.full & 0x00F0) >> 4;
    ret.hx4 = (ret.full & 0x000F);
    return ret;
}

void interpret(uint16_t ptr) {
    Cmd c = parse(ptr);
    if (c.full == 0) return; // noop
    printf("%04X ", c.full);
    if (c.full == 0x00E0) printf("cls");
    if (c.full == 0x00EE) printf("ret");
    if (c.hx1 == 0x1) printf("jp addr");
    if (c.hx1 == 0x2) printf("call addr");
    if (c.hx1 == 0x3) printf("se vx byte");
    if (c.hx1 == 0x4) printf("sne vx byte");
    if (c.hx1 == 0x5) printf("se vx vy");
    if (c.hx1 == 0x6) printf("ld vx byte");
    if (c.hx1 == 0x7) printf("add vx byte");
    if (c.hx1 == 0x8) {
        if (c.hx4 == 0x0) printf("ld vx vy");
        if (c.hx4 == 0x1) printf("or vx vy");
        if (c.hx4 == 0x2) printf("and vx vy");
        if (c.hx4 == 0x3) printf("xor vx vy"); 
        if (c.hx4 == 0x4) printf("add vx vy");
        if (c.hx4 == 0x5) printf("sub vx vy");
        if (c.hx4 == 0x6) printf("shr vx vy");
        if (c.hx4 == 0x7) printf("subn vx vy");
        if (c.hx4 == 0xE) printf("shl vx vy"); 
    }
    if (c.hx1 == 0x9 && c.hx4 == 0x0) printf("sne vx vy");
    if (c.hx1 == 0xA) printf("ld I addr");
    if (c.hx1 == 0xB) printf("jp v0 addr");
    if (c.hx1 == 0xC) printf("rnd vx byte");
    if (c.hx1 == 0xD) printf("drw vx vy n");
    if (c.hx1 == 0xE && c.hx3 == 0x9 && c.hx4 == 0xE) printf("skp vx");
    if (c.hx1 == 0xE && c.hx3 == 0xA && c.hx4 == 0x1) printf("sknp vx");
    if (c.hx1 == 0xF) {
        if (c.hx3 == 0x0 && c.hx4 == 0x7) printf("ld vx dt");
        if (c.hx3 == 0x0 && c.hx4 == 0xA) printf("ld vx k");
        if (c.hx3 == 0x1 && c.hx4 == 0x5) printf("ld dt vx");
        if (c.hx3 == 0x1 && c.hx4 == 0x8) printf("ld st vx");
        if (c.hx3 == 0x1 && c.hx4 == 0xE) printf("add i vx");
        if (c.hx3 == 0x2 && c.hx4 == 0x9) printf("ld f vx");
        if (c.hx3 == 0x3 && c.hx4 == 0x3) printf("ld b vx");
        if (c.hx3 == 0x5 && c.hx4 == 0x5) printf("ld i vx");
        if (c.hx3 == 0x6 && c.hx4 == 0x5) printf("ld vx i");
    }
    printf("\n");
}
