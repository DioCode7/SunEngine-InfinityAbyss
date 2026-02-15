#pragma once
#include <string>
#include <array>
#include <vector>
#include <SDL2/SDL.h>
#include <GL/gl.h>

struct SunCoreData {
    unsigned int VAO;
    unsigned int VBO;
    unsigned int ShaderProgram;
};

class Scene{

    public:
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

    Scene* OwnerScene;
    std::string Id;
       RenderComponentClass(int PosX,int PosY,int W,int H, float R,float G,float B,float A,std::string Id,Scene* OwnerScene):
      X(PosX),Y(PosY),Width(W),Height(H),R(R),G(G),B(B),A(A){}
 
       
   virtual void RenderMethod(float X,float Y,float W,float H,float R,float G,float B,float A) =0;

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

class SunCore {
    private:
    SunCore() {};
    public:
    std::string ApplicationState;
    SDL_Window* window;
    int WindowWidth;
    int WindowHeight;
    SDL_GLContext GlContext;
    std::vector<Scene*> RunningScenes;
    SunEngineConfig* SunEngineConfig;

    SunCoreData Gl;
    

    static SunCore& instance(){
        static SunCore instance;
        return instance;
    }
};