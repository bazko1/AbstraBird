//
// Created by bazyli on 1/19/18.
//

#ifndef ABSTRABIRD_FLOOR_H
#define ABSTRABIRD_FLOOR_H

#include <SDL_system.h>
#include <SDL_image.h>
#include "SquareMovingObject.h"
#include <memory>
#include <list>

class Floor : public IUpdate {


public:

    int wH;
    int wW;

    std::list<  std::shared_ptr<SquareMovingObject>  > flrs;

    void update(const double d) override
    {

        SquareMovingObject* r;

        for (const std::shared_ptr<SquareMovingObject>& ptr : flrs  )
            ptr->update(d);

        if ( flrs.front()->getRectX() + flrs.front()->getRectW() <= 0 )
        {


            r = new SquareMovingObject( wW ,wH-flrs.front()->getRectH(), 75 , wW/2 ,
                                        flrs.front()->getXSpeed() , 0 );


            flrs.pop_front();


           flrs.push_back( std::shared_ptr<SquareMovingObject> ( r )  );

        }



    }

    Floor ( int windowW ,int windowH ) :  wH(windowH) , wW(windowW) {

        SquareMovingObject* r;

       for ( int i = 0 ; i<=windowW ; i+=windowW/2  )
       {

           r = new SquareMovingObject( i , windowH-75 , 75 , windowW/2 , -1.6 , 0 );

           flrs.push_back( std::shared_ptr<SquareMovingObject> ( r )  );

       }


    }




};

class FlappyFloor : public Floor , public IInitable , public IRenderable  {

    SDL_Surface* bitmapSurface = NULL ;

    SDL_Texture* texture = NULL;



public:

    FlappyFloor(int windowW, int windowH) : Floor( windowW ,  windowH )  {}

    void Init (SDL_Renderer * renderer) {

        IInitable::Init( renderer
                ,"//home/bazyli/CLionProjects/AbstraBird/Pictures/ground.png"
                ,bitmapSurface
                ,texture );

    }


    void render(SDL_Renderer* renderer){

        for(std::shared_ptr<SquareMovingObject>& r: this->flrs  )

            SDL_RenderCopyEx( renderer, texture, 0, &r->getRect(),  0, NULL, SDL_FLIP_NONE );


    }

};



#endif //ABSTRABIRD_FLOOR_H
