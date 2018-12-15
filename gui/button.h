#pragma once


#include "SDL.h"
#include <string>
#include <sstream>
#include <ctype.h>
#include <map>
#include <iostream>

class DrawStrategy {

 public:
   void mouseOn(){}
   void mouseOff(){}
   void mouseClicked(){}

};



class Button {
 private:
    std::string text;

    std::string font;
    
    // Defines button behaviour when clicked and
    //other interactions with mouse
    // 
    void update();
 
 
 
 //ButtonDrawAlgorithms
 
 public:
    
    //method deciding how button is draw ( TODO: make it strategy template )
    void render(SDL_Renderer *);
    virtual void onClickAction();





    
};