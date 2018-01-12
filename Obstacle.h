//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_OBSTACLE_H
#define ABSTRABIRD_OBSTACLE_H


#include "Pipe.h"
#include "IUpdate.h"
#include "SquareMovingObject.h"

template <typename T , typename B >
class Obstacle {

    T top;
    B bot;


public:

    Obstacle( int WinWidth , int WinHeight , int Height , int Width )  {


        // Poczatkowe ustawienie x
        top.SetRectX( WinWidth );
        bot.SetRectX( WinWidth );

        // Wysokosc obiektow
        top.SetRectH(Height);
        bot.SetRectH(Height);

        // Szeroosc obiektow
        top.SetRectW(Width);
        bot.SetRectW(Width);

        // Poczatkowe Ustawienie gornego
        top.SetRectY ( WinHeight - top.getRect().h );

        // Y - do metody Update - musi
        top.setY ( WinHeight-top.getRect().h );

        // X - do metody update
        top.setX( WinWidth );
        bot.setX( WinWidth );

        // speed x
        top.setXSpeed(-0.1);
        bot.setXSpeed(-0.1);

        // y speed =  0

    }



    void Update( const double deltaTime )  {

        top.Update(deltaTime);
        bot.Update(deltaTime);

    }

    void Render ( SDL_Renderer* renderer){

        top.Render(renderer);
        bot.Render(renderer);
    }


};






#endif //ABSTRABIRD_OBSTACLE_H
