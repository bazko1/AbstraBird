#pragma once

#include <SDL_video.h>
#include <SDL.h>
#include "controller.h"
#include "observer.h"

class GWindow : public Subject {

private:

    SDL_Window* sdl_window = NULL;
    SDL_Renderer* renderer;
    const int Height = 2*384;
    const int Width = 2*288;
    bool finished = false;

public:

    virtual void Init(SDL_Renderer*){};

    SDL_Window *getSdl_window() ;

    int getHeight()const{ return Height; };

    GWindow ();

    virtual ~GWindow();
    
    SDL_Renderer* getRenderer();

    void Notify() override;
    
    void update();
    void setFinished(bool f){ finished = true; }
    bool gFinished () const {return finished;}
};


