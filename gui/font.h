#pragma once

#include <utility>
#include "bindings.h"
#include <memory>
#include <string>

// Class to load all letters stored in folder as png (loadable by IMG_Load) files.
//Each letter has to be in separate file named : uppercaseLetter.extension
// example : A.png
//
//const char* dirPath ="/home/bazyli/Pictures/numbers/Files/letters/";
//const char* ext = "png";
//

struct Letter {

    Letter(unsigned int w, unsigned int h) : w(w),h(h){};

    unsigned int w;
    unsigned int h;

};

class FontLoader {
   
   // key - letter , value - Surface 
  
  private:
   std::map <char , SDL_Surface* > letterSurface;
   std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
  public:
  
  FontLoader( const char* dirPath , const char* ext ) {
  

      for (char c : alphabet) {
      
         std::stringstream filePath;
         
         filePath<< dirPath
         << char( toupper(c) )
         <<"."<<ext;
         
         SDL_Surface* bitmapSurface = IMG_Load(filePath.str().c_str());
         
         letterSurface[ c ] = bitmapSurface;

      }
  }

 SDL_Surface* getLetterSurface(char c) {

     // TODO: for now i assume we have only one type of letters 
      //stored in dict as lower.

     if ( isupper(c) )
        c = tolower(c);

      return letterSurface [ c ];

  }


};

class FontRenderer {

  private:
    
    FontLoader Fl;
    std::map <char , SDL_Texture* > letterSurface;

  public:
  

  FontRenderer(const char* dirPath , const char* ext="png") : Fl (dirPath,ext) {

      Fl = FontLoader(dirPath,ext);

  }
  
  bool render( char c , SDL::Rect dstRect , SDL_Renderer* renderer ) {

      SDL_Surface* bitmapSurface = Fl.getLetterSurface (c);
      SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer , bitmapSurface  );

      SDL_RenderCopy( renderer , texture , 
      std::make_unique<SDL::Rect>( 0,0,bitmapSurface->w,bitmapSurface->h ).get()  ,
      std::make_unique<SDL::Rect>( dstRect ).get()
      );
 }


  bool render ( std::string chars , SDL::Rect dstRect , SDL_Renderer* renderer ) {

        double fullW = dstRect.w - chars.size();
        int letterW = fullW / chars.size();

        for (int i = 0 ; i < chars.size() ; i++ ) {
          render( chars[i] , SDL::Rect ( dstRect.x + i * (letterW + 1)
           , dstRect.y , letterW , dstRect.h ) , renderer ) ;
        }

  }


};
