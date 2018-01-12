//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_WINDOW_H
#define ABSTRABIRD_WINDOW_H


#include <SDL_video.h>
#include <SDL.h>

const static int Height = 2*384;
const static int Width = 2*288;

class Window {

private:



        SDL_Window* sdl_window = NULL;

public:

    SDL_Window *getSdl_window() const;
    const int Height = 2*384;

    const int Width = 2*288;

    Window ();




};


#endif //ABSTRABIRD_WINDOW_H
