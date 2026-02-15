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


void SunEngineGameLoop(){

   while(SunCore::instance().ApplicationState == "Running"){

    SunDispatchs();
    EngineRender();
    

   };






};



void StartEngine(SunEngineConfig& Config)
{


   SunCore::instance().SunEngineConfig = &Config;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

     CreateMainWindow(Config);

        float vertices[] = {
                -0.5f, -0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
                0.5f,  0.5f, 0.0f,
                -0.5f,  0.5f, 0.0f
                };
                unsigned int VBO,VAO;
                
                glGenVertexArrays(1,&VAO);
                glGenBuffers(1,&VBO);

                glBindVertexArray(VAO);

                glBindBuffer(GL_ARRAY_BUFFER,VBO);
                glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

                glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);

                const char* VertexShaderSource = R"(
                #version 330 core

                layout (location = 0) in vec3 aPos;
                uniform vec2 uPos;     
                uniform vec2 uSize;            
                void main(){
             vec3 scaled = vec3(aPos.x * uSize.x, aPos.y * uSize.y, 0.0);
                vec3 translated = scaled + vec3(uPos, 0.0);

                gl_Position = vec4(translated,1.0);
                }

                )";

                const char* FragmentShaderSource = R"(
                #version 330 core
                out vec4 FragColor;
                uniform vec4 uColor;

                void main(){

                FragColor = uColor; 

                }
                )";

                unsigned int VertexShader = glCreateShader(GL_VERTEX_SHADER);
                glShaderSource(VertexShader,1,&VertexShaderSource,NULL);
                glCompileShader(VertexShader);

                int Success;
                char InfoLog[512];
                glGetShaderiv(VertexShader,GL_COMPILE_STATUS, &Success);
                if(!Success){
                    glGetShaderInfoLog(VertexShader,512,NULL,InfoLog);
                  
                }

                unsigned int FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
                glShaderSource(FragmentShader,1,&FragmentShaderSource,NULL);
                glCompileShader(FragmentShader);

                   glGetShaderiv(FragmentShader,GL_COMPILE_STATUS, &Success);
                if(!Success){
                    glGetShaderInfoLog(FragmentShader,512,NULL,InfoLog);
                  
                };

                unsigned int ShaderProgram = glCreateProgram();
                glAttachShader(ShaderProgram,VertexShader);
                glAttachShader(ShaderProgram,FragmentShader);

                glLinkProgram(ShaderProgram);
                glGetProgramiv(ShaderProgram,GL_LINK_STATUS,&Success);
                if(!Success){
                    glGetProgramInfoLog(ShaderProgram,512,NULL,InfoLog);
                }
             
                SunCore::instance().Gl.VAO = VAO;
               SunCore::instance().Gl.VBO = VBO;
               SunCore::instance().Gl.ShaderProgram = ShaderProgram;
                

   
    Scene* FirstScene = Config.SunScenes.Scenes[0];

    RunScene(FirstScene);
    SunCore::instance().ApplicationState = "Running";


    
   SunEngineGameLoop();


    
    
    
    
}

