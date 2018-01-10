#include <iostream>
#include <SDL.h>
#include <chrono>
#include <SDL_image.h>
#include <bits/unique_ptr.h>
#include "DeltaTimer.h"
static int width = 720;
static int height = 480;


struct Opak
{
    SDL_Surface* surface;

    ~Opak(){

        SDL_FreeSurface(surface);

    }
};


int main() {



    struct speed {

        speed (double x , double y) : x(x),y(y){};

        double x;
        double y;
    };

    speed speed1(0.5,0.8);



    SDL_Rect rect;
    rect.w=40;
    rect.h=40;
    rect.x=0;
    rect.y=height/2;

    SDL_Rect rect2 ={0,0,40,40};
//
    double X=0.;
    double Y=0.;

    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    SDL_Texture *bitmapTex2 = NULL;
    SDL_Surface *bitmapSurface = NULL;
    SDL_Surface *bitmapSurface2 = NULL;


    SDL_Init(SDL_INIT_EVERYTHING);

    win = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);


    bitmapSurface = SDL_LoadBMP("/home/bazyli/Desktop/ASTRO2.BMP");

    bitmapSurface2 = SDL_LoadBMP("/home/bazyli/Desktop/Bird2.bmp");

    //IMG_Load("")
    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);

    bitmapTex2 = SDL_CreateTextureFromSurface(renderer,bitmapSurface2);

    //SDL_Texture


    SDL_FreeSurface(bitmapSurface);

    SDL_FreeSurface(bitmapSurface2);

    Timer timer;

    int count=0;
    int state = 0;
    while (1) {

        count++;

        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }




        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);

        if (count%31==0)
        SDL_RenderCopyEx( renderer, bitmapTex2, nullptr, &rect,  90, NULL, SDL_FLIP_NONE );
        else
            SDL_RenderCopyEx( renderer, bitmapTex2, nullptr, &rect,  0, NULL, SDL_FLIP_NONE );


        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        //SDL_RenderCopyEx( renderer, NULL, nullptr, &rect2,  , NULL, SDL_FLIP_NONE );
        SDL_RenderFillRect(renderer, &rect2);


        SDL_RenderPresent(renderer);



        double d = timer.GetDelta();

        if (rect.x + rect.w < width) {

        X += speed1.x * d * 300 ;


            rect.x = X;
            rect2.x =X;


    } else rect.x = width-rect.w;

        //milliseconds mSec(d);

        //duration < int  ,  std::milli > asUint ( d) ;
        //Uint32 ui = timer.GetDelta();
       // Uint32 delay = 16.0 - d;


        //SDL_Delay(  delay );

        //IMG_Load()

    }



    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;




    return 0;

}