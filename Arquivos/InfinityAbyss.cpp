#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <string>
#include <vector>

#include "SunEngine.h"




int main(int argc, char** argv)
{



    
   SunEngineConfig InfinityAbyssConfig;
   
    class MenuScene : public Scene{
    public:
    void SceneConfigs() override{

    };
    void OnLoad() override{

    };
    void OnInit() override{
            SunRender SunRendering;
     SunRendering.AddRectangle("TestRectangle",1100.0f,80.0f,30.0f,30.0f,1.0f,1.0f,1.0f,1.0f,this);
    };
    void OnUpdate() override{

    };
    
       

};
   
   InfinityAbyssConfig.Window.WindowName = "Infinity Abyss";
   MenuScene* Menu = new MenuScene();
   InfinityAbyssConfig.SunScenes.Scenes = {Menu};
   
    
    
    
    
  

    StartEngine(InfinityAbyssConfig);
    return 0;
}