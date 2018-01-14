//
// Created by bazyli on 1/14/18.
//

#ifndef ABSTRABIRD_FLAPPYBIRD_H
#define ABSTRABIRD_FLAPPYBIRD_H

#include <SDL_image.h>
#include "Bird.h"
#include "RectBird.h"

class AbstraBird : public RectFillBird {


    SDL_Surface* bitmapSurface = NULL ;

    SDL_Texture* texture = NULL;


public:



    AbstraBird(int windowH , int size ) : RectFillBird( 20 , windowH/2 , size , size , 0.0 , 0.0 ) {}


    void Init (SDL_Renderer * renderer) {

        bitmapSurface = IMG_Load("//home/bazyli/CLionProjects/AbstraBird/Pictures/bird_sing.png");

        texture = SDL_CreateTextureFromSurface( renderer , bitmapSurface  );

        SDL_FreeSurface( bitmapSurface );




    }



    void render(SDL_Renderer *renderer) override {


        if (this->getYSpeed() < 0)
            SDL_RenderCopyEx(renderer, texture, 0, &this->getRect(), 300, NULL, SDL_FLIP_NONE);
        else if (this->getYSpeed() > 0.8  )
            SDL_RenderCopyEx(renderer, texture, 0, &this->getRect(), 30, NULL, SDL_FLIP_NONE);
        else
            SDL_RenderCopyEx(renderer, texture, 0, &this->getRect(), 0, NULL, SDL_FLIP_NONE);
    }


};







#endif //ABSTRABIRD_FLAPPYBIRD_H
