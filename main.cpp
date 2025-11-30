// #include <SDL2/SDL.h>
#include <SDL3/SDL.h>
#include <iostream>
#include "Solver.h"
#include "World.h"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

void printSet(const Set &set) {
    std::cout << set.card1.color << " " << set.card1.shape << " " << set.card1.shading << " " << set.card1.number << " | ";
    std::cout << set.card2.color << " " << set.card2.shape << " " << set.card2.shading << " " << set.card2.number << " | ";
    std::cout << set.card3.color << " " << set.card3.shape << " " << set.card3.shading << " " << set.card3.number;
    std::cout << std::endl;
}
int main(int, char **) {
    World world = world.randomWorld();
    world.printWorld();

    Solver solver = Solver();
    std::cout << "Solving..." << std::endl;
    std::vector<Set> sets = solver.solve(world.getCards());
    std::cout << "Solved!" << std::endl;

    for (const Set &set : sets) {
        printSet(set);
    }

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }
    int width = 800, height = 600;
    SDL_Window *window = SDL_CreateWindow("Set Solver", width, height, SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        SDL_Log("Could not create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Event event;
    SDL_RenderClear(renderer);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
// // SDL_Quit();
// return 0;
// }

// SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){
//     // Initialize SDL
//     if (!SDL_Init(SDL_INIT_VIDEO)) {
//         SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
//         return SDL_APP_FAILURE;
//     }

//     if (!SDL_CreateWindowAndRenderer("SetSolver",800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
//         SDL_Log("Unable to create window and renderer: %s", SDL_GetError());
//         return SDL_APP_FAILURE;
//     }

//     SDL_SetRenderLogicalPresentation(renderer, 800, 600, SDL_LOGICAL_PRESENTATION_LETTERBOX);
//     return SDL_APP_CONTINUE;
// }

// SDL_AppResult SDL_AppIterate(void *appstate){
//     SDL_FRect rect;
//     std::cout << "loop" << std::endl;
//     //set background color?
//     SDL_SetRenderDrawColor(renderer, 230, 34, 114, SDL_ALPHA_OPAQUE);

//     //clear screen
//     SDL_RenderClear(renderer);

//     rect.x = 50;
//     rect.y = 50;
//     rect.w = 200;
//     rect.h = 150;

//     SDL_RenderRect(renderer, &rect);

//     //put it on the screen
//     SDL_RenderPresent(renderer);

//     return SDL_APP_CONTINUE;
// }

// void SDL_AppQuit(void *appstate, SDL_AppResult result){

// }
