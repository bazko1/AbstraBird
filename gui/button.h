#pragma once
#include "SDL.h"
#include <string>
#include <sstream>
#include <ctype.h>
#include <map>
#include <memory>
#include <iostream>
#include "controller.h"
#include "bindings.h"
#include "font.h"
#include "GWindow.h"
#include "observer.h"

class RenderStrategy;
class DefaultStrategy;


template <typename T=MouseController,typename S=DefaultStrategy>
class Button : public Observer {
 private:
    
    enum ButtState { PASSIVE , ACTIVE  };

    T* mouse;
    ButtState prevState = ButtState::ACTIVE;
    ButtState currState = ButtState::PASSIVE;
    GWindow* window;
    std::unique_ptr<S> strategy = NULL;

    SDL_Renderer* renderer;

    std::string text="clickme";
    const char* font="/home/bazyli/Pictures/numbers/Files/Flappy/";
    FontRenderer Fr;
    
    SDL::Rect mainRect;
    SDL::Rect textRect;
    
    SDL::Color frameColor = SDL::Color(255,255,255,255);
    SDL::Color fillColor = SDL::Color(255,0,0,255);
    SDL::Color onClickColor = SDL::Color(0,0,0,255);
    SDL::Color textColor = SDL::Color (0,0,255,255);

    void (*fn)()=[](){};

 
 public:

    
   
    Button( int x , int y , int w , int h ,int offSet=10 ) : mainRect(x,y,w,h) ,
      textRect ( x + offSet , y + offSet , w - 2*offSet , h - 2*offSet  ) {

         mouse = &T::instance();
      };

   

   ~Button (){};
   //getters  // it what if button is draw not as rectangle but as bitmap then we do not need those colors but instead we have bitmaps
   const FontRenderer& getFontRenderer() const { return Fr; }
   const SDL::Rect& getMainRect() const { return mainRect;  }
   const SDL::Rect& getTextRect() const { return textRect;  }
   const SDL::Color&  getFrameColor() const { return frameColor; }
   const SDL::Color& getFillColor() const {return fillColor; }
   const SDL::Color& getOnClickColor() const {return onClickColor; }
   const SDL::Color& getTextColor() const {return textColor;}
   const std::string& getText () const { return text; }
   
   void setText( std::string txt) {this->text = txt; }

   void setFn( void (*fn)() ){
      this->fn = fn;
   }

   

   void AttachTo ( GWindow* gwindow ) {

      if ( mouse )
         mouse->AttachTo(gwindow);

      gwindow->Attach(this);
      this->window = gwindow;
      renderer = gwindow->getRenderer();
      Fr = FontRenderer(font,renderer);
      this->render();
   }
    
    void render() {
       
       if ( !strategy )
         strategy = std::make_unique<S>(this); 
       
       strategy->render();
       
       prevState = currState; 

    }
    
   void Update (Subject* changed) {

      if ( window == changed ) {

         int x = mouse->getX()  , y = mouse->getY();
         SDL::Rect pointer = SDL::Rect(x,y,1,1);
         
         if ( SDL_HasIntersection ( &mainRect ,  &pointer ) ) {

               currState = ButtState::ACTIVE;

               if( mouse->isClicked() ) {
                  // call function;
                  fn();

               }
               
         }
         else {
            
            currState = ButtState::PASSIVE;
            
        }

         this->render();
      } 
   
   }
   


   friend S;
};


class RenderStrategy {
   
   public:
       virtual void render() = 0;
};


//A strategy in which button in rendered as SDL_Rect // and when mouse is on it it partially changes color
class DefaultStrategy : public RenderStrategy {

      Button<MouseController,DefaultStrategy>* b;
      public:
      
      DefaultStrategy(Button<MouseController,DefaultStrategy>* b):b(b){}
      
      void render() {

         if ( b->prevState == b->currState) return;

         // draw inside 
         if (b->currState == b->ButtState::ACTIVE )
            SDL::SetRenderDrawColor(b->renderer,b->onClickColor);
         else 
            SDL::SetRenderDrawColor(b->renderer,b->fillColor);
         
         SDL_RenderFillRect( b->renderer ,  &b->mainRect );

         //draw frame
         SDL::SetRenderDrawColor(b->renderer,b->frameColor);
         SDL_RenderDrawRect( b->renderer ,  &b->mainRect );

         if (b->currState == b->ButtState::ACTIVE ) {
         SDL::SetRenderDrawColor(b->renderer,b->fillColor);
         SDL_RenderFillRect( b->renderer ,  &b->textRect );
         
         }

         //draw text
         b->Fr.render(b->text , b->textRect ,b->textColor);
         
        // b->prevState = b->currState; 

    }

};

#include <climits>
//Duck typing ?
class S2 : RenderStrategy {
   
   Button<MouseController,S2>* b;
   
   public:
   S2(Button<MouseController,S2>* b) : b(b){}
   
   void render() {
      char* s1 = "clicked";
      char* s2 = "not clicked";
      char* state = b->currState == b->ButtState::ACTIVE ? s1 : s2;
      SDL_Log("Im'a %s button",state); 
         
   };

};