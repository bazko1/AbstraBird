//
// Created by bazyli on 1/8/18.
//

#include <SDL_events.h>
#include "InputListener.h"

void InputListener::checkInput() {

    SDL_Event e;

        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                this->gameFinished = true;
            }



            if ( e.type == SDL_KEYDOWN)
                this->gameStarted = true;


            const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

            if( !this->pause && currentKeyStates[ SDL_SCANCODE_UP ] )
            {
               this->jumped = true;
            }
            if ( currentKeyStates[SDL_SCANCODE_ESCAPE] )
                this->pause = !this->pause;
        }

}

bool InputListener::JumpButtonClicked() const {
    return jumped;
}

void InputListener::setJumped(bool jumped) {
    InputListener::jumped = jumped;
}

bool InputListener::isPause() const {
    return pause;
}

bool InputListener::isGameFinished() const {
    return gameFinished;
}

bool InputListener::isGameStarted() const {
    return gameStarted;
}

void InputListener::reset() {

    pause = false;

    gameFinished = false;

    gameStarted = false;

    jumped= false;



}
