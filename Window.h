//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_WINDOW_H
#define ABSTRABIRD_WINDOW_H


#include <SDL_video.h>
#include <SDL.h>
#include "IRenderable.h"

const static int Height = 2*384;
const static int Width = 2*288;

class Window : public IRenderable {

private:



    SDL_Window* sdl_window = NULL;

public:

    virtual void Init(SDL_Renderer*) = 0;

    SDL_Window *getSdl_window() const;

    const int Height = 2*384;

    const int Width = 2*288;

    Window ();

    virtual ~Window();


};


#endif //ABSTRABIRD_WINDOW_H
