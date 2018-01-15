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

struct Opak
{
    SDL_Surface* surface;

    ~Opak(){

        SDL_FreeSurface(surface);

    }
};


int main() {



//    struct speed {
//
//        speed (double x , double y) : x(x),y(y){};
//
//        double x;
//        double y;
//    };
//
//    speed speed1(0.5,0.01);
//
//
//
//    SDL_Rect rect;
//    rect.w=120;
//    rect.h=40;
//    rect.x=0;
//    rect.y=height/2;
//
//    SDL_Rect rect2 ={0,0,40,40};
////
//    double X=0.;
//    double Y=height/2.;
//
//    SDL_Window *win = NULL;
//    SDL_Renderer *renderer = NULL;
//    SDL_Texture *bitmapTex = NULL;
//    SDL_Texture *bitmapTex2 = NULL;
//    SDL_Surface *bitmapSurface = NULL;
//    SDL_Surface *bitmapSurface2 = NULL;
//
//
//    SDL_Init(SDL_INIT_EVERYTHING);
//
//    win = SDL_CreateWindow("Abstra Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
//
//    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
//
//
//    bitmapSurface = IMG_Load("/home/bazyli/CLionProjects/AbstraBird/Pictures/bg.png");

    //bitmapSurface2 = SDL_LoadBMP("/home/bazyli/CLionProjects/AbstraBird/Pictures/Bird2.bmp");

//    bitmapSurface2 = IMG_Load("/home/bazyli/Desktop/abstapicsts/bird_sing.png");
//
//    SDL_Surface* top = IMG_Load("/home/bazyli/Desktop/abstapicsts/tube1.png");
//
//    SDL_Surface* bot = IMG_Load("/home/bazyli/Desktop/abstapicsts/tube2.png");
//
//    SDL_Surface* ground= IMG_Load("/home/bazyli/Desktop/abstapicsts/ground.png");
//
//
//    SDL_Texture* topS = SDL_CreateTextureFromSurface ( renderer , top);
//
//    SDL_Texture* botS = SDL_CreateTextureFromSurface ( renderer , bot);
//
//    SDL_Texture* groundS = SDL_CreateTextureFromSurface ( renderer , bot);
//
//    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
//
//    bitmapTex2 = SDL_CreateTextureFromSurface(renderer,bitmapSurface2);

    //SDL_Texture
//    std::cout<<bitmapSurface;
//
//    SDL_FreeSurface(bitmapSurface);
//
//    SDL_Rect TP = {width-52,0,40*2,100*2};
//    SDL_Rect DP = {width-52,height-100,40*2,2*100};
//
//    SDL_FreeSurface(bitmapSurface2);
//
//
//    SDL_Rect rect3 = {0,height/2,2*36,2*26};
//
//    double PipespeedX = -0.5;
//    double pipeX = width;
//
//
//    RectFillBird bird(0,height/2,40,40,0,0);
//    Timer timer;
//    bird.setYSpeed ( 0 );
//   bird.setY( height/2 );
//
//    double gravity = 0.09;
// std::cout<<bird.getRect().y;
//
//    Obstacle obstacle(width,height,300,40);
//
//
//
//    bool  start = false;
//    while (1) {
//
//
//        bool up = false;
//        SDL_Event e;
//        if (SDL_PollEvent(&e)) {
//            if (e.type == SDL_QUIT) {
//                break;
//            }
//
//            if ( e.type == SDL_KEYDOWN)
//                start= true;
//
//            const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
//            if( currentKeyStates[ SDL_SCANCODE_UP ] )
//            {
//               up = true;
//            }
//
//        }
//
//
//        //if ( bird.getYSpeed() < gravity )
//        double  delta = timer.GetDelta();
//
//        //if ( bird.getYSpeed() < gravity ) {
//
//            if ( up  )
//                bird.setYSpeed( -1 );
//
//
//         if( bird.Intersects( obstacle.getTop() ) || bird.Intersects( obstacle.getBot() )  )
//                start = false;
//
//
//        if ( start)
//            {
//                double speed = bird.getYSpeed() + 0.5 * gravity * gravity;
//
//                bird.setYSpeed(speed);
//                bird.Update(  delta);
//                obstacle.Update(delta);
//
//            }
//
//
//
//
//
//
//        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//        SDL_RenderClear(renderer);
//        bird.render( renderer  );
//        obstacle.Render(renderer);
//        SDL_RenderPresent(renderer);



//        SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
//
//
//        SDL_RenderCopyEx( renderer, bitmapTex2, 0, &rect3,  0, NULL, SDL_FLIP_NONE );
//
//        SDL_RenderCopyEx( renderer, botS, 0, &DP,  0, NULL, SDL_FLIP_NONE );
//        SDL_RenderCopyEx( renderer, topS, 0, &TP,  0, NULL, SDL_FLIP_NONE );
//

       // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
     //   SDL_RenderFillRect(renderer, &rect2);


        //SDL_RenderCopyEx( renderer, NULL, nullptr, &rect2,  , NULL, SDL_FLIP_NONE );



//
//       // SDL_Inter
//       // std::cout<< SDL_HasIntersection(&rect2,&TP);
//        double d = timer.GetDelta();
//
//        if (rect2.x + rect2.w < width || TP.x>0) {
//
//        X += speed1.x * d * 300.0 ;
//
//            pipeX += PipespeedX * d * 300.0;
//
//            rect.x = X;
//            rect2.x =X;
//
//            TP.x = pipeX;
//            DP.x = pipeX;
//         //    rect3.x = X;
//
//    } else rect.x = width-rect.w;
//
//
//        if (rect3.y + rect3.h < height && rect3.y - rect3.h > 0) {
//
//            Y += ( d * speed1.y *310.0);
//            rect3.y = Y;
//
//        } else rect3.y = height-rect3.h;
//        speed1.y += 0.0005;

        //milliseconds mSec(d);

        //duration < int  ,  std::milli > asUint ( d) ;
        //Uint32 ui = timer.GetDelta();
       // Uint32 delay = 16.0 - d;


        //SDL_Delay(  delay );

        //IMG_Load()

   // }



//    SDL_DestroyTexture(bitmapTex);


    //Obstacle p;
    //SquareMovingObject*obj;
    FlappyTopPipe pipe( height , width , piece , 240 , -1.6 );
    FlappyBotPipe pipe2 ( height , width , piece , 140 , -1.6 );


    FlappyTopPipe pipe3(height , width + 5*piece ,144/2,360,-1.6 );
    FlappyBotPipe pipe4 (height , width + 5*piece ,144/2 ,240 , -1.6 );


//    SquareFilledTopPipe pipe5(height , width + 940 ,40,360,-0.6 );
  //  SquareFilledBotPipe pipe6 (height , width + 940,40,240 , -0.6 );


    Obstacle o ( pipe , pipe2 , width + piece  ,height);

    Obstacle o2 ( pipe3,pipe4 , width + piece, height);

//    Obstacle o3 ( pipe5 , pipe6 ,width,height);

    std::vector <Obstacle> vector = { o , o2  };

    AbstraBird bird( height , piece-piece/4 );

    bird.setX(200);
    bird.setRectX(200);

    bird.setYSpeed(0);
    FlappyWindow w;
    Game game(bird,vector,w);



    return 0;



}