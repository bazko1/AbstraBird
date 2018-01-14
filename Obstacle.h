//
// Created by bazyli on 1/12/18.
//

#ifndef ABSTRABIRD_OBSTACLE_H
#define ABSTRABIRD_OBSTACLE_H


#include "SquareMovingObject.h"
#include "IUpdate.h"
#include "IRenderable.h"

#include <stdlib.h>
#include <time.h>


class Obstacle : public IUpdate, public IRenderable , public IInitable{

    SquareMovingObject& top;
    SquareMovingObject& bot;

    bool visited = false;

    int winWidth;

    int winHeight;

    int ( *gen )() = [](){ srand( time(NULL) ); return rand();  };



public:

    int getX(); // same in both pipes

    int getTopH();

    int getBotH();

    int getW(); // same in both pipes


    bool isVisited() const;


    void setVisited(bool visited);

    const SDL_Rect& getTopRect() const;

    const SDL_Rect& getBotRect() const;


    void render(SDL_Renderer *renderer) override;


    void update(const double d) override;


    Obstacle( SquareMovingObject& , SquareMovingObject& , int , int);

    void Init(SDL_Renderer *renderer) override;


};


#endif //ABSTRABIRD_OBSTACLE_H
