#pragma once
#include "memory.h"

void parse(uint16_t ptr);

void CH8_CLS();
void CH8_RET();
void CH8_JP_addr();
void CH8_CALL_addr();
void CH8_SE_Vx();
void CH8_SNE_Vx();
void CH8_SE_VxVy();
void CH8_LD_Vx();
void CH8_ADD_Vx();
void CH8_LD_VxVy();
void CH8_OR_VxVy();
void CH8_AND_VxVy();
void CH8_XOR_VxVy();
void CH8_ADD_VxVy();
void CH8_SUB_VxVy();
void CH8_SHR_Vx();
void CH8_SUBN_VxVy();
void CH8_SHL_Vx();
void CH8_SNE_VxVy();
void CH8_LD_I();
void CH8_JP_V0();
void CH8_RND_Vx();
void CH8_DRW_VxVyN();
void CH8_SKP_Vx();
void CH8_SKNP_Vx();
void CH8_LD_VxDt();
void CH8_LD_VxK();
void CH8_LD_DtVx();
