//
// Created by bazyli on 1/6/18.
//
// Class contains all obstacle redraws them, adds them into Container on the begining


#ifndef ABSTRABIRD_OBSTACLEARR_H
#define ABSTRABIRD_OBSTACLEARR_H


#include <vector>
#include <queue>
#include "Obstacle.h"
#include <list>



class ObstacleSet  : public IUpdate   {


    const std::vector <Obstacle>& beginState;

    std::list <Obstacle> obstacles;

    int dist;

public:

    ObstacleSet(const std::vector <Obstacle>& obs);

    void update(const double d) override;


};


#endif //ABSTRABIRD_OBSTACLEARR_H
