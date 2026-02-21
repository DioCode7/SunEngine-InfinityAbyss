#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include <vector>

#include "SunEngine.h"

    SunTexturesControl SunTextures;


int main(int argc, char** argv)
{




   SunEngineConfig InfinityAbyssConfig;
   
    class MenuScene : public Scene{
    public:
    std::string SceneID = "MenuScene"; 
    void SceneConfigs() override{
     
    };
    void OnLoad() override{
     SunTextures.NewTexture("TexturaTeste","./Assets/TestAssets/TestAsset.png");
    };
    void OnInit() override{
            SunRender SunRendering;
     SunRendering.AddRectangle("TestRectangle",1100.0f,80.0f,30.0f,30.0f,1.0f,0.0f,1.0f,1.0f,this);

     SunRendering.AddCircle("TestCircle",1000.0f,700.0f,70.0f,1.0f,0.0f,0.0f,1.0f,this);
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