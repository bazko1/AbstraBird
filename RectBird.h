//
// Created by bazyli on 1/11/18.
//

#ifndef ABSTRABIRD_RECTBIRD_H
#define ABSTRABIRD_RECTBIRD_H


#include "SquareMovingObject.h"

class RectFillBird : SquareMovingObject {

public:

    RectFillBird( int x , int y , int h , int w, int xSpd , int ySpd)   :
            SquareMovingObject( x ,y , h , w,xSpd , ySpd) {}

private:
    void Render(SDL_Renderer* renderer) override {

        SDL_RenderFillRect( renderer , &this->getRect() );

    };


};

class RectBird : SquareMovingObject {

public:

    RectBird( int x , int y , int h , int w, int xSpd , int ySpd)   :
            SquareMovingObject( x ,y , h , w,xSpd , ySpd) {}

private:

    void Render(SDL_Renderer* renderer) override {

        SDL_RenderDrawRect( renderer , &this->getRect() );

    };


};





#endif //ABSTRABIRD_RECTBIRD_H
