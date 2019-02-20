//
// Created by bazyli on 1/14/18.
//

#ifndef ABSTRABIRD_WINDOWS_H
#define ABSTRABIRD_WINDOWS_H


#include <SDL_image.h>
#include "Window.h"
#include "IInitable.h"
#include "dirmanager.h"
class ColoredWindow : public Window{

public:
    void render(SDL_Renderer *renderer) override {

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);

    }

};

class FlappyWindow : public Window {

private:

    SDL_Surface* bitmapSurface = NULL ;

    SDL_Texture* texture = NULL;


public:

    FlappyWindow(){}

    void Init(SDL_Renderer *renderer) override {

        IInitable::Init( renderer
                ,DirManager::getDir("bg.png").c_str()
                ,bitmapSurface
                ,texture );

    }

    void render(SDL_Renderer *renderer) override {


        SDL_RenderCopy(renderer, texture, NULL, NULL);

    }






};

class GuiWindow : public Window {
    public:
    
    SDL_Surface* bitmapSurface = NULL ;

    SDL_Texture* texture = NULL;

    GuiWindow(SDL_Window* window) {
        this->Window::sdl_window = window;
        this->sdl_window = window;
    }

       void Init(SDL_Renderer *renderer) override {

        IInitable::Init( renderer
                ,DirManager::getDir("bg.png").c_str()
                ,bitmapSurface
                ,texture );

    }

    void render(SDL_Renderer *renderer) override {


        SDL_RenderCopy(renderer, texture, NULL, NULL);

    }


};



#endif //ABSTRABIRD_WINDOWS_H
