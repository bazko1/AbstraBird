//
// created by bazyli on 1/7/18.
//


#include <SDL_events.h>
#include "Game.h"
#include "DeltaTimer.h"

void Game::Start() {


}


void Game::mainLoop() {

    Timer timer;
    while (true) {


        this->listener.checkInput();

        if (listener.isGameFinished())
            break;

        if (!listener.isPause()) {

            if (listener.hasJumped())
                bird.jump();

            this->update( timer.GetDelta() );

        }
        render();


    }



}

void Game::update(const double d) {

    this->bird.update(d);

    for (Obstacle &o : obstacles)
        o.update(d);
}


void Game::render() {

    SDL_RenderClear(renderer);
    bird.render(renderer);

    for (Obstacle &o : obstacles)
        o.render(renderer);

    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderPresent(renderer);


}

Game::Game(Bird &b , std::vector<Obstacle>& obs ) : bird(b) , obstacles(obs) {

    this->renderer = SDL_CreateRenderer(this->window.getSdl_window(), -1, SDL_RENDERER_ACCELERATED);

    this->mainLoop();

}

Game::~Game() {

    SDL_DestroyRenderer(renderer);

    SDL_Quit();


}



