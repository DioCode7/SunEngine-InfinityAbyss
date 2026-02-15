#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include "SunEngineCore.h"
#include "SunManager.h"
#include "SunFunctions.h"

SDL_Event event;

void SunDispatchs(){

    while(SDL_PollEvent(&event)){

    if (event.type == SDL_QUIT) {
      SunCore::instance().ApplicationState = "Off";
    }

    if (event.type == SDL_KEYDOWN){
        SDL_Keycode Key = event.key.keysym.sym;

        if(Key == SDLK_F11){
            WindowManipulate("LeaveFullScreen");
        }
    }


    }
    
}