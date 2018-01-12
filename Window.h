//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_WINDOW_H
#define ABSTRABIRD_WINDOW_H


#include <SDL_video.h>
#include <SDL.h>

class Window {

private:


      SDL_Window* sdl_window = NULL;
      SDL_Renderer *renderer = NULL;

public:

    static const int Height = 2*384;

    static const int Width = 2*288;




    Window ();

    void Update();




};


#endif //ABSTRABIRD_WINDOW_H
