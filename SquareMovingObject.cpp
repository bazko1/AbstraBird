//
// Created by bazyli on 1/12/18.
//





#include "SquareMovingObject.h"


SquareMovingObject::SquareMovingObject(int x, int y, int h, int w, double xSpd, double ySpd) :
        xSpeed(xSpd),ySpeed(ySpd)
{



    this->x = static_cast<double > (x);

    this->y = static_cast<double > (y);

    rect.x = x;
    rect.y = y;
    rect.h = h;
    rect.w = w;

}


//bool SquareMovingObject::Intersects(const SquareMovingObject& o2) const {
//    return SDL_HasIntersection( &this->rect, &o2.rect );
//}



double SquareMovingObject::getX() const {
    return x;
}

void SquareMovingObject::setX(double x) {
    SquareMovingObject::x = x;
}

double SquareMovingObject::getY() const {
    return y;
}

void SquareMovingObject::setY(double y) {
    SquareMovingObject::y = y;
}

const SDL_Rect &SquareMovingObject::getRect() const {
    return rect;
}


double SquareMovingObject::getXSpeed() const {
    return xSpeed;
}

void SquareMovingObject::setXSpeed(double xSpeed) {
    SquareMovingObject::xSpeed = xSpeed;
}

double SquareMovingObject::getYSpeed() const {
    return ySpeed;
}

void SquareMovingObject::setYSpeed(double ySpd) {


    SquareMovingObject::ySpeed = ySpd;

}

void SquareMovingObject::Update(const double deltaTime) {


    double c = 300; //Game::speedConst;

    y += ySpeed * deltaTime * c;
    x += xSpeed * deltaTime * c;

    rect.x = x;


    rect.y = y;




}



