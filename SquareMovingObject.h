//
// Created by bazyli on 1/11/18.
//

#ifndef ABSTRABIRD_SQUAREOBJECT_H
#define ABSTRABIRD_SQUAREOBJECT_H

#include <SDL_rect.h>
#include <SDL_system.h>
#include <iostream>
#include "Game.h"


class SquareMovingObject {

private:

    double x;

    double y;

    SDL_Rect rect;

    double xSpeed; // -1 .. 1

    double ySpeed;// -1 .. 1

public:

    SquareMovingObject( int x , int y , int h , int w, double xSpd , double ySpd);
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

    void SetRectX(int );
    void SetRectY(int );
    void SetRectH(int );
    void SetRectW(int );

};



#endif //ABSTRABIRD_SQUAREOBJECT_H
