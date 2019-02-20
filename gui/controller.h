#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <list>
#include <memory>
#include <utility>
#include "observer.h"
#include "GWindow.h"

//Singleton 

class GWindow;
class MouseController :public Observer  {
    
    private:

     int x,y;
     
     bool buttons[3] = {0,0,0};
     bool clicked = false;
     MouseController() = default;
     GWindow* window;

    public:
    
     MouseController(MouseController const &) = delete;
     MouseController& operator=(MouseController const&) = delete;
     ~MouseController()  {};
      
     static MouseController& instance();
 
     const std::pair<Uint8,Uint8> getPos()const { return std::pair<Uint8,Uint8>(x,y);  };
     int getX()const{return x;}
     int getY()const{return y;}
     bool isClicked()const{ return clicked; };
     
     void Update ( Subject* changed);
     void update();
     void AttachTo ( GWindow*);
    // void Notify() override;


};



#endif