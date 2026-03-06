#include <iostream>
#include <SDL2/SDL.h>

#include <memory>
#include <iostream>
#include "SunEngineCore.h"
#include "SunManager.h"
#include "SunFunctions.h"

SDL_Event event;

void Dispatch(SDL_Event& event,SunListener* Listener){
    if(event.type == Listener->GetKeyboardEventType()){
    SDL_Keycode Key = event.key.keysym.sym;
          if(Key == Listener->GetSDLKey()){
          if(Listener->UseFn){
            SunEvent Event;
            Listener->Fn(Event);
          }
          }
        
    }
    };

    
void MouseDispatch(SDL_Event& event,SunListener* Listener){
     
     
    if(Listener->Trigger.GetMouseTriggerType() != MouseTriggersType::None && Listener->Trigger.GetMouseButtonCode() != MouseButtons::None){
    if(event.type == Listener->GetMouseEventType() && event.button.button == Listener->GetMouseButton() && 
    Listener->Trigger.GetComponentTarget()){
        auto c = Listener->Trigger.GetComponentTarget();
       float mouseX = event.button.x;
    float mouseY = event.button.y;
    float x = c->GetX().RenderValue;
    float y = c->GetY().RenderValue;
    float w = c->GetWidth().RenderValue;
    float h = c->GetHeight().RenderValue;

    if(mouseX > x && mouseX < x + w){
       if(mouseY > y && mouseY < y + h){
        
        if(Listener->UseFn){
            SunEvent Event;
            Listener->Fn(Event);
          }
       } 
    }

    }
    }
  

  
      
      
    };

void SunDispatchs(){

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) {
      SunCore::instance().ApplicationState = "Off";
    }
    

for(const auto& Listener : SunCore::instance().SunBrain.GetListeners()){
       Dispatch(event,Listener.second.get());   
   MouseDispatch(event,Listener.second.get());
  
    


    }
}
    
};

void SunUpdateInput(){

    const Uint8* state = SDL_GetKeyboardState(NULL);

    for(const auto& Listener : SunCore::instance().SunBrain.GetListeners()){

        if(Listener.second->Trigger.GetKeyBoardTriggerType() == KeyboardTriggersType::KeyHeld){

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