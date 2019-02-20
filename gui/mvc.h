#pragma once
#include <list>
#include <algorithm>
#include <iostream>

// Button , Slider , 
//class Controller;
//class MouseController;

class Model {
    public:
    virtual void update(Controller*);

};

class ButtonT : Model {

    void update(Controller*){}

    void update (MouseController * c) {

            std::cout<<  "Update\n";
        
    }


};


// Window
class View {

//add controler -> addbutton
//  mainLoop{  controler.update() ( take MouseXY , check if it   )  }

};


// Mouse , keyboard , joystick 

class Controller {
private:
    std::list <Model*> Models;

public:
    
    void Notify() {

        for( Model* m : Models )
            m->update(this);
    }

    void Attach ( Model* m  ) {
        Models.push_back(m);
    }

    void Detach( Model* m ) {
        Models.remove(m);
    }

};


// <Button>
// class MouseController : Controller  {
    
//      Uint8 x,y;
//      bool buttons[3] = {0,0,0};
    

    
// };


/// Usage :
// Button b; // Model
// Window w; // View 
// MouseCtr c; // Controller
//w.add( b ) // we added button to view now it is displayed
// so button gets displayed in its default state and it do not interact with user in any way

// b.attach(c) // we added button to controler 



// Lets assume now user moved mouse :
// Controller should keep checking if that happened.
// We can either do it in some sort of main loop or in different thread 
// which seems more flexible but harder to implement 

// Controller spots mouse movement accross window.
// Should button gets informed about that only if mouse lay on it or always ?? 
// According to wikipedia controller manipulates model. // imo it means it should tell 
// model to change state so logic which checks if that should happen should be inside controller
//  
// For ( button in Controller ) If Mouse intersects with button -> button.notify().
// But model should know what does intersects mean for him so it should be like
// bool button.intersects ( Mouse ) { return self.rect.intersects(mouseX ,mouseY ) }

// Button gets informed that there was movement and where mouse is
// c -> notify ( b ) 
// button logic : if mouse coordinates cross with mouse pointer we should redraw its
// frame in different color ( different buffer gets rendered )
//  // if also left mouse button is clicked a function ButtonClicked gets called and
// executed
//


