//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_OBSTACLE_H
#define ABSTRABIRD_OBSTACLE_H


#include "Pipe.h"
#include "IUpdate.h"

class Obstacle : IUpdate , IDrawable{

    int dx;

    int dy;

    Pipe top;

    Pipe bottom;

public:
    void Update() override;
    void Draw() override;


};


#endif //ABSTRABIRD_OBSTACLE_H
