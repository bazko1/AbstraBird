//
// Created by bazyli on 1/12/18.
//

#ifndef ABSTRABIRD_PIPES_H
#define ABSTRABIRD_PIPES_H


#include "IRenderable.h"
#include "IUpdate.h"
#include "SquareMovingObject.h"

class SquareFilledPipe : public SquareMovingObject {

public:

    void update(const double d) override {

    }

    SquareFilledPipe() : SquareMovingObject(0,0,0,0,0,0) {

    }


    void render(SDL_Renderer *renderer) override {
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderFillRect( renderer , &this->getRect() );
    }

};



#endif //ABSTRABIRD_PIPES_H
