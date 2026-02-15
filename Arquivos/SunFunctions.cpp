
#include <string>
#include <SDL2/SDL.h>

#include <GL/glew.h>
 
#include <variant>
#include <vector>
#include "SunEngineCore.h"
#include "SunFunctions.h"



class WindowManipulateMethods {
    public:
    void LeaveFullScreen(){
    
        Uint32 Flags = SDL_GetWindowFlags(SunCore::instance().window);

        bool IsInFullScreen = Flags & SDL_WINDOW_FULLSCREEN_DESKTOP;

        if(IsInFullScreen){
            SDL_SetWindowFullscreen(SunCore::instance().window,0);
        }else{
              SDL_SetWindowFullscreen(SunCore::instance().window,SDL_WINDOW_FULLSCREEN_DESKTOP);
        }
    };
};

void WindowManipulate(const std::string ManipulateType){

   WindowManipulateMethods Methods;
    if(ManipulateType == "LeaveFullScreen"){
       Methods.LeaveFullScreen();
    }

    

    

}

 class RenderComponentRectangle : public RenderComponentClass{
            public:
       
           RenderComponentRectangle(int PosX,int PosY,int W,int H, float R,float G,float B,float A,std::string Id,Scene* OwnerScene):
            RenderComponentClass(PosX,PosY,W,H, R, G, B,A,Id,OwnerScene){}
         
              void RenderMethod(float X,float Y,float W,float H,float R,float G,float B,float A) override {


             
                
                GLuint Shader = SunCore::instance().Gl.ShaderProgram;

                float PosX = (((X / SunCore::instance().WindowWidth)*2.0f)-1.0f) + (W / SunCore::instance().WindowWidth) / 2.0f;
                float PosY = 0.0f - (((Y / SunCore::instance().WindowHeight)*2.0f)-1.0f) - (H / SunCore::instance().WindowHeight) / 2.0f;

                float SizeX = (W / SunCore::instance().WindowWidth) * 2.0f;
                float SizeY = (H / SunCore::instance().WindowHeight) * 2.0f;



                glUseProgram(Shader);

           
                glBindVertexArray(SunCore::instance().Gl.VAO);

                 GLint uPosLoc = glGetUniformLocation(Shader,"uPos");
                  GLint uSizeLoc = glGetUniformLocation(Shader,"uSize");
                  GLint uColorLoc = glGetUniformLocation(Shader,"uColor");

                  glUniform2f(uPosLoc,PosX,PosY);
                  glUniform2f(uSizeLoc,SizeX,SizeY);
                  glUniform4f(uColorLoc,R,G,B,A);

                
                glDrawArrays(GL_TRIANGLE_FAN,0,4);



 


                

            };
              
        };



      
      
    void SunRender::AddRectangle(std::string Id,float PosX,float PosY,float Width,float Height,float R,float G,float B,float A,Scene* OwnerScene){
     
    RenderComponentRectangle* Rc = new RenderComponentRectangle(PosX,PosY,Width,Height,R,G,B,A,Id,OwnerScene);



      SunCore::instance().SunEngineConfig->Render.RenderVector.push_back(Rc);
     
           
           

        };
    
     
      





  



void RunScene(Scene* RequestScene){

    

    RequestScene->OnInit();


    SunCore::instance().RunningScenes.push_back(RequestScene); 

}