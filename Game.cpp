//
// created by bazyli on 1/7/18.
//


#include <SDL_events.h>
#include "Game.h"
void Game::Start() {



}

void Game::Pause() {

    isPaused = true;
}

void Game::mainLoop() {

    while ( true ) {


        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        // Check Input ();


        if ( !isPaused ) {

            // UpdateObjectsStates

        }



    }

        Render();


        /// wait


    }



void Game::Render() {

    //bird.Draw();

    //obstacles.Draw();


}

