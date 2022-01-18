#include "interp.h"
#include "cpu.h"
#include "SDL2/SDL.h"
#include "ram.h"
#include <SDL2/SDL_keycode.h>

static SDL_Window* window = NULL;
static SDL_Surface* screen = NULL;
static Program* program = NULL;

static const int WIDTH = 512;
static const int HEIGHT = 256;
static const int P_WIDTH = WIDTH / CH8_SCREEN_WIDTH;
static const int P_HEIGHT = HEIGHT / CH8_SCREEN_HEIGHT;

static int init_window() {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL init error: %s\n", SDL_GetError());
        return 1;
    }
    int centered = SDL_WINDOWPOS_CENTERED; 
    window = SDL_CreateWindow(
            "Chip-8 Interpreter", 
            centered, centered, WIDTH, HEIGHT,
            SDL_WINDOW_SHOWN // | SDL_WINDOW_RESIZABLE
            );
    if (window == NULL) {
        printf("Windowing error: %s", SDL_GetError());
        return 1;
    }
    screen = SDL_GetWindowSurface(window);
    return 0;
}

static void destroy_window() {
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
}

static void draw_window() {
    Uint32 black = SDL_MapRGB(screen->format, 0, 0, 0);
    Uint32 white = SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF);
    SDL_FillRect(screen, NULL, black);
    SDL_Rect pixel = {0, 0, P_WIDTH, P_HEIGHT};
    for (int y = 0; y < CH8_SCREEN_HEIGHT; y++) {
        for (int x = 0; x < CH8_SCREEN_WIDTH; x++) {
            pixel.x = x * P_WIDTH;
            pixel.y = y * P_HEIGHT;
            if (1 & program->vram[y] << x)
                SDL_FillRect(screen, &pixel, white);
        }
    }
    SDL_UpdateWindowSurface(window);
}

static int poll_events() {
    static SDL_Event e;
    while(SDL_PollEvent(&e) != 0) {
        switch(e.type) {
            case SDL_QUIT:
                return 1;
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_ESCAPE)
                    return 1;
        }
    }
    return 0;
}

static int load_cart(const char* path) {
    // Open cart
    FILE* f = fopen(path, "rb");
    if (f == NULL) {
        printf("Could not find cart at %s\n", path);
        return 1;
    }
    
    // Get size
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    rewind(f);
    if (size > 3584) {
        printf("Cart is too large\n");
        return 1;
    }

    // Read into ram
    program = create_program();  
    byte* temp = program->ram + CH8_START_INDEX;
    fread(temp, 1, size, f);
    fclose(f);
    return 0;
}

int start_chip8(struct Arguments args) {
    // Run
    if (init_window()) return 1;
    if (load_cart(args.path)) return 1;
    int exit = 0;
    while (!exit) {
        exit &= poll_events();
        exit &= step(program);  
        draw_window();
    }
    destroy_window();
    return 0;
}

