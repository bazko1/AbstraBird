//
// Created by bazyli on 1/11/18.
//

#ifndef ABSTRABIRD_SQUAREOBJECT_H
#define ABSTRABIRD_SQUAREOBJECT_H


#include "SquareObject.h"
#include "IUpdate.h"
#include "IRenderable.h"

class SquareMovingObject : public SquareObject , public IUpdate , public IRenderable  {
private:

    double x; // For accuracy

    double y; // ^

    SDL_Rect rect;


    double xSpeed; //

    double ySpeed;//

public:

    SquareMovingObject(){}
    SquareMovingObject( int x , int y , int h , int w, double xSpd , double ySpd);
    void setX(double x);

    double getY() const;

    virtual void Update(const double deltaTime);

    void setY(double y);

    const SDL_Rect &getRect() const;

    double getXSpeed() const;

    void setXSpeed(double xSpeed);

    double getYSpeed() const;

    void setYSpeed(double ySpeed);

    //virtual bool Intersects(const SquareMovingObject& o2 ) const ;

    double getX() const;



};



#endif //ABSTRABIRD_SQUAREOBJECT_H
