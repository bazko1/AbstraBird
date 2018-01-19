//
// Created by bazyli on 1/14/18.
//

#ifndef ABSTRABIRD_IINITABLE_H
#define ABSTRABIRD_IINITABLE_H

#include <SDL_system.h>
#include <SDL_image.h>
#include "string"

class IInitable {

public:

    virtual void Init( SDL_Renderer* )=0;

    virtual void Init ( SDL_Renderer* renderer , const char* filePath , SDL_Surface* bitmapSurface , SDL_Texture*& texture ){

        bitmapSurface = IMG_Load(filePath);

        texture = SDL_CreateTextureFromSurface( renderer , bitmapSurface  );

        SDL_FreeSurface( bitmapSurface );


    }


};


#endif //ABSTRABIRD_IINITABLE_H
