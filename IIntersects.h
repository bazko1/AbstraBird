//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_IINTERSECTS_H
#define ABSTRABIRD_IINTERSECTS_H

#include "Obstacle.h"
#include "Bird.h"

template <typename T>
class IIntersects {

public:

    virtual bool Intersects ( Obstacle& obstacle , Bird<T>& bird) = 0;

    virtual bool hitsFloor( Bird<T>& bird ) = 0;

    virtual bool hitsCeil( Bird<T>& bird ) = 0;



};






#endif //ABSTRABIRD_IINTERSECTS_H
