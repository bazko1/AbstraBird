
#pragma once
#include "SDL.h"
#include "observer.h"
#include "GWindow.h"
#include <cmath>
#include "saveTexture.h"

class InteractiveRectGetter : public Observer {

    private:
      
        SDL::Rect mainRect;
        MouseController* mouse;
        GWindow* window;
        SDL_Renderer* renderer;
        SDL_Texture* mainImage = NULL;
        SDL_Rect prevPoint={-1,-1,0,0};
        SDL::Rect prevArea;
        int counter = 0;


    SDL_Texture* GetAreaTextrue(SDL_Rect rect, SDL_Renderer* renderer, SDL_Texture* source) {
        SDL_Texture* result = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);          
        SDL_SetRenderTarget(renderer, result);
        SDL_RenderCopy(renderer, source, &rect, NULL);
        // the folowing line should reset the target to default(the screen)
        SDL_SetRenderTarget(renderer, NULL);  
        // I also removed the RenderPresent funcion as it is not needed here      
        return result;
    }


    void redrawRect(const SDL::Rect* rect ) {

        if ( mainImage ) {
            
            int h2 = window->getHeight() - mainRect.h;
            SDL_Rect copy = { rect->x , rect->y-h2 , rect->w , rect->h  };

            SDL_Texture* area = GetAreaTextrue(copy,renderer,mainImage);
            
            SDL_RenderCopy( renderer, area, NULL , rect );
            
            
            // for testing migh be removed
            SDL_Rect test={0,0,100,100};
            SDL_RenderCopy( renderer, area, NULL , &test );
            

            SDL_Texture* toCopy = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, test.w, test.h);          
            SDL_SetRenderTarget(renderer, toCopy);
            
            SDL_Rect saving = {0,0,36,26};
            SDL_RenderCopyEx(renderer, area, NULL ,&test, 180, NULL, SDL_FLIP_HORIZONTAL);
            
            SDL_SetRenderTarget(renderer, NULL);  
            save_texture("mainGame/Pictures/bird.png",renderer,toCopy);
            
            SDL_DestroyTexture(toCopy);
            SDL_DestroyTexture(area);
        }
    }

    public:

        InteractiveRectGetter( SDL::Rect  pos ) {
                this->mainRect = pos;
                mouse = &MouseController::instance();
        }

        

        void AttachTo( GWindow* w) {
            
            w->Attach(this);
            this->window = w;
            this->renderer = window->getRenderer();
            
            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            SDL_RenderDrawRect( renderer ,  &mainRect );
            
        }

        void setTexture (SDL_Texture* texture) {
            
            //create texture with size of addon
            SDL_Texture* auxtexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, mainRect.w, mainRect.h);

            //change the rendering target
            SDL_SetTextureBlendMode(auxtexture, SDL_BLENDMODE_BLEND);
            SDL_SetRenderTarget(renderer, auxtexture);
            // Render texture to auxtexture
            SDL_RenderCopy( renderer , texture , NULL , NULL );
            // Back to default 
            SDL_SetRenderTarget(renderer, NULL); //NULL SETS TO DEFAULT
            
            this->mainImage = auxtexture;
            
            SDL_Rect CopyRect = {0,0,mainRect.w,mainRect.h};  
            
            SDL_RenderCopy( renderer , auxtexture , &CopyRect , &mainRect );
            
            SDL_DestroyTexture(texture);
            

        }

        void render() {

        }


        void Update (Subject* changed) {
            
            if ( window == changed ) {

                SDL_Rect pointer = {mouse->getX(),mouse->getY(),1,1};

                if ( SDL_HasIntersection ( &mainRect ,  &pointer ) ) {

                    if ( mouse->isClicked() && mainImage != NULL ) {

                        counter++;
                        SDL_Log("counter = %d" , counter);
                        
                        int w,h,x,y;
                        SDL::Rect area;

                        if ( counter == 2 || counter == 1) {
                            SDL_Rect Dot = {pointer.x,pointer.y,2,2};
                            SDL_SetRenderDrawColor(renderer,255,0,0,255);
                            SDL_RenderFillRect( renderer ,  &Dot );
                                    
                            w = std::abs(prevPoint.x - pointer.x)+1;
                            h = std::abs(prevPoint.y - pointer.y)+1;
                            x = std::min(prevPoint.x,pointer.x);
                            y = std::min( prevPoint.y, pointer.y );

                            area = SDL::Rect(x,y,w,h);
                        }

                        if (counter == 1) {
                            
                            prevPoint.x = pointer.x;
                            prevPoint.y = pointer.y;
                        }
                        
                        if ( counter == 2 ) {
                            
                            SDL_RenderDrawRect( renderer ,  &area );
                            prevArea=area;
                            
                        }
                        
                        if (counter == 3 ) {
                            //SDL_RenderDrawRect( renderer ,  &prevArea );
                            if ( prevPoint.x != -1)
                                this->redrawRect(&prevArea);
                            counter = 0;
                        }
                            
                    
                    }


                }


            }
            //this->render();
        }




};