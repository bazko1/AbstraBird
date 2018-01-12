//
// Created by bazyli on 1/12/18.
//

#ifndef ABSTRABIRD_PIPES_H
#define ABSTRABIRD_PIPES_H

#include "SquareMovingObject.h"

class SquareFilledPipe : public SquareMovingObject {

public:
    SquareFilledPipe() : SquareMovingObject(0,0,0,0,0,0) {

    }

    void Render(SDL_Renderer *renderer) override {
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderFillRect( renderer , &this->getRect() );
    }

};



#endif //ABSTRABIRD_PIPES_H
