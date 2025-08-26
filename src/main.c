#include <stdio.h>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = SCREEN_WIDTH * 9 / 16;

void draw_player(SDL_Renderer *renderer, SDL_Texture *texture) {
    float width, height;
    SDL_GetTextureSize(texture, &width, &height);

    SDL_FRect rect = {0.0f, 0.0f, width, height};

    SDL_RenderTextureRotated(renderer, texture, NULL, &rect, 90.0, NULL,
                             SDL_FLIP_NONE);
}

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window =
        SDL_CreateWindow("C++ Game", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    SDL_Texture *background =
        IMG_LoadTexture(renderer, "assets/background.png");
    SDL_SetTextureScaleMode(background, SDL_SCALEMODE_NEAREST);

    SDL_Texture *player_texture = IMG_LoadTexture(renderer, "assets/ship.png");
    if (player_texture == NULL) {
        SDL_DestroyTexture(background);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);

    bool window_should_close = false;
    while (!window_should_close) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                window_should_close = true;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, background, NULL, NULL);
        draw_player(renderer, player_texture);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(player_texture);
    SDL_DestroyTexture(background);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
