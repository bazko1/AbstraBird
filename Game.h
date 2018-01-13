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


class Game : public IUpdate {

private:

    Window window;

    InputListener listener;

    std::vector<Obstacle>& obstacles;

    GameLogic gameLogic;

    Bird& bird;

    SDL_Renderer* renderer = NULL;

    int points = 0;

    bool finished = false;


public:

    constexpr static const double speedConst = 500.;




    Game(Bird& , std::vector<Obstacle>& obs );

    void Start();

    void mainLoop();

    void update(const double d) override;

    void render() ;

    ~Game();
};




#endif //ABSTRABIRD_GAME_H
