//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_GAMELOGIC_H
#define ABSTRABIRD_GAMELOGIC_H


#include <vector>
#include "Bird.h"

class GameLogic {

int wH;
int wW;


public:



    GameLogic(int H , int W ): wH(W) ,wW(H)  {};

    bool score ( Bird& b , Obstacle& obstacle );

};


#endif //ABSTRABIRD_GAMELOGIC_H
