
#include <iostream>
#include <SDL.h>
#include "button.h"
#include "bindings.h"
#include "InteractiveRectGetter.h"
#include "FileLoader.h"
#include "runGame.h"

SDL_Renderer* r = NULL;
InteractiveRectGetter* geter = NULL;
FileLoader Fl;
SDL_Window* win;
GWindow* gW;

 static void foo() {
    Fl.interactiveLoadName();
    SDL_Texture* texture = Fl.LoadImageAsTexture(r);

    if ( texture ) {
        geter->setTexture(texture);
    }
    else
        SDL_Log("texture = null");
    
    SDL_RaiseWindow(win);
    
};
static void foo2(){
    
    SDL_Quit();
    gW->setFinished(true);
    runGame();

}

int main() {

    SDL_Init(SDL_INIT_EVERYTHING);

    GWindow w;
    gW=&w;
    win = w.getSdl_window();
    r = w.getRenderer();

    
    Button<> Sb(150,30,400,100);
    Sb.setText("StartGame");
    Sb.setFn(foo2);

    Button<> b(150,150,400,100);
    b.setFn(foo);
    b.setText("ChooseFile");
    
    b.AttachTo(&w);
    Sb.AttachTo(&w);
    
    //Created for sake of showing that it works and to show abstraction of startegy a (button which drawing is printing on screen)
    //Button<MouseController,S2> b3(0,0,10,10);
    //b3.AttachTo(&w);

    SDL::Rect rect = SDL::Rect(0,270,288*2,498);
    InteractiveRectGetter Rg (rect);
    geter = &Rg;
    Rg.AttachTo(&w);
    

    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart,frameTime;

    
    while ( !w.gFinished() ) {

        frameStart = SDL_GetTicks();

        SDL_Event e;
        
        w.Notify();
        
        frameTime = SDL_GetTicks() - frameStart;

        if ( frameDelay > frameTime ) {
            SDL_Delay(frameDelay - frameTime );
        }

    }
    

    SDL_Quit();
    

    return 0;



}
