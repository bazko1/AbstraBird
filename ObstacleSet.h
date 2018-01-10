//
// Created by bazyli on 1/6/18.
//
// Class contains all obstacle redraws them, adds them into Container on the begining


#ifndef ABSTRABIRD_OBSTACLEARR_H
#define ABSTRABIRD_OBSTACLEARR_H


#include <vector>
#include "Obstacle.h"
template <typename T>
class ObstacleSet : std::vector< Obstacle<T> > {

private:

  //  std::vector <Obstacle> obstacles;

public:

    template < typename Generate >
     void AddObstacle();




};


#endif //ABSTRABIRD_OBSTACLEARR_H
