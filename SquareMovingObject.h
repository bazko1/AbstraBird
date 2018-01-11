//
// Created by bazyli on 1/11/18.
//

#ifndef ABSTRABIRD_SQUAREOBJECT_H
#define ABSTRABIRD_SQUAREOBJECT_H

#include <SDL_rect.h>
#include <SDL_system.h>
#include "cmake-build-debug/Game.h"

class SquareMovingObject {

    double x;

    double y;

    SDL_Rect rect;

    double xSpeed; // -1 .. 1

    double ySpeed;// -1 .. 1

public:

    SquareMovingObject( int x , int y , int h , int w,int xSpd , int ySpd);

    void setX(double x);

    double getY() const;

    void setY(double y);

    const SDL_Rect &getRect() const;

    double getXSpeed() const;

    void setXSpeed(double xSpeed);

    double getYSpeed() const;

    void setYSpeed(double ySpeed);

    virtual void Update(double deltaTime );

    virtual void Render( SDL_Renderer* ) = 0;

    virtual bool Intersects(const SquareMovingObject& o2 ) const ;

    double getX() const;
};

SquareMovingObject::SquareMovingObject(int x, int y, int h, int w, int xSpd, int ySpd): xSpeed(xSpd),ySpeed(ySpd) {

    this->x = static_cast<double > (x);

    this->y = static_cast<double > (y);

    rect.x = x;
    rect.y = y;
    rect.h = h;
    rect.w = w;

}


void SquareMovingObject::Update( const double deltaTime ) {

    if (rect.x + rect.w < Window::Width)
    {

        x += xSpeed * deltaTime * Game::speedConst;
        rect.x = x;

    }

    if ( rect.y + rect.h < Window::Height )
    {
        y += ySpeed * deltaTime * Game::speedConst;

        rect.y = y;
    }

}

bool SquareMovingObject::Intersects(const SquareMovingObject& o2) const {
    return SDL_HasIntersection( &this->rect, &o2.rect );
}



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

void SquareMovingObject::setYSpeed(double ySpeed) {
    SquareMovingObject::ySpeed = ySpeed;
}



#endif //ABSTRABIRD_SQUAREOBJECT_H
