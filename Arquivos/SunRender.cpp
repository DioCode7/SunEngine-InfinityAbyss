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

void Renderer::InitSDLContext(SunEngineConfig& Config){
   SunCore::instance().SunEngineConfig = &Config;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
     CreateMainWindow(Config);
}

void Renderer::LoadShaders(SunEngineConfig& Config){
     float vertices[] = {
     -0.5f,-0.5f,0.0f,  0.0f,0.0f,
     0.5f,-0.5f,0.0f,   1.0f,0.0f,
     0.5f, 0.5f,0.0f,   1.0f,1.0f,
    -0.5f, 0.5f,0.0f,   0.0f,1.0f
                };
                unsigned int VBO,VAO;
                
                glGenVertexArrays(1,&VAO);
                glGenBuffers(1,&VBO);

                glBindVertexArray(VAO);

                glBindBuffer(GL_ARRAY_BUFFER,VBO);
                glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

               glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
                glEnableVertexAttribArray(1);

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

                const char* VertexShaderSource = R"(
                #version 330 core


                layout (location = 0) in vec3 aPos;
                layout (location = 1) in vec2 aUV;

                out vec2 vUV;

                uniform vec2 uPos;     
                uniform vec2 uSize;
                    
                out vec2 vLocalPos;
                    
                void main(){
              
             vec3 scaled = vec3(aPos.x * uSize.x, aPos.y * uSize.y, 0.0);
                vec3 translated = scaled + vec3(uPos, 0.0);

                gl_Position = vec4(translated,1.0);

                vLocalPos = aPos.xy;
               vUV = aUV;
               
                }

                )";

                const char* FragmentShaderSource = R"(
                #version 330 core
                in vec2 vLocalPos;
                in vec2 aUV;
                out vec4 FragColor;
                
                uniform vec4 uColor;
                uniform int ShapeType;
                uniform int uUseTexture;
                uniform sampler2D uTexture;

                void main(){

                vec4 uBaseColor = uColor;
                if(uUseTexture == 1){
                uBaseColor *= texture(uTexture,aUV);
                }
               
                int uShapeType = ShapeType;
                if(uShapeType == 0){
                FragColor = uBaseColor; 
               }else if(uShapeType == 1){
                 float dist = length(vLocalPos);
                 if(dist > 0.5) discard;
                 FragColor = uBaseColor;
               }
            
               
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
                

   
}




