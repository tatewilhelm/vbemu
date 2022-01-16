#include "memory.h"

typedef enum {
    NOP, CLS, RET, JP, CALL, SE_VX, SNE_VX,
    SE_VXVY, LD_VX, ADD_VX, LD_VXVY, OR_VXVY,
    AND_VXVY, XOR_VXVY, ADD_VXVY, SUB_VXVY,
    SHR_VXVY, SUBN_VXVY, SHL_VXVY, SNE_VXVY, LD_I,
    JP_V0, RND_VX, DRW_VXVY, SKP_VX,
    SKNP_VX, LD_VXDT, LD_VXK, LD_DTVX,
    LD_STVX, ADD_IVX, LD_FVX, LD_BVX,
    LD_IVX, LD_VXI 
} CH8_OP; 

typedef struct {
    uint16_t full;
    byte hx1;
    byte hx2;
    byte hx3;
    byte hx4;
    CH8_OP op;
} Cmd;

int step(Program* p);
