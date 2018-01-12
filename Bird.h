//
// Created by bazyli on 1/12/18.
//

#ifndef ABSTRABIRD_BIRD_H
#define ABSTRABIRD_BIRD_H



#include "SquareMovingObject.h"
#include "IIntersects.h"

class Bird : public SquareMovingObject , public IIntersects  {

    double gravity;

public:
    Bird(int x , int y , int h , int w, double xSpd , double ySpd );

    void Update(const double);

    void jump();

    bool intersects(const Obstacle &obstacle) override;

};

#endif //ABSTRABIRD_BIRD_H
