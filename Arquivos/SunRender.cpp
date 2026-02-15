#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "SunEngineCore.h"
#include "SunRender.h"



void CreateMainWindow(SunEngineConfig& Config){
     SDL_DisplayMode DisplayMode;
     SDL_GetCurrentDisplayMode(0,&DisplayMode);

     int X = DisplayMode.w;
     int Y = DisplayMode.h - 50;

    SunCore::instance().window = SDL_CreateWindow(
        Config.Window.WindowName.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        X, Y,
        SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP
    );
    SunCore::instance().GlContext = SDL_GL_CreateContext(SunCore::instance().window);
    int winW, winH;
    SDL_GetWindowSize(SunCore::instance().window, &winW, &winH);

        SunCore::instance().WindowWidth  = winW;
        SunCore::instance().WindowHeight = winH;
 
        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            std::cout << "Erro ao iniciar GLEW\n";
        }
}

void EngineRender(){



    glClearColor(0, 0, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);


   for (auto* rc : SunCore::instance().SunEngineConfig->Render.RenderVector) {

    rc->RenderMethod(rc->X,rc->Y,rc->Width,rc->Height,rc->R,rc->G,rc->B,rc->A);
    
}






    
    SDL_GL_SwapWindow(SunCore::instance().window);

    SDL_Delay(1);


    }





