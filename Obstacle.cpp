//
// Created by bazyli on 1/12/18.
//


#include "Obstacle.h"


Obstacle::Obstacle(int WinWidth, int WinHeight, SquareMovingObject& Top, SquareMovingObject& Bot) :
        top( Top ) , bot( Bot ) , winWidth(WinWidth) {

    // Poczatkowe ustawienie x
    top.setRectX( WinWidth );
    bot.setRectX( WinWidth );

    // Wysokosc obiektow
    top.setRectH(40);
    bot.setRectH(40);

    // Szeroosc obiektow
    top.setRectW(40);
    bot.setRectW(40);

    // Poczatkowe Ustawienie gornego
    top.setRectY ( WinHeight - top.getRect().h );

    // Y - do metody Update - musi
    top.setY ( WinHeight-top.getRect().h );


    // X - do metody update
    top.setX( WinWidth );
    bot.setX( WinWidth );

    // speed x // should be in arguments
    top.setXSpeed(-0.1);
    bot.setXSpeed(-0.1);

    // y speed =  0


}


void Obstacle::render(SDL_Renderer *renderer) {
    top.render(renderer);
    bot.render(renderer);

}

void Obstacle::update(const double d) {

    top.Update(d);
    bot.Update(d);

    if ( top.getX() + top.getRect().w < 0)
        top.setX(winWidth);


    if ( bot.getX() + bot.getRect().w < 0) {
        bot.setX(winWidth);
        visited = false;

    }



}

SquareMovingObject &Obstacle::getTop() const {
    return top;
}

SquareMovingObject &Obstacle::getBot() const {
    return bot;
}

Obstacle::Obstacle(SquareMovingObject &Top, SquareMovingObject &Bot , int WinWidth )
: top(Top) , bot(Bot) , winWidth(WinWidth) {}

bool Obstacle::isVisited() const {
    return visited;
}

void Obstacle::setVisited(bool visited) {
    Obstacle::visited = visited;
}
