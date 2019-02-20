#include <iostream>
#include <SDL.h>
#include <chrono>
#include <SDL_image.h>
#include <vector>
#include "DeltaTimer.h"
#include "Obstacle.h"
#include "Pipes.h"
#include "RectBird.h"
#include "Game.h"
#include "Windows.h"
#include "AbstraBird.h"
#include "GameFabric.h"
#include "Rng.h"
//static const int width = 2*288;
//static const int height = 2*384;

//int piece = 72; //1/8 width
#include "dirmanager.h"

void runGame() {




   FlappyTopPipe* pipe = new FlappyTopPipe( height , width , piece , 240 , -3 );
   FlappyBotPipe* pipe2  = new FlappyBotPipe( height , width , piece , 140 , -3 );

    
   FlappyTopPipe* pipe3 = new FlappyTopPipe(height , width + 5*piece ,144/2,360,-3 );
   FlappyBotPipe* pipe4 = new FlappyBotPipe  (height , width + 5*piece ,144/2 ,240 , -3 );
   
   std::shared_ptr < RNG <int , std::vector> > rng;
   rng = std::make_shared<RNG<int,std::vector>>(70,130,1);


   //std::shared_ptr<Obstacle> o = std::make_shared<Obstacle>( pipe , pipe2 , width + piece  ,height,rng);

    //std::shared_ptr<Obstacle> o2 = std::make_shared<Obstacle>( pipe3,pipe4 , width + piece, height,rng);
    
    //std::shared_ptr<Obstacle> o = std::make_shared<Obstacle>(pipe , pipe2 , width + piece  ,height,rng);

    //std::shared_ptr<Obstacle> o2 = std::make_shared<Obstacle>( pipe3,pipe4 , width + piece, height,rng);

    std::shared_ptr<Obstacle> o = std::make_shared<Obstacle>(pipe , pipe2 , width + piece  ,height,rng);

     std::shared_ptr<Obstacle> o2 = std::make_shared<Obstacle>( pipe3,pipe4 , width + piece, height,rng);


     std::vector <std::shared_ptr<Obstacle>> *vector = new std::vector<std::shared_ptr<Obstacle>> { o , o2  };

    std::shared_ptr<AbstraBird> bird = std::make_shared<AbstraBird>( height , piece-piece/4 ); //Bird

    bird->setX(200);
    bird->setRectX(200);

    bird->setYSpeed(-0.1);
    
    //std::shared_ptr<FlappyWindow> w = std::make_shared<FlappyWindow>();

//std::shared_ptr<FlappyWindow> w = std::make_shared<FlappyWindow>();

    //GameFabric<FlappyTopPipe, FlappyBotPipe, AbstraBird> fabric; //
//    RNG<int,std::vector> rng(1,10,1);
//    rng.getRandom();
    //Game game = GameFabric<FlappyTopPipe, FlappyBotPipe, AbstraBird>::getGame(200,-0.1,Hard);
    //Game game = GameFabric<FlappyTopPipe, FlappyBotPipe, AbstraBird>::getGame(200,-0.1,Medium);
    //Game game = GameFabric<FlappyTopPipe, FlappyBotPipe, AbstraBird>::getGame(200,-0.1,Hard);
    
    //SDL_Window* gw = game.window->sdl_window;
    std::shared_ptr<FlappyWindow> w = std::make_shared<FlappyWindow>();
    //std::shared_ptr<FlappyWindow> w = std::make_shared<FlappyWindow>();
  //SDL_CreateRenderer(w->getSdl_window(), -1, SDL_RENDERER_ACCELERATED);
//    while (true){}
   Game game(bird,vector,w);

    game.Start();





};