cmake_minimum_required(VERSION 3.11)
project(vbemu C)
set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(vbemu
        src/main.c src/main.h src/arguments.c src/arguments.h
        # Game Boy
        src/gb/gameboy.c src/gb/gameboy.h src/gb/cpu/cpu.c src/gb/cpu/cpu.h
        src/gb/ram/ram.c src/gb/ram/ram.h src/gb/rom/cartridge.c src/gb/rom/cartridge.h)


