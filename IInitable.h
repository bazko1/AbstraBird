//
// Created by bazyli on 1/14/18.
//

#ifndef ABSTRABIRD_IINITABLE_H
#define ABSTRABIRD_IINITABLE_H

#include <SDL_system.h>

class IInitable {

public:
    virtual void Init( SDL_Renderer* )=0;

};


#endif //ABSTRABIRD_IINITABLE_H
