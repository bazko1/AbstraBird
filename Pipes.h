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

    void Init(SDL_Renderer* r) {};

};




class SquareFilledTopPipe : public SquareFilledPipe {

public:

    void update(const double d) override {
        SquareMovingObject::update(d);
    }


    SquareFilledTopPipe( int winH , int winW , int w , int h ,double speed ) :
            SquareFilledPipe( winW , 0 , w , h , speed) {}




};

class SquareFilledBotPipe : public SquareFilledPipe {

public:

    void update(const double d) override {
        SquareMovingObject::update(d);
    }


    SquareFilledBotPipe( int winH , int winW , int w , int h , double speed ) :
            SquareFilledPipe( winW , winH - h , w , h , speed ) {}




};


class FlappyTopPipe : public SquareFilledPipe{

private:

    SDL_Surface* bitmapSurface = NULL ;

    SDL_Texture* texture = NULL;


public:

    FlappyTopPipe( int winH , int winW , int w , int h ,double speed ) :
            SquareFilledPipe( winW , 0 , w , h , speed) {}

    void Init (SDL_Renderer * renderer) {


            IInitable::Init( renderer
                ,"//home/bazyli/CLionProjects/AbstraBird/Pictures/tube1.png"
                ,bitmapSurface
                ,texture );

    }



    void render(SDL_Renderer *renderer) override {


        SDL_RenderCopyEx( renderer, texture, 0, &this->getRect(),  0, NULL, SDL_FLIP_NONE );

    }

};



class FlappyBotPipe : public SquareFilledPipe{

private:

    SDL_Surface* bitmapSurface = NULL ;

    SDL_Texture* texture = NULL;


public:

    FlappyBotPipe( int winH , int winW , int w , int h ,double speed ) :
            SquareFilledPipe( winW , winH - h , w , h , speed ) {}

    void Init (SDL_Renderer * renderer) {


        IInitable::Init( renderer
                ,"//home/bazyli/CLionProjects/AbstraBird/Pictures/tube2.png"
                ,bitmapSurface
                ,texture );

    }



    void render(SDL_Renderer *renderer) override {


        SDL_RenderCopyEx( renderer, texture, 0, &this->getRect(),  0, NULL, SDL_FLIP_NONE );

    }

};





#endif //ABSTRABIRD_PIPES_H
