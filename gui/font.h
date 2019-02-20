#pragma once
#include <SDL_image.h>
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


class FontLoader {
   
   // key - letter , value - Surface 
  // TODO: make it lazy object construction , renderer doesnt have to be given instantly 
  // could be given at get letter texture and at this moment it is created 
  private:
   std::map <char , SDL_Texture* > letterTexture;
   std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
  public:
  
  FontLoader(){}
  
  FontLoader( const char* dirPath , const char* ext , SDL_Renderer* render ) {
  

      for (char c : alphabet) {
      
         std::stringstream filePath;
         
         filePath<< dirPath
         << char( toupper(c) )
         <<"."<<ext;
         
         SDL_Surface* bitmapSurface = IMG_Load(filePath.str().c_str());
         SDL_Texture* texture = SDL_CreateTextureFromSurface( render , bitmapSurface  );
         SDL_FreeSurface(bitmapSurface);
         
         letterTexture[ c ] = texture;

      }
  }

  SDL_Texture* getLetterTexture(char c) const {

     // TODO: for now i assume we have only one type of letters 
      //stored in dict as lower.

     if ( isupper(c) )
        c = tolower(c);

     if ( !hasThisChar(c) )
        return NULL;

      return letterTexture.at(c);//letterSurface [ c ];

  }

  bool hasThisChar(char c) const{

    return letterTexture.find(c) != letterTexture.end();
    
  }


};

class FontRenderer {

  private:
    
    FontLoader Fl;
    SDL_Renderer * renderer;
    //std::map <char , SDL_Texture* > letterSurface;

  public:
  
  FontRenderer(){}

  FontRenderer(const char* dirPath , SDL_Renderer* r , const char* ext="png") : Fl (dirPath,ext,r),renderer(r) 
  {  }
  
  bool render( char c , SDL::Rect dstRect , SDL::Color color ) const {
      
      SDL_Texture* texture = Fl.getLetterTexture(c);
      
      if (!texture)
          return false;

      int w,h;
      SDL_QueryTexture(texture, NULL, NULL, &w, &h);
      
      SDL::SetTextureColorMod(texture,color);

      SDL_Rect CopyRect = {0,0,w,h};

      SDL_RenderCopy( renderer , texture , &CopyRect , &dstRect );
      
      return true;

 }

//TODO: change to std::string_view 

  bool render ( std::string chars , SDL::Rect dstRect , SDL::Color color ) const {

        double fullW = dstRect.w - chars.size();
        int letterW = fullW / chars.size();

        for (int i = 0 ; i < chars.size() ; i++ ) {
          render( chars[i] , SDL::Rect ( dstRect.x + i * (letterW + 1)
           , dstRect.y , letterW , dstRect.h ) , color ) ;
        }

  }


};
