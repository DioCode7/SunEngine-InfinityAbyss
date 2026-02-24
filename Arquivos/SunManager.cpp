#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <memory>
#include <iostream>
#include "SunEngineCore.h"
#include "SunManager.h"
#include "SunFunctions.h"

SDL_Event event;

void Dispatch(SDL_Event& event,SunListener* Listener){
    SDL_Keycode Key = event.key.keysym.sym;
            if(Listener->Trigger.Type == TriggerType::KeyDown){
          if(Key == Listener->GetSDLKey()){
          if(Listener->UseFn){
            SunEvent Event;
            Listener->Fn(Event);
          }
          }
        }
      
    };

void SunDispatchs(){

    

    while(SDL_PollEvent(&event)){
for(const auto& Listener : SunCore::instance().SunBrain.GetListeners()){
    if(event.type == SDL_QUIT) {
      SunCore::instance().ApplicationState = "Off";
    }

    if(event.type == SDL_KEYDOWN){
       Dispatch(event,Listener.second.get());   
       SDL_Keycode Key = event.key.keysym.sym;
          if(Key == SDLK_F11){           
    WindowManipulate("LeaveFullScreen");
        }
    }
  
    


    }
}
    
};

void SunUpdateInput(){

    const Uint8* state = SDL_GetKeyboardState(NULL);

    for(const auto& Listener : SunCore::instance().SunBrain.GetListeners()){

        if(Listener.second->Trigger.Type == TriggerType::KeyHeld){

            if(state[Listener.second->GetSDLScanKey()]){

                if(Listener.second->UseFn){
                    SunEvent Event;
                    Listener.second->Fn(Event);
                }
            }
        }
    }
}

void SunListeners::AddListener(std::unique_ptr<SunListener> Listener){
    SunCore::instance().SunBrain.NewListener(std::move(Listener));
}