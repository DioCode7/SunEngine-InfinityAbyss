#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include "SunEngine.h"
#include "SunEngineCore.h"
#include "SunRender.h"
#include "SunManager.h"
#include "SunEngineCore.h"
#include "SunFunctions.h"
#include "SunImages.h"

auto& Core = SunCore::instance();


void SunEngineGameLoop(){

   while(SunCore::instance().ApplicationState == "Running"){

    SunDispatchs();
    SunUpdateInput();
    EngineRender();
    ScenesLoop();
   Core.BodysControl.Update();

   };






};



void StartEngine(SunEngineConfig& Config)
{

    Renderer RenderMethods;
    RenderMethods.InitSDLContext(Config);
    RenderMethods.LoadShaders(Config);
    Scene* FirstScene = Config.SunScenes.Scenes[0];
    RunScene(FirstScene);
    SunCore::instance().ApplicationState = "Running";
   SunEngineGameLoop();


    
    
    
    
}

