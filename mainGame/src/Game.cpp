//
// created by bazyli on 1/7/18.
//


#include <SDL_events.h>
#include <iostream>
#include "Game.h"
#include "DeltaTimer.h"
#include <memory>
#include "Floor.h"

void Game::Start() {
    for(std::shared_ptr<IInitable> i: inits) {
        i->Init(renderer);
    }

    this->mainLoop();

}


void Game::mainLoop() {


    Timer timer;

    double d;

    while (true)
    {


            this->listener->checkInput();


            if ( listener->isGameFinished()   )
                break;


            if ( finished ) {

                Restart();

                finished = false;
                SDL_Delay(1000);

                timer.GetDelta(); // dont wanna count delay
            }


            d = timer.GetDelta();

            if ( !listener->isPause()  && listener->isGameStarted() && !finished )
            {


                if ( listener->JumpButtonClicked() )
                {
                    bird->jump();
                    listener->setJumped( false );
                }


                this->update( d );

            }


            render();


    }

}

void Game::update(const double d) {
    for(std::shared_ptr<IUpdate> up: updates) {
        up->update(d);
    }

    for (std::shared_ptr<Obstacle> o : obstacles) {

        if ( bird->intersects ( *o ) || bird->intersects(*floor) ) {

            this->finished = true;

        }

        if ( score( *o ) )
        this->score1->scorePlus();


    }

}


void Game::render() {


    SDL_RenderClear(renderer);
    for (std::shared_ptr<IRenderable> r: renders)
        r->render(renderer);
    SDL_RenderPresent(renderer);


}

Game::Game(std::shared_ptr<Bird> b , std::vector<std::shared_ptr<Obstacle> > *obs , std::shared_ptr<Window> w) : bird(b) , obstacles( obs->begin() , obs->end() ) ,  window(w)
{
      //All objects initialization
      floor = std::make_shared<FlappyFloor>(this->window->Width,this->window->Height);
      score1 = std::make_shared<Score<int>>();
      listener = std::make_shared<InputListener>();
      //Initialization of IInitable vector
      this->renderer = SDL_CreateRenderer(this->window->getSdl_window(), -1, SDL_RENDERER_ACCELERATED);
      inits = {window, floor, bird, score1};
      inits.insert(inits.end(),obs->begin(),obs->end());
      //Initialization of IRenderable vector
      renders = {window,floor, bird};
      renders.insert(renders.end(),obs->begin(),obs->end());
      renders.push_back(score1);
      //Initialization of IUpdate
      updates = {bird,floor};
      updates.insert(updates.end(),obs->begin(),obs->end());
      //Initialization of IResetables
      resets = {score1,listener,floor};
      resets.insert(resets.end(),obs->begin(),obs->end());
      //Run init on all Initable objects



}


Game::~Game() {

    SDL_DestroyRenderer(renderer);

    SDL_Quit();


}

bool Game::score(Obstacle &obstacle) {

    int x = obstacle.getX() + obstacle.getW();

    int y1 = 0;

    int y2 = window->Height;


    if(  !obstacle.isVisited() &&  SDL_IntersectRectAndLine( &bird->getRect() ,  &x , &y1 , &x , &y2  )  )
    {
        obstacle.setVisited( true );
        return true;
    }


    return false;



}

void Game::increaseGlobalSpeed(double speed) {

}

void Game::Restart() {

    bird->reset( window->Width ) ;

    for(std::shared_ptr<IResetable> res : resets)
        res->reset();


}




