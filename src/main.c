#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

void exit_error(const char *msg);

int main(int argc, char **argv) {
    
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Init SDL
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        exit_error("Failure to init SDL");
    }

    // Create window
    window = SDL_CreateWindow("Game_Jam", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    if (window == NULL) {
        exit_error("Failure to create window");
        SDL_Quit();
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL) {
        exit_error("Failure to create renderer");
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    SDL_Delay(3000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void exit_error(const char *msg) {

    SDL_Log("ERROR: %s > %s", msg, SDL_GetError());
    exit(EXIT_FAILURE);
}
