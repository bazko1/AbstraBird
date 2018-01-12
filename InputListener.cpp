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
            if( currentKeyStates[ SDL_SCANCODE_UP ] )
            {
               this->jumped = true;
            }
            if ( currentKeyStates[SDL_SCANCODE_ESCAPE] )
                this->pause = true;
        }

}

bool InputListener::hasJumped() const {
    return jumped;
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
