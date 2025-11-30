#pragma once
#include <SDL3/SDL.h>

class Window {
public:
    Window() {
        SDL_CreateWindow(
            "Hello Window",
            800, 300,
            SDL_WINDOW_RESIZABLE);
    }
};