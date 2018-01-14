//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_GAMELOGIC_H
#define ABSTRABIRD_GAMELOGIC_H


#include <vector>
#include "Bird.h"

class GameLogic {


int prevBegin = 0;

    int wH;

    int wW;

    int ( *gen)() = [](){ srand( time(NULL) ); return rand();  };




public:



    GameLogic(int H , int W ): wH(W) ,wW(H)  {};

    bool score (const Bird& b , Obstacle& obstacle ) const ;

    void randomizeDistSize( Obstacle& );

};


#endif //ABSTRABIRD_GAMELOGIC_H
