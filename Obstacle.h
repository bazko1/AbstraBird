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
#include <memory>
#include "IResetable.h"
#include "Rng.h"

class Obstacle : public IUpdate, public IRenderable , public IInitable, public IResetable {

    SquareMovingObject* top;
    SquareMovingObject* bot;

    bool visited = false;

    int winWidth;

    int winHeight;

    std::shared_ptr < RNG <int , std::vector> > rng;

    //int ( *gen )() = rng->getRandom;
    //[](){ srand( time(NULL) ); return rand();  };



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


    Obstacle( SquareMovingObject* , SquareMovingObject* , int , int);

    Obstacle( SquareMovingObject* , SquareMovingObject* , int , int,int , int);

    Obstacle( SquareMovingObject* , SquareMovingObject* , int , int , std::shared_ptr < RNG <int , std::vector> > );

    void Init(SDL_Renderer *renderer) override;

    void reset();

    ~Obstacle();
};


#endif //ABSTRABIRD_OBSTACLE_H
