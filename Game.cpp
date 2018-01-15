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

    while (true)
    {


            this->listener.checkInput();


            if ( listener.isGameFinished()   )
                break;

            if ( !listener.isPause()  && listener.isGameStarted() && !finished )
            {



                if ( listener.JumpButtonClicked() )
                {
                    bird.jump();
                    listener.setJumped( false );
                }

               this->update( timer.GetDelta() );


            }
            else
                timer.GetDelta();




            render();


    }

}

void Game::update(const double d) {

    this->bird.update(d);

    for (Obstacle &o : obstacles) {

        o.update(d);


        if ( bird.intersects ( o ) ) {

            this->finished = true;

        }

        if ( score( o ) )
        this->score1.scorePlus();

    }

}


void Game::render() {


    SDL_RenderClear(renderer);

    window.render(renderer);

    bird.render(renderer);

    for (Obstacle &o : obstacles)
        o.render(renderer);

    score1.render(renderer);

    SDL_RenderPresent(renderer);


}

Game::Game(Bird &b , std::vector<Obstacle>& obs , Window& w ) : bird(b) , obstacles( obs.begin() , obs.end() ) , gameLogic( window.Height , window.Width ) , orginal(obs) , window(w) {


    this->renderer = SDL_CreateRenderer(this->window.getSdl_window(), -1, SDL_RENDERER_ACCELERATED);

    window.Init(renderer);

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

    //bird.setYSpeed(  bird.getYSpeed() )

}




