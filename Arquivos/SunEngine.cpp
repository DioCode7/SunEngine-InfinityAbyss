#include <iostream>
#include <cmath>
#include <ios>
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
#include "SunText.h"

auto& Core = SunCore::instance();

SunTime& Time = SunCore::instance().SunTime;


void SunEngineGameLoop(){

   while(SunCore::instance().ApplicationState == "Running"){
       
      Time.TimeUpdate();
       float t = Time.GetTime();
      float DeltaTime = Time.GetDeltaTime();
     // DeltaTime = std::min(DeltaTime,0.033f);

    SunDispatchs();
    SunUpdateInput();
    ScenesLoop();
    EngineRender(DeltaTime,t);
   Core.SunWorld.CollisionsWorld.CollisionsUpdate(DeltaTime);
   Core.SunWorld.CollisionsWorld.PhysicUpdate(DeltaTime);

    

   };






};



void StartEngine(SunEngineConfig& Config)
{

    Renderer RenderMethods;
    SunText TextMethods;
    RenderMethods.InitSDLContext(Config);
    RenderMethods.LoadShaders(Config);
    TextMethods.Init();
    Scene* FirstScene = Config.SunScenes.Scenes[0];
    RunScene(FirstScene);
    SunCore::instance().ApplicationState = "Running";
   SunEngineGameLoop();


    
    
    
    
}

