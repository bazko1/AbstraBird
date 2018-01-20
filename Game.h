//
// Created by bazyli on 1/7/18.
//

#ifndef ABSTRABIRD_GAME_H
#define ABSTRABIRD_GAME_H

#include <vector>
#include "Window.h"
#include "GameLogic.h"
#include "ObstacleSet.h"
#include "InputListener.h"
#include "Obstacle.h"
#include "Score.h"
#include "Floor.h"


class Game : public IUpdate {

private:

    Window& window;

    InputListener listener;

    std::vector<Obstacle> obstacles;

    GameLogic gameLogic;

    Bird& bird;

    SDL_Renderer* renderer = NULL;

    bool finished = false;

    Score<int> score1;

    FlappyFloor floor;


public:


    bool score( Obstacle& obstacle );

    Game(Bird& , std::vector<Obstacle>& obs , Window& );

    void Start();

    void mainLoop();

    void update(const double d) override;

    void render() ;

    void increaseGlobalSpeed(double speed );

    void Restart();

    ~Game();
};




#endif //ABSTRABIRD_GAME_H
