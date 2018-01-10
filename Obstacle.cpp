//
// Created by bazyli on 1/6/18.
//

#include "Obstacle.h"
template <typename T>
void Obstacle<T>::Update() {

    top.Move( dx , dy );

    bottom.Move(dx,dy);


}


