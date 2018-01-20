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


static const int width = 2*288;
static const int height = 2*384;

int piece = 72; //1/8 width


int main() {




    FlappyTopPipe pipe( height , width , piece , 240 , -3 );
    FlappyBotPipe pipe2 ( height , width , piece , 140 , -3 );


    FlappyTopPipe pipe3(height , width + 5*piece ,144/2,360,-3 );
    FlappyBotPipe pipe4 (height , width + 5*piece ,144/2 ,240 , -3 );




    Obstacle o ( pipe , pipe2 , width + piece  ,height);

    Obstacle o2 ( pipe3,pipe4 , width + piece, height);


    std::vector <Obstacle> vector = { o , o2  };

    AbstraBird bird( height , piece-piece/4 );

    bird.setX(200);
    bird.setRectX(200);

    bird.setYSpeed(-0.1);
    FlappyWindow w;
    Game game(bird,vector,w);



    return 0;



}