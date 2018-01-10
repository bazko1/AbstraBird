//
// Created by bazyli on 1/6/18.
//

#include "GameLogic.h"
#include "ObstacleSet.h"

template <typename T>
bool IIntersects<T>::hitsCeil(Bird<T> &bird) {

}

template <typename T>
bool IIntersects<T>::hitsFloor(Bird<T> &bird) {

}
template <typename T>
bool IIntersects<T>::Intersects( Obstacle<T> &obstacle , Bird<T> &bird)  {
    return false;

}

template <typename T>
bool GameLogic<T>::GameOver(Bird<T> &bird , ObstacleSet<T>& obstacleSet) {

    if ( hitsFloor(bird)|hitsCeil(bird) )
        return true;

    for ( Obstacle<T> obstacle: obstacleSet ){

        if (  Intersects( obstacle , bird ) )
            return true;

    }




}
