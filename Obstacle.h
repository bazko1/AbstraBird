//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_OBSTACLE_H
#define ABSTRABIRD_OBSTACLE_H


#include "Pipe.h"
#include "IUpdate.h"
template <typename T>
class Obstacle : IUpdate {

    T dx;

    T dy;

    Pipe<T> top;

    Pipe<T> bottom;

public:
    void Update() override;


};


#endif //ABSTRABIRD_OBSTACLE_H
