//
// Created by bazyli on 1/12/18.
//

#include "Obstacle.h"


Obstacle::Obstacle(int WinWidth, int WinHeight, SquareMovingObject& Top, SquareMovingObject& Bot) : top( Top ) , bot( Bot ) , winWidth(WinWidth) , winHeight(WinHeight) {

    // Poczatkowe ustawienie x
    top.setRectX( WinWidth );
    bot.setRectX( WinWidth );

    // Wysokosc obiektow
    top.setRectH(winHeight);
    bot.setRectH(winHeight);

    // Szeroosc obiektow
    top.setRectW(winWidth);
    bot.setRectW(winWidth);

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


void Obstacle::render(SDL_Renderer *renderer) {
    top.render(renderer);
    bot.render(renderer);

}

void Obstacle::update(const double d) {

    top.Update(d);
    bot.Update(d);

    if ( top.getX() + top.getRect().h < 0)
        top.setX ( winWidth  );

    if ( bot.getX() + bot.getRect().h < 0)
        bot.setX ( winWidth  );

}

SquareMovingObject &Obstacle::getTop() const {
    return top;
}

SquareMovingObject &Obstacle::getBot() const {
    return bot;
}
