#pragma once 

#include <SDL.h>


namespace SDL {
    
    struct Rect : SDL_Rect {


        Rect(int x , int y , int w , int h) {
            this->x=x;
            this->y=y;
            this->w=w;
            this->h=h;
        };


        Rect (const Rect& r ) : Rect(r.x,r.y,r.w,r.h){};


    };

}