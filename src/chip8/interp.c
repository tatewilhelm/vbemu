#include "interp.h"
#include "cpu.h"

int start_chip8(struct Arguments args) {
    // Find file size
    FILE* f = fopen(args.path, "rb");
    fseek(f, 0L, SEEK_END);
    int size = ftell(f);
    fseek(f, 0L, SEEK_SET);
    // Read into ram
    mem_wipe();
    byte* ptr = mem_ptr(0);
    fread(ptr, 1, size, f);
    // Parse
    for (int i = 0; i < size; i++) {
        interpret(i*2);     
    }
    return 0;
}

