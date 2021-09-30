#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void exit_error(const char *msg);

int main(int argc, char **argv) {
    
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Init SDL
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        exit_error("Failure to init SDL");
    }

    // Create window
    window = SDL_CreateWindow("Game_Jam", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (window == NULL) {
        exit_error("Failure to create window");
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        exit_error("Failure to create renderer");
    }

    const Uint32 startMs = SDL_GetTicks();
    while( SDL_GetTicks() - startMs < 3000 )
    {
        SDL_PumpEvents();

        //Set render ccolor
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

        //Clear screen
        SDL_RenderClear(renderer);

        //Show all the has been done behind the scenes
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void exit_error(const char *msg) {

    SDL_Log("ERROR: %s > %s", msg, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
