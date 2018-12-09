//
// Created by bazyli on 1/14/18.
//

#ifndef ABSTRABIRD_FLAPPYBIRD_H
#define ABSTRABIRD_FLAPPYBIRD_H

#include <SDL_image.h>
#include "Bird.h"
#include "RectBird.h"
#include "dirmanager.h"
class AbstraBird : public RectFillBird {


    SDL_Surface* bitmapSurface = NULL ;

    SDL_Texture* texture = NULL;

    int animCounter = 0;

    int currAnim = 0;
public:



    AbstraBird(int windowH , int size ) : RectFillBird( 20 , windowH/2 , size , size , 0.0 , 0.0 ) {}


    void Init (SDL_Renderer * renderer) {

        IInitable::Init( renderer
                ,DirManager::getDir("bird.png").c_str()
                ,bitmapSurface
                ,texture );

    }



    void render(SDL_Renderer *renderer) override {


        SDL_Rect srcRect = { 36* currAnim,0,36,26 };


        if (this->getYSpeed() < -0.1)
            SDL_RenderCopyEx(renderer, texture, &srcRect, &this->getRect(), 300, NULL, SDL_FLIP_NONE);
        else if (this->getYSpeed() > 0.8  )
            SDL_RenderCopyEx(renderer, texture, &srcRect, &this->getRect(), 30, NULL, SDL_FLIP_NONE);
        else
            SDL_RenderCopyEx(renderer, texture, &srcRect, &this->getRect(), 0, NULL, SDL_FLIP_NONE);

        if ( animCounter++==80 ) {

            currAnim++;
            currAnim %= 3;
            animCounter=0;
        }

    }


};







#endif //ABSTRABIRD_FLAPPYBIRD_H
