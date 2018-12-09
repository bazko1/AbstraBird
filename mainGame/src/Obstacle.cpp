//
// Created by bazyli on 1/12/18.
//


#include "Obstacle.h"





void Obstacle::render(SDL_Renderer *renderer) {
    top->render(renderer);
    bot->render(renderer);

}

void Obstacle::update(const double d) {

    top->update(d);
    bot->update(d);

    if ( top->getX() + top->getRect().w < 0) {

        top->setX(winWidth);
        top->setRectH( winHeight/2 -  rng->getRandom()
        );
    }


    if ( bot->getX() + bot->getRect().w < 0) {

        bot->setX(winWidth);

        int randY = winHeight/2 + rng->getRandom();
        bot->setY( randY );
        bot->setRectH( randY );

        visited = false; // for counting points

    }



}



Obstacle::Obstacle(SquareMovingObject *Top, SquareMovingObject *Bot , int WinWidth , int winHeight )
: top(  Top  ) , bot( Bot ) ,
winWidth(WinWidth) , winHeight(winHeight)
{

 rng = std::make_shared<RNG<int,std::vector>>(50,60,1);
}

bool Obstacle::isVisited() const {
    return visited;
}

void Obstacle::setVisited(bool visited) {
    Obstacle::visited = visited;
}

const SDL_Rect &Obstacle::getTopRect() const {
    return top->getRect();
}

const SDL_Rect &Obstacle::getBotRect() const {
    return bot->getRect();
}

int Obstacle::getX() {
    return top->getRectX();

}

int Obstacle::getW() {
    return top->getRectW();
}

void Obstacle::Init(SDL_Renderer *renderer) {

    top->Init(renderer);
    bot->Init(renderer);

}

void Obstacle::reset() {

    this->top->reset();
    this->bot->reset();
    this->visited = false;
}
Obstacle::~Obstacle() {
    delete top;
    delete bot;
}

Obstacle::Obstacle(SquareMovingObject *Top, SquareMovingObject *Bot , int WinWidth , int winHeight,int a ,int b )
        : top(  Top  ) , bot( Bot ) ,
          winWidth(WinWidth) , winHeight(winHeight)
{

    rng = std::make_shared<RNG<int,std::vector>>(a,b,1);
}

Obstacle::Obstacle(SquareMovingObject *Top, SquareMovingObject *Bot , int WinWidth ,
 int winHeight,    std::shared_ptr < RNG <int , std::vector> > Rng )
        : top(  Top  ) , bot( Bot ) ,
          winWidth(WinWidth) , winHeight(winHeight)
        ,rng(Rng)  {}
