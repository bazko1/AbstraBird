//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_BIRD_H
#define ABSTRABIRD_BIRD_H


#include "IDrawable.h"
#include "IMovable.h"

class Bird : IDrawable , IMovable {

private:

    /// Coordinates
    double x;
    double y;
    /// Movement
    double dx;
    double dy;

public:

    void Update();

    void IDrawable::Draw();

    void IMovable::Move(double xPos, double yPos);



};


#endif //ABSTRABIRD_BIRD_H
