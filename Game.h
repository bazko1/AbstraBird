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
#include <memory>

class Game : public IUpdate {

private:

    std::shared_ptr<Window> window;

    std::shared_ptr<InputListener> listener;

    std::vector<std::shared_ptr<Obstacle>> obstacles;

    std::shared_ptr<GameLogic> gameLogic;

    std::shared_ptr<Bird> bird;

    SDL_Renderer* renderer = NULL;

    bool finished = false;

    std::shared_ptr<Score<int>> score1;

    std::shared_ptr<FlappyFloor> floor;

    std::vector<std::shared_ptr<IInitable>> inits;

    std::vector<std::shared_ptr<IRenderable>> renders;

    std::vector<std::shared_ptr<IUpdate>> updates;

    std::vector<std::shared_ptr<IResetable>> resets;

public:


    bool score( Obstacle& obstacle );

    Game(std::shared_ptr<Bird> , std::vector<std::shared_ptr<Obstacle>>* obs , std::shared_ptr<Window>);

    void Start();

    void mainLoop();

    void update(const double d) override;

    void render() ;

    void increaseGlobalSpeed(double speed );

    void Restart();

    ~Game();
};




#endif //ABSTRABIRD_GAME_H
