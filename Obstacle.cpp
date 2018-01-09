//
// Created by bazyli on 1/6/18.
//

#include "Obstacle.h"

void Obstacle::Update() {

    top.Move( dx , dy );

    bottom.Move(dx,dy);


}

void Obstacle::Draw() {

    top.Draw();
    bottom.Draw();

}
