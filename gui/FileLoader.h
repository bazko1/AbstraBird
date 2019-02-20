#pragma once

#include <string>
#include <algorithm>

class FileLoader {

 private:
    std::string lastLoadedName;

    std::string GetStdoutFromCommand(std::string cmd) {
     
        std::string data;
        FILE * stream;
        const int max_buffer = 256;
        char buffer[max_buffer];
        cmd.append(" 2>/dev/null");
    
        stream = popen(cmd.c_str(), "r");
        if (stream) {
         
            while (!feof(stream))
                if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);

    
            pclose(stream);
    
        }

        return data;
    }
 
 
 
 public:

    std::string interactiveLoadName(){
    
        std::string filename = GetStdoutFromCommand("zenity --file-selection");

        //remove endline at the end of output or we won't load this file
        filename.erase(std::remove(filename.begin(), filename.end(), '\n'), filename.end());

        //TODO: Optionally: add some extension checking (name has to have .png/jpg/bmp/...)

        //SDL_Log("You choosed file %s" , filename.c_str() );

        lastLoadedName = filename;
    
        return filename;    

    };
 

    SDL_Texture* LoadImageAsTexture(SDL_Renderer* render) {

         SDL_Surface* bitmapSurface = IMG_Load( lastLoadedName.c_str() );
         SDL_Texture* texture = SDL_CreateTextureFromSurface( render , bitmapSurface  );
         SDL_FreeSurface(bitmapSurface);
         return texture;
    };
 
 




    
};
