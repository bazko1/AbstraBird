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

    Window& window;

    InputListener listener;

    std::list<Obstacle> obstacles;

    const std::vector<Obstacle> orginal;

    GameLogic gameLogic;

    Bird& bird;

    SDL_Renderer* renderer = NULL;

    int points = 0;

    bool finished = false;

    int count = 0;

public:

    //constexpr static const double speedConst = 500.;


    bool score( Obstacle& obstacle );

    Game(Bird& , std::vector<Obstacle>& obs , Window& );

    void Start();

    void mainLoop();

    void update(const double d) override;

    void render() ;

    ~Game();
};




#endif //ABSTRABIRD_GAME_H
