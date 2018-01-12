//
// Created by bazyli on 1/12/18.
//

#include "Bird.h"

void Bird::Update(const double d) {

    // apply gravity

    double  spd = this->getYSpeed() + 0.5* gravity * gravity;
    this->setYSpeed( spd );

    // normal update
    SquareMovingObject::Update( d );
}

bool Bird::intersects(const Obstacle &obstacle) {
    return SDL_HasIntersection( &this->getRect(), &obstacle.getTop().getRect() )
         ||   SDL_HasIntersection( &this->getRect(), &obstacle.getBot().getRect() );
}

void Bird::jump() {

    this->setYSpeed( -1 );

}

Bird::Bird(int x, int y, int h, int w, double xSpd, double ySpd) : SquareMovingObject(x, y, h, w, xSpd, ySpd) {};

