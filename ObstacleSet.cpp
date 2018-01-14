//
// Created by bazyli on 1/6/18.
//

#include "ObstacleSet.h"


ObstacleSet::ObstacleSet(const std::vector<Obstacle> &obs) : beginState( obs ) , obstacles( obs.begin() , obs.end() ) {}

void ObstacleSet::update(const double d) {

    for (Obstacle& o : obstacles) {


        o.update(d);

//        if ( o.getBot().getX() < 0   ) {

  //          obstacles.pop_front();
//        }


    }

    //if ( obstacles.size() == 0 )
        //obstacles = std::vector <Obstacle> ( beginState );

        //obstacles.insert(  beginState.begin() , beginState.end() );


}
