#pragma once
#include <string>
#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <SDL2/SDL.h>





struct SunCoreData {
    unsigned int VAO;
    unsigned int VBO;
    unsigned int ShaderProgram;
};

enum class SceneState{
  OnLoad,
  OnInit,
  OnUpdate
};
enum class UnitType{
Percent,
Pixel
};
class UnitClass{
   public:
UnitType Unit;
float Value;
float ValueResolved;
};

class NodeClass;

class Component{
  public:
  Component(std::string Id,UnitClass W,UnitClass H,UnitClass X,UnitClass Y,std::string Texture):Id(Id),Width(W),Height(H),PosX(X),PosY(Y),Texture(Texture){}
  std::string Id;
  std::string Texture;
   UnitClass Width;
   UnitClass Height;
   UnitClass PosX;
   UnitClass PosY;
   NodeClass* Owner = nullptr;

  

};

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
    std::unordered_map<std::string,RenderComponentClass*> Sprites;
    void AddTexture(const std::string& Id,const Texture& Tex){
      if(Textures.count(Id)){
        std::cout << "Texture Ja Existe";
      } 
      else{
        Textures.emplace(Id,Tex);
      }
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
    

    static SunCore& instance(){
        static SunCore instance;
        return instance;
    }
};