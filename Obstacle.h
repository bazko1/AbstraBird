//
// Created by bazyli on 1/12/18.
//

#ifndef ABSTRABIRD_OBSTACLE_H
#define ABSTRABIRD_OBSTACLE_H


#include "SquareMovingObject.h"
#include "IUpdate.h"
#include "IRenderable.h"

class Obstacle : public IUpdate, public IRenderable {

    SquareMovingObject &top;
    SquareMovingObject &bot;

    bool visited = false;

    int winWidth;
public:
    bool isVisited() const;

    void setVisited(bool visited);
//    int winHeight;

public:

    SquareMovingObject &getTop() const;

    SquareMovingObject &getBot() const;

    void render(SDL_Renderer *renderer) override;

    void update(const double d) override;

    Obstacle(int WinWidth, int WinHeight, SquareMovingObject &top, SquareMovingObject &bot);

    Obstacle( SquareMovingObject& , SquareMovingObject& , int );

};


#endif //ABSTRABIRD_OBSTACLE_H
