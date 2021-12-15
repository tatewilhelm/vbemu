#include "interp.h"
#include "cpu.h"

int start_chip8(struct Arguments args) {
    FILE* f = fopen(args.path, "rb");
    fseek(f, 0L, SEEK_END);
    int size = ftell(f);
    fseek(f, 0L, SEEK_SET);
    mem_wipe();
    byte* ptr = mem_ptr(0);
    fread(ptr, 1, size, f);
    for (int i = 0; i < size; i++) {
        parse(i*2);     
    }
    return 0;
}

