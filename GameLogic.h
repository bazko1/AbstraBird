//
// Created by bazyli on 1/6/18.
//

#ifndef ABSTRABIRD_GAMELOGIC_H
#define ABSTRABIRD_GAMELOGIC_H


#include "IIntersects.h"
#include "ObstacleSet.h"
template <typename T>
class GameLogic : IIntersects<T> {


bool lost = false;




public:

    bool GameOver ( Bird<T>& b , ObstacleSet& obstacleSet);

};


#endif //ABSTRABIRD_GAMELOGIC_H
