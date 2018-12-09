#ifndef GAMEFABRIC_H
#define GAMEFABRIC_H
#include <iostream>
#include <SDL.h>
#include <chrono>
#include <SDL_image.h>
#include <bits/unique_ptr.h>
#include <vector>
#include "DeltaTimer.h"
#include "Obstacle.h"
#include "Pipes.h"
#include "RectBird.h"
#include "Game.h"
#include "Windows.h"
#include "AbstraBird.h"
#include "Levels.h"
#include <type_traits>
static const int width = 2*288;
static const int height = 2*384;

int piece = 72; //1/8 width

template<typename Top, typename Bot, typename Bird>
static Game getGame(int,int BirdSpeedY) {

}
template <class Top, class Bot, class Bird, class Enable = void>
class GameFabric {
private:
     Game getGame(int birdInitX, double birdSpeedY,Level);
};
template <class Top, class Bot, class Bird>
class GameFabric<Top, Bot, Bird,
        typename std::enable_if< (std::is_base_of<SquareMovingObject, Top>::value) &&(std::is_base_of<SquareMovingObject, Bot>::value)
        && (std::is_base_of<AbstraBird, Bird>::value)> :: type >
{
public:
    static Game getGame(int birdInitX, double birdSpeedY , Level level) {

        Top* pipe = new Top( height , width , piece , 240 , -3 ); //Top
        Bot* pipe2 = new Bot( height , width , piece , 140 , -3 ); //Bot


        Top* pipe3 = new Top(height , width + 5*piece ,144/2,360,-3 ); //Top
        Bot* pipe4 = new Bot(height , width + 5*piece ,144/2 ,240 , -3 ); //Bot

        std::shared_ptr < RNG <int , std::vector> > rng;

        switch(level)
        {
            case Easy:
            {
                rng = std::make_shared<RNG<int,std::vector>>(130,200,1);
                break;

            }

            case Medium:
            {
                rng = std::make_shared<RNG<int,std::vector>>(70,130,1);
                break;
            }

            case Hard:
            {
                rng = std::make_shared<RNG<int,std::vector>>(60,90,1);
                break;

            }


        }




        std::shared_ptr<Obstacle> o = std::make_shared<Obstacle>(pipe , pipe2 , width + piece  ,height,rng);

        std::shared_ptr<Obstacle> o2 = std::make_shared<Obstacle>( pipe3,pipe4 , width + piece, height,rng);


        std::vector <std::shared_ptr<Obstacle>> *vector = new std::vector<std::shared_ptr<Obstacle>> { o , o2  };

        std::shared_ptr<Bird> bird = std::make_shared<Bird>( height , piece-piece/4 ); //Bird

        bird->setX(birdInitX);
        bird->setRectX(birdInitX);

        bird->setYSpeed(birdSpeedY);
        std::shared_ptr<FlappyWindow> w = std::make_shared<FlappyWindow>();

        return Game(bird,vector,w);
    }
};
#endif // GAMEFABRIC_H
