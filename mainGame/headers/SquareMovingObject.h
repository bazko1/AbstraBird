//
// Created by bazyli on 1/11/18.
//

#ifndef ABSTRABIRD_SQUAREOBJECT_H
#define ABSTRABIRD_SQUAREOBJECT_H


#include "SquareObject.h"
#include "IUpdate.h"
#include "IRenderable.h"
#include "IInitable.h"

class SquareMovingObject : public SquareObject , public IUpdate,public IRenderable , public IInitable {
public:
    void render(SDL_Renderer *renderer) override;

private:

    double x; // For accuracy

    double y; // ^

    double xSpeed; //

    double ySpeed;//

    int drawXBeginPos;

public:

    SquareMovingObject(){}

    SquareMovingObject ( const SquareMovingObject& );

    SquareMovingObject( int x , int y , int h , int w, double xSpd , double ySpd);

    void setX(double x);

    double getY() const;

    void update(const double ) override;

    void setY(double y);

    const SDL_Rect &getRect() const;

    double getXSpeed() const;

    void setXSpeed(double xSpeed);

    double getYSpeed() const;

    void setYSpeed(double ySpeed);

    double getX() const;

    void reset();

    void Init(SDL_Renderer *renderer) override;

};



#endif //ABSTRABIRD_SQUAREOBJECT_H
