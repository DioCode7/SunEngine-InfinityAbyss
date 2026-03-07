#include <iostream>
#include <SDL2/SDL.h>

#include <memory>
#include <iostream>
#include "SunEngineCore.h"
#include "SunManager.h"
#include "SunFunctions.h"

SDL_Event event;
Component* LastMouseInteraction = nullptr;
Component* LastMouseInteractionOut = nullptr;

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
        if(c->GetRenderDisplay() != DisplayType::None || !c->GetPointerEvents()){
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
    }
  

  
      
      
    };

     
void MouseMotionDispatch(SDL_Event& event,SunListener* Listener){

    int HightzIndex = 1;
     
     if(Listener->GetMouseEventType() == SDL_MOUSEMOTION){
        std::cout << "MousEmORIAJSDO";
            auto* c = Listener->Trigger.GetComponentTarget();
        if(c->GetRenderDisplay() != DisplayType::None || !c->GetPointerEvents()){
       float mouseX = event.motion.x;
    float mouseY = event.motion.y;
    float x = c->GetX().RenderValue;
    float y = c->GetY().RenderValue;
    float w = c->GetWidth().RenderValue;
    float h = c->GetHeight().RenderValue;

    if(mouseX > x && mouseX < x + w || (Listener->Trigger.GetMouseTriggerType() == MouseTriggersType::MouseOut && LastMouseInteractionOut == c)){
       if(mouseY > y && mouseY < y + h || (Listener->Trigger.GetMouseTriggerType() == MouseTriggersType::MouseOut && LastMouseInteractionOut == c)){
        if(Listener->Trigger.GetMouseTriggerType() == MouseTriggersType::MouseOn || 
        (Listener->Trigger.GetMouseTriggerType() == MouseTriggersType::MouseIn && LastMouseInteraction != c) ||
    (Listener->Trigger.GetMouseTriggerType() == MouseTriggersType::MouseOut && LastMouseInteractionOut == c)){
     
        if(Listener->UseFn){
            SunEvent Event;
            Listener->Fn(Event);
          }

       } 
    }
}
        }
    
}
    
    for(auto& comp : SunCore::instance().SunWorld.GetWorldComponentsMap()){
      auto* component = comp.second.get();
         if(component->GetRenderDisplay() != DisplayType::None || !component->GetPointerEvents()){
       float mouseX = event.motion.x;
    float mouseY = event.motion.y;
    float x = component->GetX().RenderValue;
    float y = component->GetY().RenderValue;
    float w = component->GetWidth().RenderValue;
    float h = component->GetHeight().RenderValue;
      if(mouseX > x && mouseX < x + w ){
       if(mouseY > y && mouseY < y + h ){
        if(component->GetzIndex() >= HightzIndex){
        if(component != LastMouseInteraction){
        LastMouseInteractionOut = LastMouseInteraction;
        }
        LastMouseInteraction = component;
        HightzIndex = component->GetzIndex();
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
   MouseMotionDispatch(event,Listener.second.get());
   
  
    


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