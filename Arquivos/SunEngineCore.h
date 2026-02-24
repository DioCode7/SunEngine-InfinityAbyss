#pragma once
#include <string>
#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>
#include <SDL2/SDL.h>

class SunCore;



class ShaderLocationsClass{
  public:
   GLint uPosLoc;
  GLint uSizeLoc;
  GLint uColorLoc;
  GLint uShapeType;
  GLint uUseTexture;
  GLint uTexture;
  GLint uFlipY;
  GLint uFlipX;
};

struct SunCoreData {
    unsigned int VAO;
    unsigned int VBO;
    unsigned int ShaderProgram;
    ShaderLocationsClass UniformsLocations;

};

class SunEvent{
  public:
  virtual ~SunEvent() = default;
};

enum class TriggerType{
KeyDown,
KeyUp,
KeyHeld,
PointerDown,
PointerUp,
};

enum class KeyCodes{
 A,
 D,
 W,
 S,
};

SDL_Keycode TranslateSDLKey(KeyCodes Key);
SDL_Scancode TranslateSDLScan(KeyCodes Key);

class SunEventTrigger{
  public:
 TriggerType Type;
 KeyCodes Key;
};

class SunListener{
  private:
    SDL_Keycode SDLTrigger;
    SDL_Scancode SDLScanTrigger;
  public:
std::string Id;
SunEventTrigger Trigger;
bool Enable = true;
bool UseFn = false;
std::function<void(SunEvent&)> Fn;
void SetSDLKey(SDL_Keycode Key){
SDLTrigger = Key;
};
SDL_Keycode GetSDLKey(){
return SDLTrigger;
};
void SetSDLScanKey(SDL_Scancode Key){
SDLScanTrigger = Key;
};
SDL_Scancode GetSDLScanKey(){
return SDLScanTrigger;
};
};



enum class SceneState{
  OnLoad,
  OnInit,
  OnUpdate
};
enum class UnitType{
Percent,Pixel
};
class UnitClass{
   public:
UnitType Unit;
float Value;
float ValueResolved;
};

class Component;
class NodeClass{
  public:
  NodeClass(){};
 Component* ComponentClass;
 NodeClass* Parent = nullptr;
 
 std::vector<NodeClass*> Childrens;
 std::vector<Component*> Components;

 void AddChild(NodeClass* Node){
  Childrens.push_back(Node);
 };
 
 void AddComponent(Component* Node){
  Components.push_back(Node);
 }
};


enum class OriginClass{
Start,
Center,
End

};

class RGBAClass{
  public:
  RGBAClass(float r,float g,float b,float a):R(r),G(g),B(b),A(a){}
  float R,G,B,A;
};






class Scene{

    public:
    std::string SceneID;
    SceneState State;
  virtual void SceneConfigs();
  virtual void OnLoad();
  virtual void OnInit();
  virtual void OnUpdate();
   virtual ~Scene() = default;

};





class RenderComponentClass{
    public:
    float Width;
  float Height;
  float X;
    float Y;
    float R;
float G;
float B;
float A;
Component* OriginalComponent;
OriginClass OriginX,OriginY;
std::string TextureId;

    Scene* OwnerScene;
    std::string Id;
       RenderComponentClass(int PosX,int PosY,int W,int H, float R,float G,float B,float A,std::string Id,Scene* OwnerScene,
      std::string TextureId = "None"):
      X(PosX),Y(PosY),Width(W),Height(H),R(R),G(G),B(B),A(A),Id(Id),OwnerScene(OwnerScene),TextureId(TextureId){}
 
       
   virtual void RenderMethod(float X,float Y,float W,float H,float R,float G,float B,float A,std::string Texture = "None") =0;

};

class SunEngineConfig{
      public:
        class MainWindow{
            public:
            std::string WindowName;
        };
        class SunScenes{
            public:
        std::vector<Scene*> Scenes;
        
        };
        class RenderList{
            public:
            std::vector<RenderComponentClass*> RenderVector;
            
        };

        RenderList Render;
        MainWindow Window;
        SunScenes SunScenes;
        Scene SceneClass;
};

class Texture{
    public:
    std::string Id;
    GLuint GPUID;
    int Width;
    int Height;

  
};

class RenderCore{
    public:
    std::unordered_map<std::string,Texture> Textures;
    Texture* GetTexture(std::string Id){
      auto it = Textures.find(Id);
      if(it != Textures.end()){
        return &it->second;
      }
      return nullptr;
    }
    std::unordered_map<std::string,std::unique_ptr<RenderComponentClass>> Sprites;
    void AddTexture(const std::string& Id,const Texture& Tex){
      if(Textures.count(Id)){
        std::cout << "Texture Ja Existe";
      } 
      else{
        Textures.emplace(Id,Tex);
      }
    }
    
};
class SunBrain{
  private:
  std::unordered_map<std::string,std::unique_ptr<SunListener>> Listeners;
public:
void NewListener(std::unique_ptr<SunListener> Listener){
  auto Id = Listener.get()->Id;
  Listener->SetSDLKey(TranslateSDLKey(Listener->Trigger.Key));
   Listener->SetSDLScanKey(TranslateSDLScan(Listener->Trigger.Key));
 Listeners.emplace(Id,std::move(Listener));
};
void DeleteListener(std::string Id){
 Listeners.erase(Id);
}
void DisableListener(std::string Id){
  auto It = Listeners.find(Id);
  if(It != Listeners.end()){
 Listeners[Id]->Enable = false;
  }
};
void EnableListener(std::string Id){
auto It = Listeners.find(Id);
  if(It != Listeners.end()){
 Listeners[Id]->Enable = true;
  }
};
void UpdateListener(std::string Id,std::unique_ptr<SunListener> Listener){
 auto It = Listeners.find(Id);
  if(It != Listeners.end()){
  It->second = std::move(Listener);
  }
}
const std::unordered_map<std::string,std::unique_ptr<SunListener>>& GetListeners()const{
   return Listeners;
}
};

class SunCore {
    private:
    SunCore() {};
    public:
    std::string ApplicationState;
    SDL_Window* window;
    int WindowWidth;
    int WindowHeight;
    SDL_GLContext GlContext;
    std::unordered_map<std::string,Scene*> ScenesDiagrams;
    SunEngineConfig* SunEngineConfig;
    SunCoreData Gl;
    RenderCore SunRenderCore;
    SunBrain SunBrain;
    

    static SunCore& instance(){
        static SunCore instance;
        return instance;
    }
};


class Component{
  public:

  
void ResolveComponent(){
  if(!Dirty) return;
Component* Parent = nullptr;
if (Owner && Owner->Parent) {
    Parent = Owner->Parent->ComponentClass;
}


 switch(Width.Unit){
  case UnitType::Pixel:
  Width.ValueResolved = Width.Value;
  break;
  case UnitType::Percent:
  float ParentWidth = SunCore::instance().WindowWidth;
  if(Parent){
  ParentWidth = Parent->Width.ValueResolved;
  }
 Width.ValueResolved = ParentWidth * Width.Value;
 std::cout << "Resolve Width   ";
  
  
  break;
 }
 switch(Height.Unit){
  case UnitType::Pixel:
  Height.ValueResolved = Height.Value;
  break;
  case UnitType::Percent:
  float ParentHeight = SunCore::instance().WindowHeight;
  if(Parent){
  ParentHeight = Parent->Height.ValueResolved;
  }
  Height.ValueResolved = ParentHeight * Height.Value;
   std::cout << "Resolve height  ";
  break;
 }
 switch(PosX.Unit){
  case UnitType::Pixel:
   if(Parent){
  float RelativeX = PosX.Value; // começa do valor local

NodeClass* ActualNode = Owner->Parent;

while (ActualNode) {
    RelativeX += ActualNode->ComponentClass->PosX.ValueResolved;
    std::cout << "RelativeX: ";
    std::cout << RelativeX;
    ActualNode = ActualNode->Parent;
}

PosX.ValueResolved = RelativeX;
  
  }else{
  PosX.ValueResolved = PosX.Value;
  }
  break;
  case UnitType::Percent:
  float ParentWidth = SunCore::instance().WindowWidth;
  if(Parent){
   ParentWidth = Parent->Width.ValueResolved + Parent->PosX.ValueResolved;
  }
   PosX.ValueResolved = ParentWidth * PosX.Value;
    std::cout << "Resolve XXXXXXX   ";
  break;
 }
  switch(PosY.Unit){
  case UnitType::Pixel:
   if(Parent){
    float RelativeY = 0.0f;
    NodeClass* ActualNode;
    bool WhileFlag = true;
    ActualNode = Owner;
  while(WhileFlag){
  RelativeY += ActualNode->ComponentClass->PosY.ValueResolved;
  if(!ActualNode->Parent){
  WhileFlag = false;
  }else{
  ActualNode = ActualNode->Parent;
  }
  }
   PosY.ValueResolved = RelativeY;
  }else{
 PosY.ValueResolved = PosY.Value;
  }
  break;
  case UnitType::Percent:
  float ParentHeight = SunCore::instance().WindowHeight;
  if(Parent){
   ParentHeight = Parent->Height.ValueResolved + Parent->PosY.ValueResolved;
  }
   PosY.ValueResolved = ParentHeight * PosY.Value;
  break;
 }
 UpdateRC();
 Dirty = false;

};

 void UpdateRC(){
   if(!RenderComponent) return;
  RenderComponent->Height = Height.ValueResolved;
  RenderComponent->Width = Width.ValueResolved;
  RenderComponent->OriginX = OriginX;
  RenderComponent->OriginY = OriginY;
  RenderComponent->X = PosX.ValueResolved;
  RenderComponent->Y = PosY.ValueResolved;
 };

  Component(std::string Id,UnitClass W,UnitClass H,UnitClass X,
    UnitClass Y, OriginClass OriginX  = OriginClass::Center, OriginClass OriginY = OriginClass::Center):
    Id(Id),Width(W),Height(H),PosX(X),PosY(Y),OriginX(OriginX),OriginY(OriginY),RGBA(std::make_unique<RGBAClass>(1.0f,1.0f,1.0f,1.0f)){}

  UnitClass GetX(){
    return PosX;
  };
  
  UnitClass GetY(){
    return PosY;
  };

  
  UnitClass GetWidth(){
    return Width;
  };

  
  UnitClass GetHeight(){
    return Height;
  };

  
  std::string GetId(){
    return Id;
  };

  
  std::string GetTexture(){
    return Texture;
  };
  
  NodeClass* GetOwner(){
    return Owner;
  };

  
  RGBAClass* GetRGBA(){
    return RGBA.get();
  };

  
  OriginClass GetOriginX(){
    return OriginX;
  };

   OriginClass GetOriginY(){
    return OriginY;
  };


   void SetY(UnitClass Value){
    this->PosY = Value;
    this->Dirty = true;
   };
   void SetX(UnitClass Value){
    this->PosX = Value;
    this->Dirty = true;
   };
    void SetTexture(std::string Value){
    this->Texture = Value;
    this->Dirty = true;
   };
    void SetOriginX(OriginClass Value){
    this->OriginX = Value;
    this->Dirty = true;

   };
     void SetOriginY(OriginClass Value){
    this->OriginY = Value;
    this->Dirty = true;

   };

     void SetRGBA(float r, float g, float b, float a) {
    RGBA->R = r;
    RGBA->G = g;
    RGBA->B = b;
    RGBA->A = a;
    Dirty = true;
}
    void SetOwner(NodeClass* Value){
    this->Owner = Value;
    this->Dirty = true;

   };
     void SetWidth(UnitClass Value){
    this->Width = Value;
    this->Dirty = true;

   };
     void SetHeight(UnitClass Value){
    this->Height = Value;
    this->Dirty = true;

   };

   void SetRenderComponent(RenderComponentClass* RC){
  RenderComponent = RC;
   };
  private:
  std::string Id;
  std::string Texture;
   UnitClass Width;
   UnitClass Height;
   UnitClass PosX;
   UnitClass PosY;
   OriginClass OriginX;
   OriginClass OriginY;
   NodeClass* Owner = nullptr;
   RenderComponentClass* RenderComponent = nullptr;
 std::unique_ptr<RGBAClass> RGBA;
   bool Dirty = false;

  
  
   

  

};

