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

        Rect() : Rect(0,0,0,0){};

    };

    struct Color {

        Uint8 r,g,b,a;
        Color(Uint8 r ,Uint8 g , Uint8 b , Uint8 a ) : r(r),g(g),b(b),a(a){};

    };

    int SetRenderDrawColor(SDL_Renderer* renderer , SDL::Color& c){
        
        //SDL_Log ("Setting color %i %i %i %i" ,  c.r, c.g, c.b, c.a  );  
        return SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    }

    int SetTextureColorMod(SDL_Texture* texture , SDL::Color& c) {
        SDL_SetTextureColorMod(texture, c.r, c.g, c.b);
        SDL_SetTextureAlphaMod(texture,c.a);
    }

    void renderTexture( SDL::Rect dstRect , SDL_Texture* texture , SDL_Renderer* renderer ){
    
        int w,h;
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);

        SDL_Rect CopyRect = {0,0,w,h};  
        SDL_RenderCopy( renderer , texture , &CopyRect , &dstRect );
      
    }

}