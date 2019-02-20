#include "controller.h"

void MouseController::update() {

         SDL_Event e;
            
        if (SDL_PollEvent(&e)) {
         
            switch (e.type) {
            
                case SDL_QUIT:
                        this->window->setFinished(true);
                        break;
            
            
                case SDL_MOUSEBUTTONDOWN:{
                        
                        SDL_MouseButtonEvent* b = &e.button;
                        
                        if(b->button == SDL_BUTTON_LEFT){
                                this->clicked = true;
                                
                        }
                        break;
                }
                default:
                        this->clicked = false;
                        break;
            }
        
        }

        Uint32 u = SDL_GetMouseState( &x, &y);
        
};

void MouseController::Update ( Subject* changed) {
        
        if ( window == changed ){
                this->update();
        }
    }

void MouseController::AttachTo ( GWindow* gwindow ) {

      gwindow->Attach(this);
      this->window = gwindow;
}


MouseController& MouseController::instance(){
        static MouseController single;
        return single;
}
