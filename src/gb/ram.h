#ifndef VBEMU_RAM_H
#define VBEMU_RAM_H
#include <stdint.h>

enum gb_licensee
{
    UNDEFINED, EA
};

struct gb_ram_t {
    uint8_t rom[2][0x4000];
    uint8_t video_ram[0x2000];
    uint8_t external_ram[0x2000];
    uint8_t working_ram[2][0x1000];
    uint8_t mirror_working_ram[0x1E00]; // Prohibited but here just for compatibilities’ sake.
    uint8_t sprite_table[0xA0];
    uint8_t io_registers[0x80];
    uint8_t high_ram [0x7F];
    uint8_t interrupt_enable;

    // Unnecessary but whatever
    enum gb_licensee licensee;
};


struct gb_ram_t ram;

void gb_load_rom(char *path)
{

}


#endif //VBEMU_RAM_H
