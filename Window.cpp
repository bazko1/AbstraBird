//
// Created by bazyli on 1/6/18.
//

#include <SDL.h>
#include "Window.h"

Window::Window() {

    SDL_Init(SDL_INIT_EVERYTHING);

   // this->sdl_window = SDL_CreateWindow("Abstra Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->Width, this->Height, 0);

 //   this->renderer = SDL_CreateRenderer(sdl_window,-1,SDL_RENDERER_ACCELERATED);

}

void Window::Update() {

    SDL_RenderPresent(renderer);

    SDL_RenderClear(renderer);

}
