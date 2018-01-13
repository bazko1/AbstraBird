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

    SquareFilledPipe( int x , int y , int w , int h  , double speed ):
    SquareMovingObject(x , y , h , w , speed  , 0 ){};

    void render(SDL_Renderer *renderer) override {
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderFillRect( renderer , &this->getRect() );
    }


};




class SquareFilledTopPipe : public SquareFilledPipe {

public:

    void update(const double d) override {
        SquareMovingObject::Update(d);
    }


    SquareFilledTopPipe( int winH , int winW , int w , int h ,double speed ) :
            SquareFilledPipe( winW , 0 , w , h , speed) {}




};

class SquareFilledBotPipe : public SquareFilledPipe {

public:

    void update(const double d) override {
        SquareMovingObject::Update(d);
    }


    SquareFilledBotPipe( int winH , int winW , int w , int h , double speed ) :
            SquareFilledPipe( winW , winH - h , w , h , speed ) {}




};





#endif //ABSTRABIRD_PIPES_H
