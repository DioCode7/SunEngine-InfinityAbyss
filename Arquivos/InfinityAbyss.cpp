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
       SunTextures.NewTexture("TexturaTeste2","./Assets/TestAssets/TestAsset2.jpg");
    };
    void OnInit() override{
            SunRender SunRendering;
    SunRendering.AddRectangle("TestRectangle",1100.0f,80.0f,30.0f,30.0f,1.0f,0.0f,1.0f,1.0f,this);
     SunRendering.AddCircle("TestCircle",1000.0f,700.0f,70.0f,1.0f,0.0f,0.0f,1.0f,this);

     UnitClass MenuBackgroundW;
     MenuBackgroundW.Unit = UnitType::Pixel;
     MenuBackgroundW.Value = 700.0f;
       UnitClass MenuBackgroundH;
     MenuBackgroundH.Unit = UnitType::Pixel;
     MenuBackgroundH.Value = 700.0f;
       UnitClass MenuBackgroundX;
     MenuBackgroundX.Unit = UnitType::Pixel;
     MenuBackgroundX.Value = 200.0f;
     UnitClass MenuBackgroundY;
     MenuBackgroundY.Unit = UnitType::Pixel;
     MenuBackgroundY.Value = 400.0f;
     Component* MenuBackground = new Component("MenuBackground",MenuBackgroundW,MenuBackgroundH,MenuBackgroundX,MenuBackgroundY,"TexturaTeste");
     SunRendering.AddSprite(MenuBackground,this);

      UnitClass MenuW;
     MenuW.Unit = UnitType::Pixel;
     MenuW.Value = 700.0f;
       UnitClass MenuH;
     MenuH.Unit = UnitType::Pixel;
     MenuH.Value = 300.0f;
       UnitClass MenuX;
     MenuX.Unit = UnitType::Pixel;
     MenuX.Value = 0.0f;
     UnitClass MenuY;
     MenuBackgroundY.Unit = UnitType::Pixel;
     MenuBackgroundY.Value = 0.0f;
     Component* Menu = new Component("Menu",MenuW,MenuH,MenuX,MenuY,"TexturaTeste2");
     SunRendering.AddSprite(Menu,this,MenuBackground);




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