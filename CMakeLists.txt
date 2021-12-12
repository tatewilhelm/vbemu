cmake_minimum_required(VERSION 3.00)
project(vbemu C)

set(CMAKE_C_STANDARD 99)

add_executable(vbemu src/main.c src/main.h src/gb/handler.c src/gb/handler.h src/gb/cpu.c src/gb/cpu.h)
target_link_libraries(vbemu sdl2)