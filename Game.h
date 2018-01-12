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


class Game {

private:

    Window& window;

//    GameLogic<T>& gameLogic;
//
//    //Bird<T>& bird;
//
//    ObstacleSet<T>& obstacles;
//
//    InputListener& listener;

    bool isPaused = false;

    bool finished = false;

    std::vector <IDrawable> toDraw;

public:

    constexpr static const double speedConst = 500.;


    //Game ( Window& w ,  Bird<T>& b , GameLogic<T>& logic , ObstacleSet<T>& obstacleSet , InputListener& listener );

    void Start();

    void Pause();

    void mainLoop();

    void Render();

};




#endif //ABSTRABIRD_GAME_H
