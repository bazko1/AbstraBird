//
// Created by bazyli on 1/11/18.
//

#ifndef ABSTRABIRD_RECTBIRD_H
#define ABSTRABIRD_RECTBIRD_H


#include "SquareMovingObject.h"
#include "Bird.h"

class RectFillBird : public Bird {

private:


public:
    void update(const double d) override {

       // Bird::update(d);

    }

    RectFillBird( int x , int y , int h , int w, double xSpd , double ySpd)   :
            Bird( x ,y , h , w , xSpd , ySpd) {}


    RectFillBird() : RectFillBird ( 0 , 0 , 40 , 40 , 0 , 0.0 ) {}


    void render(SDL_Renderer* renderer) override {

        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderFillRect( renderer , &this->getRect() );

    };


};

class RectBird : public Bird {

public:

    RectBird( int x , int y , int h , int w, int xSpd , int ySpd)   :
            Bird( x ,y , h , w,xSpd , ySpd) {}

private:

    void render(SDL_Renderer* renderer) override {

        SDL_RenderDrawRect( renderer , &this->getRect() );

    };


};





#endif //ABSTRABIRD_RECTBIRD_H
