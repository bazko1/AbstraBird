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

    int winWidth;
    int winHeight;

public:

    Obstacle( int WinWidth , int WinHeight , int Height , int Width )  : winHeight(WinHeight) , winWidth(WinWidth) {


        // Poczatkowe ustawienie x
        top.setRectX( WinWidth );
        bot.setRectX( WinWidth );

        // Wysokosc obiektow
        top.setRectH(Height);
        bot.setRectH(Height);

        // Szeroosc obiektow
        top.setRectW(Width);
        bot.setRectW(Width);

        // Poczatkowe Ustawienie gornego
        top.setRectY ( WinHeight - top.getRect().h );

        // Y - do metody Update - musi
        top.setY ( WinHeight-top.getRect().h );

        // X - do metody update
        top.setX( WinWidth );
        bot.setX( WinWidth );

        // speed x // should be in arguments
        top.setXSpeed(-0.4);
        bot.setXSpeed(-0.4);

        // y speed =  0

    }



    void Update( const double deltaTime )  {

        top.Update(deltaTime);
        bot.Update(deltaTime);

        if ( top.getX() + top.getRect().h < 0)
            top.setX ( winWidth  );

        if ( bot.getX() + bot.getRect().h < 0)
            bot.setX ( winWidth  );


    }

    void Render ( SDL_Renderer* renderer){

        top.Render(renderer);
        bot.Render(renderer);
    }

    T getTop() const {
        return top;
    }

    B getBot() const {
        return bot;
    }



};






#endif //ABSTRABIRD_OBSTACLE_H
