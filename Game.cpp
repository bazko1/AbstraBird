//
// created by bazyli on 1/7/18.
//


#include <SDL_events.h>
#include <iostream>
#include "Game.h"
#include "DeltaTimer.h"

void Game::Start() {


}


void Game::mainLoop() {


    Timer timer;

    double d;

    while (true)
    {


            this->listener.checkInput();


            if ( listener.isGameFinished()   )
                break;


            if ( finished ) {

                Restart();

                finished = false;
                SDL_Delay(1000);

                timer.GetDelta(); // dont wanna count delay
            }


            d = timer.GetDelta();

            if ( !listener.isPause()  && listener.isGameStarted() && !finished )
            {


                if ( listener.JumpButtonClicked() )
                {
                    bird.jump();
                    listener.setJumped( false );
                }

               this->update( d );


            }

            f.update(d);


            render();


    }

}

void Game::update(const double d) {

    this->bird.update(d);


    for (Obstacle &o : obstacles) {
        o.update(d);


        if ( bird.intersects ( o ) || bird.intersects(f) ) {

            this->finished = true;

        }

        if ( score( o ) )
        this->score1.scorePlus();


    }

}


void Game::render() {


    SDL_RenderClear(renderer);

    window.render(renderer);

    f.render(renderer);

    bird.render(renderer);

    for (Obstacle &o : obstacles)
        o.render(renderer);

    score1.render(renderer);

    SDL_RenderPresent(renderer);


}

Game::Game(Bird &b , std::vector<Obstacle>& obs , Window& w ) : bird(b) , obstacles( obs.begin() , obs.end() ) , gameLogic( window.Height , window.Width )  , window(w)
,f(window.Width,window.Height)
{


    this->renderer = SDL_CreateRenderer(this->window.getSdl_window(), -1, SDL_RENDERER_ACCELERATED);

    window.Init(renderer);

    f.Init(renderer);

    bird.Init(renderer);


    for (Obstacle &o : obstacles)
        o.Init( renderer );

      score1.Init(renderer);

        this->mainLoop();


}


Game::~Game() {

    SDL_DestroyRenderer(renderer);

    SDL_Quit();


}

bool Game::score(Obstacle &obstacle) {

    int x = obstacle.getX() + obstacle.getW();

    int y1 = 0;

    int y2 = window.Height;


    if(  !obstacle.isVisited() &&  SDL_IntersectRectAndLine( &bird.getRect() ,  &x , &y1 , &x , &y2  )  )
    {
        obstacle.setVisited( true );
        return true;
    }


    return false;



}

void Game::increaseGlobalSpeed(double speed) {

}

void Game::Restart() {

    bird.reset( window.Width ) ;

    for ( Obstacle& o : obstacles   )
        o.reset();

    score1.reset();

    this->listener.reset();


}




