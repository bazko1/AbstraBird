//
// Created by bazyli on 1/6/18.
//

#include <iostream>
#include "GameLogic.h"

bool GameLogic::score(const Bird &b, Obstacle &obstacle) const {


    int x = obstacle.getX() + obstacle.getW(); // Obstacle.getX + obstacle.getW

    int y1 = 0;

    int y2 = wH;


   if(  !obstacle.isVisited() &&  SDL_IntersectRectAndLine( &b.getRect() ,  &x , &y1 , &x , &y2  )  )
   {
       obstacle.setVisited( true );
       return true;
   }


    return false;

}



