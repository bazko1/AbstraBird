//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_GAMELOGIC_H
#define ABSTRABIRD_GAMELOGIC_H


#include <vector>
#include "Bird.h"

class GameLogic {


    Bird& bird;
    std::vector<Obstacle>& obstacles;


public:

    GameLogic ( Bird&b ,std::vector<Obstacle>& obs  ) : bird(b) , obstacles(obs){

    }

    void update();

private:



};


#endif //ABSTRABIRD_GAMELOGIC_H
