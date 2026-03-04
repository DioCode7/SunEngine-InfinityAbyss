#pragma once
#include <ft2build.h>
#include FT_FREETYPE_H
#include <string>
#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>
#include <SDL2/SDL.h>
#include <GL/glew.h>


#include <chrono>


class SunCore;


struct vector2{
  float x = 0.0f;
  float y = 0.0f;
};


struct vector3{
  float x = 0.0f;
  float y = 0.0f;
  float z = 0.0f;
};


struct vector4{
  float x = 0.0f;
  float y = 0.0f;
  float z = 0.0f;
  float xy = 0.0f;
};




enum class Align{
  Start,
  Center,
  End,
  None
};


struct Character{
 vector2 Size;
 vector2 Bearing;
 unsigned int Advance;
 vector2 UvMin;
 vector2 UvMax;
};


class SunFont{
  private:
  std::unordered_map<char,Character> Characters;
  public:
  GLuint AtlasTexture;
  void AddToCaracters(char c,Character chra){
      Characters.emplace(c,chra);
  };
  Character GetCharacter(char ch){
   if(Characters.find(ch) != Characters.end()){
   return Characters.find(ch)->second;
   }else{
    Character c;
    return c;
   }
  };
  std::string Id;
  int Height;
  const char* FontPath;
  FT_Face Face;



};

enum class UniformType{
 OneFloat,
 TwoFLoat,
 ThreeFloat,
 FourFloat,
 Texture2D,
 OneInt,

};

class ShaderUniform{
 public:
 UniformType Type;
 GLint Location;
 int IntValue;
 int FloatValue;
 vector2 TwoFloatValue;
  
 
};

enum class SunUniformsTypes{
uSunPos,
uSunSize,
uSunProjection,
uSunTexture,
uSunTime,
uSunTextureMask,
};



class SunShader{
  private:
    GLuint ShaderProgram;
    unsigned int VAO;
    unsigned int VBO;
   std::unordered_map<std::string,std::unique_ptr<ShaderUniform>> Uniforms;
   std::unordered_map<SunUniformsTypes,GLint> SunUniforms;
  public:
 
  void SetShaderProgram(GLuint sp){
  ShaderProgram = sp;
  };
  unsigned int GetShaderProgram(){
   return ShaderProgram;
  };

  unsigned int GetVAO()const{
  return VAO;
  };

  unsigned int GetVBO()const{
  return VBO;
  };

  void SetVBO(unsigned int vbo){
   VBO = vbo;
  };

  void SetVAO(unsigned int vao){
   VAO = vao;
  };

   void AddUniform(const char* Id,std::unique_ptr<ShaderUniform> U){
    U->Location = glGetUniformLocation(ShaderProgram,Id);
        std::cout << "\n SunUniforms:  " << "SunPos:  " << U->Location << "\n";
     Uniforms.emplace(Id,std::move(U));

   };

   void AddSunUniform(SunUniformsTypes su,GLint loc){
        SunUniforms.emplace(su,loc);
   };

     const std::unordered_map<SunUniformsTypes,GLint>& GetSunUniforms() const {
    return SunUniforms;
     };


   ShaderUniform* GetUniform(std::string Id){
   auto it = Uniforms.find(Id);
   if(it != Uniforms.end()){
    return it->second.get();
   }
   return nullptr;
   }
   
};


class SunShadersCore{
private:
  std::unordered_map<std::string,std::unique_ptr<SunShader>> Shaders;
public:
    
   void AddShaderToWorld(std::string Id,std::unique_ptr<SunShader> s);
   
   SunShader* GetShader(std::string Id){
   auto it = Shaders.find(Id);
   if(it != Shaders.end()){
    return it->second.get();
   }
   return nullptr;
   }
   
};

enum class ComponentType{
  Text,
  Rectangle,
  Circle,
  Sprite
};

class SunFonts{
private:
std::unordered_map<std::string,std::unique_ptr<SunFont>> Fonts;
public:
void AddFontToWorld(std::string Id,std::unique_ptr<SunFont> Font){
  Fonts.emplace(Id,std::move(Font));
};
SunFont* GetFont(std::string Id){
 if(Fonts.find(Id) != Fonts.end()){
   return Fonts.find(Id)->second.get();
 }
return nullptr;
};

};


class SunTime{
private:
float DeltaTime = 0.0f;
using Clock = std::chrono::high_resolution_clock;
std::chrono::time_point<Clock> LastFrame;
float Time = 0.0f;
std::chrono::time_point<Clock> InitTime;

public:
SunTime(){
  LastFrame = Clock::now();
  InitTime = Clock::now();
};
float GetTime(){
return Time;
};
void TimeUpdate(){
auto Now = Clock::now();
std::chrono::duration<float> Elapsed = Now - LastFrame;
DeltaTime = Elapsed.count();
LastFrame = Now;

std::chrono::duration<float> Elapsed2 = InitTime - Now;
Time = Elapsed2.count();

};
float GetDeltaTime()const{
  return DeltaTime;
};

};

enum class CollisionPhysicTypes{
  Arcade,
  SunPhysic,
};


class ShaderLocationsClass{
  public:
   GLint uPosLoc;
  GLint uSizeLoc;
  GLint uColorLoc;
  GLint uShapeType;
  GLint uUseTexture;
  GLint uTexture;
  GLint uFlipY;
  GLint uBorderWidth;
    GLint uBorderColor;
  GLint uFlipX;
};

class TextShaderLocationsClass{
  public:
  GLint uTexture;
  GLint uColor;
  GLint uSize;
  GLint ProjectionMatrix;
  GLint uPos;
};

struct SunCoreData {
    unsigned int VAO;
     unsigned int TextVAO;
    unsigned int VBO;
    unsigned int TextVBO; 
    unsigned int ShaderProgram;
    ShaderLocationsClass UniformsLocations;
    TextShaderLocationsClass TextUniformsLocations;
    unsigned int TextShader;
   
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
UnitType Unit = UnitType::Pixel;
float Value = 0.0f;
float ValuePixel = 0.0f;
float ValueResolved = 0.0f;
float RenderValue = 0.0f;
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


class CollisionLayer{

private:
  std::unordered_map<std::string,CollisionLayer*> CollidesWith; 
public:
  std::string Id;

  const std::unordered_map<std::string,CollisionLayer*>& GetCollidesWith()const{
   return  CollidesWith;
   };

   void AddCollision(CollisionLayer* CL){
     CollidesWith.emplace(CL->Id,CL);
   };



};

class Material;


class RenderComponentClass{
    public:
    float Width;
  float Height;
  std::string Font = "None";
  std::string Text = "None";
  float X;
    float Y;
    float R; 
float G;
float B;
float A;
float BorderColorR,BorderColorG,BorderColorB,BorderColorA = 1.0f;
float BorderWidth = 0.0f;
Material* Material = nullptr;

vector2 CharactersMargin;
Align TextAlignX;
Align TextAlignY;
Component* OriginalComponent;
OriginClass OriginX,OriginY;
std::string TextureId;
std::string TextureMask = "None";
bool IsText = false;
    Scene* OwnerScene;
    std::string Id;
       RenderComponentClass(int PosX,int PosY,int W,int H, float R,float G,float B,float A,std::string Id,Scene* OwnerScene,
      std::string TextureId = "None",std::string FontId = "None",std::string Text = "None"):
      X(PosX),Y(PosY),Width(W),Height(H),R(R),G(G),B(B),A(A),Id(Id),OwnerScene(OwnerScene),TextureId(TextureId),Font(FontId),
      Text(Text){}

 
       
   virtual void RenderMethod() =0;
  

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
        bool BodysDebug = false; 
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

enum class BlendOptions{
None,
Alpha,
Add,
};


class Material{
  private:
  std::unordered_map<std::string,float> FloatUniforms;
std::unordered_map<std::string,vector2> TwoFloatsUniforms;
std::unordered_map<std::string,vector3> ThreeFloatUniforms;
std::unordered_map<std::string,vector4> FourFloatUniforms;
std::unordered_map<std::string,Texture*> TexturesUniforms;

  public:
 SunShader* Shader = nullptr;
 BlendOptions BlendMode =BlendOptions::Alpha;
 void AddTextureUniform(std::string Id,std::string TextureId);
 void AddFloatUniform(std::string Id,float f){
  FloatUniforms.emplace(Id,f);
 };
 void AddTwoFloatsUniform(std::string Id,float x,float y){
  vector2 v2;
  v2.x = x;
  v2.y = y;
  TwoFloatsUniforms.emplace(Id,v2);
 };
  void AddThreeFloatsUniform(std::string Id,float x,float y,float z){
  vector3 v3;
  v3.x = x;
  v3.y = y;
  v3.z = z;
  ThreeFloatUniforms.emplace(Id,v3);
 };
   void AddFourFloatsUniform(std::string Id,float x,float y,float z,float xy){
  vector4 v4;
  v4.x = x;
  v4.y = y;
  v4.z = z;
  v4.xy = xy;
  FourFloatUniforms.emplace(Id,v4);
 };
 const std::unordered_map<std::string,Texture*>& GetTexturesUniforms()const{
   return TexturesUniforms;
 };
 const std::unordered_map<std::string,vector4>& GetFourFloatsUniforms()const{
   return FourFloatUniforms;
 };
  const std::unordered_map<std::string,vector3>& GetThreeFloatsUniforms()const{
   return ThreeFloatUniforms;
 };
  const std::unordered_map<std::string,vector2>& GetTwoFloatsUniforms()const{
   return TwoFloatsUniforms;
 };
  const std::unordered_map<std::string,float>& GetFloatsUniforms()const{
   return FloatUniforms;
 };




 void Apply(RenderComponentClass* rc,float t,float dt);
 
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



class SunBodys;

struct WorldGridCell{

   int x;
    int y;

    bool operator==(const WorldGridCell& other) const {
        return x == other.x && y == other.y;
    }
};

struct WorldGridHash{
    std::size_t operator()(const WorldGridCell& k) const {
        return std::hash<int>()(k.x) ^ (std::hash<int>()(k.y) << 1);
    }
};

enum class CollisionsTypes{
None,
Solid,
Trigger,
};


class Body;


class BodyArcadePhysic{
  private:
  float Mass = 1.0f;
  bool DynamicMovement = true;
  vector2 Velocity;
  vector2 AccumulatedForces;
  Body* Owner = nullptr;


  public:

  const Body* GetOwner() const{
   return Owner;
  };

  void SetOwner(Body* bd){
   Owner = bd;
  };

  void SetVelocity(vector2 v){
  Velocity = v;
  };

  void SetMass(float v){
   Mass = v;
  };

  void SetDynamicMovement(bool b){
   DynamicMovement = b;
  };
  float GetMass(){
    return Mass;
  }
  bool GetDynamicMovement(){
    return DynamicMovement;
  }
  vector2 GetAccumulatedForces(){
  return AccumulatedForces;
  }
  vector2 GetVelocity(){
    return Velocity;
  };
  void AddForce(vector2 m){
    AccumulatedForces.x += m.x;
    AccumulatedForces.y += m.y;
  };

  void PhysicResolve(float DeltaTime);

  void CollisionAtrict();

};


class BodySunPhysic{
  private:
  float Mass = 1.0f;
  bool DynamicMovement = true;
  vector2 Velocity;
  vector2 AccumulatedForces;
  Body* Owner = nullptr;


  public:

  const Body* GetOwner() const{
   return Owner;
  };

  void SetOwner(Body* bd){
   Owner = bd;
  };

  void SetVelocity(vector2 v){
  Velocity = v;
  };

  void SetMass(float v){
   Mass = v;
  };

  void SetDynamicMovement(bool b){
   DynamicMovement = b;
  };
  float GetMass(){
    return Mass;
  }
  bool GetDynamicMovement(){
    return DynamicMovement;
  }
  vector2 GetAccumulatedForces(){
  return AccumulatedForces;
  }
  vector2 GetVelocity(){
    return Velocity;
  };
  void SetAccumulatedForce(vector2 ac){
   AccumulatedForces = ac;
  };
  void AddForce(vector2 m){
    AccumulatedForces.x += m.x;
    AccumulatedForces.y += m.y;
  };

  void PhysicResolve(float DeltaTime);

  void CollisionAtrict();

};



class Body{
  private:
   std::unique_ptr<Component> BodyComponent = nullptr;
   CollisionLayer* BodyCollisionLayer = nullptr;
   using bap = std::unique_ptr<BodyArcadePhysic>;
   using sunph = std::unique_ptr<BodySunPhysic>;
   sunph SunPhysic = nullptr;
   bap ArcadePhysic = nullptr;
 public:
std::string Id;
float Width,Height,OffsetX = 0.0f,OffsetY = 0.0f,WorldX = OffsetX,WorldY = OffsetY;
WorldGridCell WorldGridCell;
bool Collides = true;

 BodyArcadePhysic* GetBodyArcadePhysics()const{
 return ArcadePhysic.get();
};

 BodySunPhysic* GetBodySunPhysics()const{
 return SunPhysic.get();
};

void SetBodyArcadePhysic(bap ap){
 ArcadePhysic = std::move(ap);
 ArcadePhysic->SetOwner(this);
};

void SetBodySunPhysic(sunph ap){
 SunPhysic = std::move(ap);
 SunPhysic->SetOwner(this);
};
CollisionsTypes CollissionType =CollisionsTypes::Solid;

CollisionLayer* GetCollisionLayer(){
 return BodyCollisionLayer;
};



void SetCollisionLayer(std::string Cl);
SunBodys* Owner = nullptr;
void CreateBodyComponent();
Component* GetBodyComponent(){
  if(BodyComponent){
return BodyComponent.get();
  }else{
    return nullptr;
  }
};

};

class SunBodys{
  private:

 std::unordered_map<std::string,std::unique_ptr<Body>> Bodys;
 bool StaticBody = false;


 public:
 
Component* OwnerComponent = nullptr;
 std::string GetId();
bool GetStatic(){
  return StaticBody;
};
void AddBody(std::string Id,std::unique_ptr<Body> Body){
  Body->Id = Id;
  Body->Owner = this;
  Bodys.emplace(Id,std::move(Body));
};

void DeleteBody(std::string Id){
  auto It = Bodys.find(Id);
 if(It != Bodys.end()){
   Bodys.erase(Id);
 };
}; 

void CreateStaticBody(std::string Id,std::unique_ptr<SunBodys> Body);

 const std::unordered_map<std::string,std::unique_ptr<Body>>& GetBodysMap()const{
   return Bodys;
};
};


class CollisionsWorld{
private:
std::unordered_map<std::string,std::unique_ptr<CollisionLayer>> CollisionLayers;
std::unordered_map<WorldGridCell,std::vector<Body*>,WorldGridHash> WorldGrid;
public:
CollisionPhysicTypes CollisionPhysic = CollisionPhysicTypes::Arcade;
const std::unordered_map<std::string,std::unique_ptr<CollisionLayer>>& GetCollisionLayersMap()const{
return CollisionLayers;
};
void AddNewCollissionLayer(std::unique_ptr<CollisionLayer> Layer){
CollisionLayers.emplace(Layer.get()->Id,std::move(Layer));
};
void AddNewBodyToWorld(Body* Body);
const std::unordered_map<WorldGridCell,std::vector<Body*>,WorldGridHash>& GetWorldGrid()const{
return WorldGrid;
};
void CollisionsUpdate(float DeltaTime = 0.0f);
void PhysicUpdate(float DeltaTime = 0.0f);

};

class SunWorld{
  private:
  SunWorld(){};
  std::unordered_map<std::string,std::unique_ptr<SunBodys>> StaticBodys;
  std::unordered_map<std::string,std::unique_ptr<Component>> WorldComponents;
  std::unordered_map<std::string,Component*> BodysComponents;
  std::unordered_map<std::string,std::unique_ptr<Material>> Materials;
  public:
 const std::unordered_map<std::string,std::unique_ptr<SunBodys>>& GetStaticBodysMap()const {
    return StaticBodys;
   };
   void AddNewStaticBody(std::string Id,std::unique_ptr<SunBodys> StaticBody){
      for(auto& B : StaticBody.get()->GetBodysMap()){
 CollisionsWorld.AddNewBodyToWorld(B.second.get());
}

    StaticBodys.emplace(Id,std::move(StaticBody));
 
   };
 
   const std::unordered_map<std::string,std::unique_ptr<Component>>& GetWorldComponentsMap()const{
    return WorldComponents;
   }; 

   void AddNewWorldComponent(std::unique_ptr<Component> NewComponent);
  float WorldGridCellsWidth = 64.0f;
   CollisionsWorld CollisionsWorld;


     static SunWorld& instance(){
        static SunWorld instance;
        return instance;
    }

    Material* GetMaterial(std::string Id){
     auto it = Materials.find(Id);
     if(it != Materials.end()){
      return it->second.get();
     };
     return nullptr;
    };

    void AddMaterialToWorld(std::string MaterialId,std::string ShaderId);

    
   

};


class SunBodysControl{
private:
std::vector<SunBodys*> BodysVector;
public:
void AddSunBody(SunBodys* Body){
  std::cout << "AddSunBody: " << Body << "\n";
 BodysVector.push_back(Body);
 
 for(auto& B : Body->GetBodysMap()){
 SunWorld::instance().CollisionsWorld.AddNewBodyToWorld(B.second.get());
}
};
const std::vector<SunBodys*>& GetSunBodysVector()const{
return BodysVector;
};
void Update();

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
    SunBodysControl BodysControl;
    SunWorld& SunWorld = SunWorld.instance();
    SunTime* SunTime;
    SunFonts SunFontsControl;
    SunShadersCore SunShaders;
    

    static SunCore& instance(){
        static SunCore instance;
        return instance;
    }
};



class BorderClass{
  public:
 UnitClass Width;
 float R,G,B,A = 1.0f;
 bool Use = false;
};


class Component{
  public:

  
void ResolveComponent(){
  if(!Dirty) return;
  if (Owner && Owner->Parent) {
    if (Owner->Parent == Owner.get()) {
        std::cout << "Parent self reference!\n";
    }
}

Component* Parent = nullptr;
if (Owner && Owner->Parent) {
    Parent = Owner->Parent->ComponentClass;
}


 switch(Width.Unit){
  case UnitType::Pixel:
  Width.ValueResolved = Width.Value;
    Width.ValuePixel = Width.Value;
      Width.RenderValue = Width.Value;
  break;
  case UnitType::Percent:
  float ParentWidth = SunCore::instance().WindowWidth;
  if(Parent){
  ParentWidth = Parent->Width.ValueResolved;
  }
 Width.ValueResolved = ParentWidth * Width.Value;
 Width.ValuePixel = ParentWidth * Width.Value;
 Width.RenderValue = ParentWidth * Width.Value;

  
  
  break;
 }
 switch(Height.Unit){
  case UnitType::Pixel:
  Height.ValueResolved = Height.Value;
   Height.ValuePixel = Height.Value;
    Height.RenderValue = Height.Value;
  break;
  case UnitType::Percent:
  float ParentHeight = SunCore::instance().WindowHeight;
  if(Parent){
  ParentHeight = Parent->Height.ValueResolved;
  }
  Height.ValueResolved = ParentHeight * Height.Value;
    Height.ValuePixel = ParentHeight * Height.Value;
      Height.RenderValue = ParentHeight * Height.Value;

  break;
 }
 if(TextAlingX == Align::None){
 switch(PosX.Unit){
  case UnitType::Pixel:
   if(Parent){
    float RelativeX = 0.0f;
    NodeClass* ActualNode;
    bool WhileFlag = true;
    ActualNode = Owner.get();
  while(WhileFlag){
  RelativeX += ActualNode->ComponentClass->PosX.ValuePixel;
  if(!ActualNode->Parent){
  WhileFlag = false;
  }else{
  ActualNode = ActualNode->Parent;
  }
  }
   PosX.ValueResolved = RelativeX;
   PosX.ValuePixel = PosX.Value;
   TransformOriginX();
  }else{
 PosX.ValueResolved = PosX.Value;
    PosX.ValuePixel = PosX.Value;
    TransformOriginX();

  }
  break;
  case UnitType::Percent:
  float ParentWidth = SunCore::instance().WindowWidth;
  float ParentX = 0.0f;
  if(Parent){
    ParentX = Parent->PosX.ValueResolved;
   ParentWidth = Parent->Width.ValueResolved;
     
  }
   PosX.ValueResolved = (ParentWidth * PosX.Value) + ParentX;
PosX.ValuePixel = (ParentWidth * PosX.Value);
TransformOriginX();

  break;
 }}else{
   if(this->Type == ComponentType::Text){
   ResolveText();
 };
 };

 if(TextAlingY == Align::None){
  switch(PosY.Unit){
  case UnitType::Pixel:
   if(Parent){
    float RelativeY = 0.0f;
    NodeClass* ActualNode;
    bool WhileFlag = true;
    ActualNode = Owner.get();
  while(WhileFlag){
  RelativeY += ActualNode->ComponentClass->PosY.Value;
  if(!ActualNode->Parent){
  WhileFlag = false;
  }else{
  ActualNode = ActualNode->Parent;
  }
  }
   PosY.ValueResolved = RelativeY;
   PosY.ValuePixel = PosY.Value;
   TransformOriginY();
  }else{
 PosY.ValueResolved = PosY.Value;
 PosY.ValuePixel = PosY.Value;
 TransformOriginY();
  }
  break;
  case UnitType::Percent:
  float ParentHeight = SunCore::instance().WindowHeight;
  float ParentY = 0.0f;
  if(Parent){
    ParentY = Parent->PosY.ValueResolved;
   ParentHeight = Parent->Height.ValueResolved;
  }
   PosY.ValueResolved = (ParentHeight * PosY.Value) + ParentY;
   PosX.ValuePixel = (ParentHeight * PosY.Value);
   TransformOriginY();
  break;
 }
}else{
  ResolveText();
}

 

 switch(Border.Width.Unit){
  case UnitType::Pixel:{
    Border.Width.ValueResolved = Border.Width.Value;
    Border.Width.ValuePixel = Border.Width.Value;
    Border.Width.RenderValue = Border.Width.Value;
    break;
  
 }
 };
 
 if(this->Body){
    if(this->Type == ComponentType::Text){
   ResolveText();
 };
 }


 UpdateRC();
 Dirty = false;

};

void TransformOriginX(){
 float ax = PosX.ValueResolved;
 float w = Width.RenderValue;
 switch(OriginX){
  case OriginClass::Start:{
    PosX.RenderValue = ax;
    break;
  }
  case OriginClass::Center:{
    PosX.RenderValue = ax - (w / 2);
    break;
  }
  case OriginClass::End:{
    PosX.RenderValue = ax - w;
    break;
  }
 }
};

void TransformOriginY(){
float ay = PosY.ValueResolved;
 float h = Height.RenderValue;
 switch(OriginY){
  case OriginClass::Start:{
    PosY.RenderValue = ay;
    break;
  }
  case OriginClass::Center:{
    PosY.RenderValue = ay - (h / 2);
    break;
  }
  case OriginClass::End:{
    PosY.RenderValue = ay - h;
    break;
  }
 }
};

 void UpdateRC(){
   if(!RenderComponent) return;
  RenderComponent->Height = Height.ValueResolved;
  RenderComponent->Width = Width.ValueResolved;
  RenderComponent->OriginX = OriginX;
  RenderComponent->OriginY = OriginY;
  RenderComponent->X = PosX.ValueResolved;
  RenderComponent->Y = PosY.ValueResolved;
  RenderComponent->BorderWidth = Border.Width.ValueResolved;
  RenderComponent->BorderColorR = Border.R;
  RenderComponent->BorderColorA = Border.A;
  RenderComponent->BorderColorB = Border.B;
  RenderComponent->BorderColorG = Border.G;
  RenderComponent->CharactersMargin = CharactersMargin;
  RenderComponent->TextAlignX = TextAlingX;
  RenderComponent->TextAlignY = TextAlingY;
  
 };

 void ResolveBody(){ 
 
   for(auto& InnerBody : Body->GetBodysMap()){
    
    Component* BodyComponent = InnerBody.second->GetBodyComponent();

    UnitClass BodyX;
    BodyX.Unit = UnitType::Pixel;
    BodyX.Value = this->PosX.RenderValue + InnerBody.second.get()->OffsetX;

    UnitClass BodyY;
    BodyY.Unit = UnitType::Pixel;
    BodyY.Value = this->PosY.ValueResolved + InnerBody.second.get()->OffsetY;
    InnerBody.second->WorldX = BodyX.Value;
   InnerBody.second->WorldY = BodyY.Value;
    
   if(BodyComponent){
    BodyComponent->SetX(BodyX);
    BodyComponent->SetY(BodyY);

    BodyComponent->ResolveComponent();

   };

   if(this->GetOriginX() == OriginClass::End){
   InnerBody.second->WorldX -= InnerBody.second->Width;
   };
      if(this->GetOriginY() == OriginClass::End){
   InnerBody.second->WorldY -= InnerBody.second->Height;
   };

    if(this->GetOriginX() == OriginClass::Center){
   InnerBody.second->WorldX -= InnerBody.second->Width / 2;
   };
      if(this->GetOriginY() == OriginClass::Center){
   InnerBody.second->WorldY -= InnerBody.second->Height / 2;
   };

  };
  
   
  
  
 };

 void ResolveText(){
  if(Font){
   float tw = 0.0f;
   float x = 0.0f;
   float y = 0.0f;
   float th = 0.0f;
   float maxAscent = 0.0f;
float maxDescent = 0.0f;


for(char c : Text){
    Character ch = Font->GetCharacter(c);
    tw += (ch.Advance >> 6) + CharactersMargin.x;
    th += (ch.Size.y + CharactersMargin.y);

    float maxAscent = 0.0f;
float maxDescent = 0.0f;

    float ascent = ch.Bearing.y;
    float descent = ch.Size.y - ch.Bearing.y;

    if(ascent > maxAscent)
        maxAscent = ascent;

    if(descent > maxDescent)
        maxDescent = descent;

};

 th = maxAscent + maxDescent;




float px = 0.0f;
float pw = SunCore::instance().WindowWidth;
float ph = SunCore::instance().WindowHeight;
float py = 0.0f;

if(Owner->Parent)
{
    px = Owner->Parent->ComponentClass->GetX().RenderValue;
    pw = Owner->Parent->ComponentClass->GetWidth().ValueResolved;
    py = Owner->Parent->ComponentClass->GetY().RenderValue;
    ph = Owner->Parent->ComponentClass->GetHeight().ValueResolved;
}
if(TextAlingX == Align::Start)
{
    float parentStart = px;
    x = parentStart;
}
else if(TextAlingX == Align::Center)
{
    float parentCenter = px + (pw / 2.0f);
    x = parentCenter - (tw / 2.0f);
}
else if(TextAlingX == Align::End)
{
    x = px + pw - tw;
}

if(TextAlingY == Align::Start)
{
    float parentStart = py;
    y = parentStart;
}
else if(TextAlingY == Align::Center)
{
    float parentCenter = py + (ph / 2.0f);
    y = parentCenter - (th / 2.0f);
}
else if(TextAlingY == Align::End)
{
    y = py + ph - th;
}
std::cout << "\n  Align  " << x << " , "<< PosY.ValueResolved << "  \n  ";
PosX.ValueResolved = x;
PosY.ValueResolved = y;
TransformOriginX();
TransformOriginY();
UpdateRC();
  };
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
    return Owner.get();
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
    void SetOwner(std::unique_ptr<NodeClass> Value){
    this->Owner = std::move(Value);
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
   RenderComponentClass* GetRenderComponent(){
   return RenderComponent;
   };
   void SetBorder(BorderClass Border){
    this->Border = Border;
     this->Dirty = true;
   };

   BorderClass GetBorder(){
    return Border;
   };

   void AddMaterial(std::string Id){
     RenderComponent->Material = SunCore::instance().SunWorld.GetMaterial(Id);
   };
   
   ComponentType GetComponentType()const{
    return Type;
   };

   void SetComponentType(ComponentType t){
     Type = t;
     Dirty = true;
   };
  
   SunFont* GetFont(){
   return Font;
   }; 

   void SetFont(SunFont* sf){
    Font = sf;
    Dirty = true; 
   }

   std::string GetText(){
    return Text;
   };

   void SetText(std::string T){
    Text = T;
   };

   void AddBody(std::unique_ptr<SunBodys> SunBody){
    Body = std::move(SunBody);
    SunCore::instance().BodysControl.AddSunBody(Body.get());
    Body->OwnerComponent = this;
   };


   void ApplyForce(vector2 v2){
    if(this->Body){
    for(auto& b : this->Body->GetBodysMap()){
      if(SunCore::instance().SunWorld.CollisionsWorld.CollisionPhysic == CollisionPhysicTypes::Arcade){
      if(b.second->GetBodyArcadePhysics()){
    b.second->GetBodyArcadePhysics()->AddForce(v2);
      }else{
        std::cout << "\n A component must have a Physic Config in Body to add velocity \n";
      }
    }else if(SunCore::instance().SunWorld.CollisionsWorld.CollisionPhysic == CollisionPhysicTypes::SunPhysic){
         if(b.second->GetBodySunPhysics()){
    b.second->GetBodySunPhysics()->AddForce(v2);
      }else{
        std::cout << "\n A component must have a Physic Config in Body to add velocity \n";
      }
    }
  }
    }else{
      std::cout << "\n A component must have a Body to add velocity \n";
    }
   
  };

  vector2 GetCharactersMargin()const{
   return CharactersMargin;
  };

  void SetCharatersMargin(float x,float y){
   CharactersMargin.x = x;
   CharactersMargin.y = y;
   Dirty = true;
  };

  Align GetTextAlignX()const{
  return TextAlingX;
  };

  void SetTextAlingX(Align A){
   TextAlingX = A;
  }; 

    Align GetTextAlignY()const{
  return TextAlingY;
  };

  void SetTextureMask(std::string m){
   RenderComponent->TextureMask = m;
  };

  void SetTextAlingY(Align A){
   TextAlingY = A;
  }; 
  private:
  std::string Id;
  std::string Texture;
  vector2 CharactersMargin;
   UnitClass Width;
   UnitClass Height;
   UnitClass PosX;
   UnitClass PosY;
   OriginClass OriginX = OriginClass::Center;
   OriginClass OriginY = OriginClass::Center;
   BorderClass Border;
   std::unique_ptr<NodeClass> Owner = nullptr;
   RenderComponentClass* RenderComponent = nullptr;
 std::unique_ptr<RGBAClass> RGBA;
   bool Dirty = true;
   std::unique_ptr<SunBodys> Body = nullptr;
   Align TextAlingX = Align::None;
   Align TextAlingY = Align::None;
   ComponentType Type;
   SunFont* Font = nullptr;
   std::string Text = "None";
  
  
   

  

};

