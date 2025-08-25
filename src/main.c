#include <stdio.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("C++ Game", 1920, 1080, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    IMG_LoadTexture();

    bool window_should_close = false;
    while (!window_should_close) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                window_should_close = true;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
