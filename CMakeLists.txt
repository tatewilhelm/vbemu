cmake_minimum_required(VERSION 3.11)
project(vbemu C)
set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(vbemu
        src/main.c src/main.h src/arguments.c src/arguments.h

        # Game Boy
        src/gb/gameboy.c src/gb/gameboy.h src/gb/cpu/cpu.c src/gb/cpu/cpu.h src/gb/clock/clock.c src/gb/clock/clock.h src/gb/window/window.h src/gb/window/window.c src/gb/gfx/gfx.c src/gb/gfx/gfx.h)
target_link_libraries(vbemu ${SDL2_LIBRARIES})

