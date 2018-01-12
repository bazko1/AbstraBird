//
// Created by bazyli on 1/12/18.
//

#ifndef ABSTRABIRD_IRENDERABLE_H
#define ABSTRABIRD_IRENDERABLE_H

#include <SDL_render.h>

class IRenderable {
public:
    virtual void render(SDL_Renderer* renderer) = 0 ;
};

#endif //ABSTRABIRD_IRENDERABLE_H
