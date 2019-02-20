#include "GWindow.h"

GWindow::GWindow() {


    this->sdl_window = SDL_CreateWindow("guiDemo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->Width, this->Height, 0);

    this->renderer = SDL_CreateRenderer( this->sdl_window , -1 , 0 );
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);

}


SDL_Window* GWindow::getSdl_window() {
    return sdl_window;
}

GWindow::~GWindow() {

    SDL_DestroyWindow(this->sdl_window);

}

SDL_Renderer* GWindow::getRenderer(){
    return this->renderer;
}

 void GWindow::Notify() {

     Subject::Notify();
     SDL_RenderPresent(  this->renderer );
 }

 void update(){


     
 }