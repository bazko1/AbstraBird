#pragma once
#include <SDL.h>
#include <algorithm>

class Subject;

class Observer {
    
  protected:
      Observer(){};
  public:
      virtual ~Observer(){};
      virtual void Update ( Subject* changed) = 0;
    

};


class Subject {

  public:
  
     virtual ~Subject(){};

     virtual void Attach (Observer * o  ) {
          
          if (  *std::find (Models.begin() , Models.end() , o ) != o )
          Models.push_back(o);
          
          
      }
  
      virtual void Detach ( Observer * m ) {
          Models.remove(m);
      }
  
      virtual void Notify() {
  
          for( Observer* m : Models ) {
              m->Update( this );
          }
      }


  protected:
    Subject(){};
  private:
    std::list <Observer*> Models;
  
};