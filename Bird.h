//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_BIRD_H
#define ABSTRABIRD_BIRD_H


#include "IDrawable.h"
#include "IUpdate.h"


template <typename T>
class Bird : IDrawable , IUpdate {

private:

    /// Coordinates
    T x;
    T y;
    /// Movement
    T dx;
    T dy;

public:

    void Update();



};


#endif //ABSTRABIRD_BIRD_H
