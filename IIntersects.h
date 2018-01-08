//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_IINTERSECTS_H
#define ABSTRABIRD_IINTERSECTS_H

#include "Obstacle.h"
#include "Bird.h"

class IIntersects {

public:

    virtual bool Intersects ( Obstacle& obstacle , Bird& bird) = 0;




};






#endif //ABSTRABIRD_IINTERSECTS_H
