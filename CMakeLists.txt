cmake_minimum_required(VERSION 3.11)
project(vbemu C)
set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(vbemu
        src/main.c src/main.h src/arguments.c src/arguments.h src/verbose.c src/verbose.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(vbemu PRIVATE Threads::Threads)