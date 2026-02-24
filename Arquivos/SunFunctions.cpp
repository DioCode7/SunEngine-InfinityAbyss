
#include <string>
#include <SDL2/SDL.h>

#include <GL/glew.h>
 #include <iostream>
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
         
              void RenderMethod(float X,float Y,float W,float H,float R,float G,float B,float A,std::string TextureId = "None") override {


             
                
                GLuint Shader = SunCore::instance().Gl.ShaderProgram;
                float PosX;
                float PosY;
                float SizeX = (W / SunCore::instance().WindowWidth) * 2.0f;
                float SizeY = (H / SunCore::instance().WindowHeight) * 2.0f;

                switch(this->OriginX){
                case OriginClass::Center:
                PosX = (((X / SunCore::instance().WindowWidth)*2.0f)-1.0f);
                break;
                case OriginClass::Start:
                  PosX = (((X / SunCore::instance().WindowWidth)*2.0f)-1.0f) + (SizeX / 2.0f);
                break;
                 case OriginClass::End:
                  PosX = (((X / SunCore::instance().WindowWidth)*2.0f)-1.0f) - (SizeX / 2.0f);
                break;
               }
               switch(this->OriginY){
                case OriginClass::Center:
                 PosY = 0.0f - (((Y / SunCore::instance().WindowHeight)*2.0f)-1.0f);
                 break;
                 case OriginClass::Start:
                 PosY = 0.0f - (((Y / SunCore::instance().WindowHeight)*2.0f)-1.0f) - (SizeY / 2.0f);
                 break;
                  case OriginClass::End:
                 PosY = 0.0f - (((Y / SunCore::instance().WindowHeight)*2.0f)-1.0f) + (SizeY / 2.0f);
                 break;
               }



                glUseProgram(Shader);

           
                glBindVertexArray(SunCore::instance().Gl.VAO);

                  GLint uPosLoc = SunCore::instance().Gl.UniformsLocations.uPosLoc;
                  GLint uSizeLoc = SunCore::instance().Gl.UniformsLocations.uSizeLoc;
                  GLint uColorLoc = SunCore::instance().Gl.UniformsLocations.uColorLoc;
                    GLint uShapeType = SunCore::instance().Gl.UniformsLocations.uShapeType;
                    GLint uUseTexture = SunCore::instance().Gl.UniformsLocations.uUseTexture;
                  

                  glUniform2f(uPosLoc,PosX,PosY);
                  glUniform2f(uSizeLoc,SizeX,SizeY);
                  glUniform4f(uColorLoc,R,G,B,A);
                  glUniform1i(uShapeType,0);
                  glUniform1i(uUseTexture,0);

                
                glDrawArrays(GL_TRIANGLE_FAN,0,4);



 


                

            };
              
        };

class RenderComponentCircle : public RenderComponentClass{
    public:
       RenderComponentCircle(int Radius,int PosX,int PosY,int R,int G,int B,int A,std::string Id,Scene* OwnerScene) :
        RenderComponentClass(PosX,PosY,Radius * 2,Radius * 2,R,G,B,A,Id,OwnerScene){}

        void RenderMethod(float X,float Y,float W, float H, float R, float G,float B,float A,std::string TextureId = "None") override {
         GLuint Shader = SunCore::instance().Gl.ShaderProgram;

            

                float SizeX = (W / SunCore::instance().WindowWidth) * 2.0f;
                float SizeY = (H / SunCore::instance().WindowHeight) * 2.0f;
                float PosX;
                float PosY;
                switch(this->OriginX){
                case OriginClass::Center:
                PosX = (((X / SunCore::instance().WindowWidth)*2.0f)-1.0f);
                break;
                case OriginClass::Start:
                  PosX = (((X / SunCore::instance().WindowWidth)*2.0f)-1.0f) + (SizeX / 2.0f);
                break;
                 case OriginClass::End:
                  PosX = (((X / SunCore::instance().WindowWidth)*2.0f)-1.0f) - (SizeX / 2.0f);
                break;
               }
               switch(this->OriginY){
                case OriginClass::Center:
                 PosY = 0.0f - (((Y / SunCore::instance().WindowHeight)*2.0f)-1.0f);
                 break;
                 case OriginClass::Start:
                 PosY = 0.0f - (((Y / SunCore::instance().WindowHeight)*2.0f)-1.0f) - (SizeY / 2.0f);
                 break;
                  case OriginClass::End:
                 PosY = 0.0f - (((Y / SunCore::instance().WindowHeight)*2.0f)-1.0f) + (SizeY / 2.0f);
                 break;
               }




                glUseProgram(Shader);

           
                glBindVertexArray(SunCore::instance().Gl.VAO);

               GLint uPosLoc = SunCore::instance().Gl.UniformsLocations.uPosLoc;
                  GLint uSizeLoc = SunCore::instance().Gl.UniformsLocations.uSizeLoc;
                  GLint uColorLoc = SunCore::instance().Gl.UniformsLocations.uColorLoc;
                    GLint uShapeType = SunCore::instance().Gl.UniformsLocations.uShapeType;
                    GLint uUseTexture = SunCore::instance().Gl.UniformsLocations.uUseTexture;
                 

                  glUniform2f(uPosLoc,PosX,PosY);
                  glUniform2f(uSizeLoc,SizeX,SizeY);
                  glUniform4f(uColorLoc,R,G,B,A);
                  glUniform1i(uShapeType,1);
                    glUniform1i(uUseTexture,0);

                
                glDrawArrays(GL_TRIANGLE_FAN,0,4);



 
        }
};


class RenderComponentSprite : public RenderComponentClass{
public:
RenderComponentSprite(std:: string SpriteId,float PosX,float PosY,float W,float H,std::string TextureId,Scene* OwnerScene) :
RenderComponentClass(PosX,PosY,W,H,0,0,0,0,SpriteId,OwnerScene,TextureId){}

    void RenderMethod(float X,float Y,float W,float H,float R,float G,float B,float A,std::string TextureID)override{
   
      GLuint Shader = SunCore::instance().Gl.ShaderProgram;
    Texture* Tex = SunCore::instance().SunRenderCore.GetTexture(TextureID);
    
   float PosX;
   float PosY;

             

                float SizeX = (W / SunCore::instance().WindowWidth) * 2.0f;
                float SizeY = (H / SunCore::instance().WindowHeight) * 2.0f;

                  switch(this->OriginX){
                case OriginClass::Center:
                PosX = (((X / SunCore::instance().WindowWidth)*2.0f)-1.0f);
                break;
                case OriginClass::Start:
                  PosX = (((X / SunCore::instance().WindowWidth)*2.0f)-1.0f) + (SizeX / 2.0f);
                break;
                 case OriginClass::End:
                  PosX = (((X / SunCore::instance().WindowWidth)*2.0f)-1.0f) - (SizeX / 2.0f);
                break;
               }
               switch(this->OriginY){
                case OriginClass::Center:
                 PosY = 0.0f - (((Y / SunCore::instance().WindowHeight)*2.0f)-1.0f);
                 break;
                 case OriginClass::Start:
                 PosY = 0.0f - (((Y / SunCore::instance().WindowHeight)*2.0f)-1.0f) - (SizeY / 2.0f);
                 break;
                  case OriginClass::End:
                 PosY = 0.0f - (((Y / SunCore::instance().WindowHeight)*2.0f)-1.0f) + (SizeY / 2.0f);
                 break;
               }


                glUseProgram(Shader);

           
                glBindVertexArray(SunCore::instance().Gl.VAO);

                 GLint uPosLoc = SunCore::instance().Gl.UniformsLocations.uPosLoc;
                  GLint uSizeLoc = SunCore::instance().Gl.UniformsLocations.uSizeLoc;
                  GLint uColorLoc = SunCore::instance().Gl.UniformsLocations.uColorLoc;
                    GLint uShapeType = SunCore::instance().Gl.UniformsLocations.uShapeType;
                    GLint uUseTexture = SunCore::instance().Gl.UniformsLocations.uUseTexture;
                    GLint uTexture = SunCore::instance().Gl.UniformsLocations.uTexture;
                    GLint uFlipY = SunCore::instance().Gl.UniformsLocations.uFlipY;
                     GLint uFlipX = SunCore::instance().Gl.UniformsLocations.uFlipX;

                  glUniform2f(uPosLoc,PosX,PosY);
                  glUniform2f(uSizeLoc,SizeX,SizeY);
                  glUniform1i(uShapeType,0);
                  glUniform1i(uUseTexture,1);
                 glUniform1i(uTexture,0);
                 glUniform1i(uFlipY,1);
                 glUniform1i(uFlipX,0);
                 glUniform4f(uColorLoc, 1.0f, 1.0f, 1.0f, 1.0f);
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D,Tex->GPUID);
                 
                glDrawArrays(GL_TRIANGLE_FAN,0,4);



    

};
};



      
    void SunRender::AddRectangle(Component* ComponentClass,Scene* OwnerScene,Component* Parent){
     
  NodeClass* ComponentNode = new NodeClass();
  ComponentClass->SetOwner(ComponentNode);
  NodeClass* ParentNode = nullptr;
  if(Parent){
    ParentNode = Parent->GetOwner();
  }
  ComponentNode->Parent = ParentNode;
  ComponentNode->ComponentClass = ComponentClass;
   ComponentClass->ResolveComponent();
  RenderComponentRectangle* Rc = new RenderComponentRectangle(ComponentClass->GetX().ValueResolved,
    ComponentClass->GetY().ValueResolved,ComponentClass->GetWidth().ValueResolved,ComponentClass->GetHeight().ValueResolved,
    ComponentClass->GetRGBA()->R,ComponentClass->GetRGBA()->G,ComponentClass->GetRGBA()->B,ComponentClass->GetRGBA()->A,ComponentClass->GetId(),OwnerScene);
    Rc->OriginX = ComponentClass->GetOriginX();
    Rc->OriginY = ComponentClass->GetOriginY();
    Rc->OriginalComponent = ComponentClass;
  SunCore::instance().SunEngineConfig->Render.RenderVector.push_back(Rc);
     
           
           

        };
    
 void SunRender::AddCircle(Component* ComponentClass,Scene* OwnerScene,Component* Parent){
    NodeClass* ComponentNode = new NodeClass();
  ComponentClass->SetOwner(ComponentNode);
  NodeClass* ParentNode = nullptr;
  if(Parent){
    ParentNode = Parent->GetOwner();
  }
  ComponentNode->Parent = ParentNode;
  ComponentNode->ComponentClass = ComponentClass;
   ComponentClass->ResolveComponent();
  RenderComponentCircle* Rc = new RenderComponentCircle(ComponentClass->GetWidth().ValueResolved,ComponentClass->GetX().ValueResolved,
    ComponentClass->GetY().ValueResolved,
    ComponentClass->GetRGBA()->R,ComponentClass->GetRGBA()->G,ComponentClass->GetRGBA()->B,ComponentClass->GetRGBA()->A,ComponentClass->GetId(),OwnerScene);
    Rc->OriginX = ComponentClass->GetOriginX();
    Rc->OriginY = ComponentClass->GetOriginY();
    Rc->OriginalComponent = ComponentClass;
  SunCore::instance().SunEngineConfig->Render.RenderVector.push_back(Rc);
     
 }      
 
 void SunRender::AddSprite(Component* ComponentClass,Scene* OwnerScene,Component* Parent){
  NodeClass* ComponentNode = new NodeClass();
  ComponentClass->SetOwner(ComponentNode);
  NodeClass* ParentNode = nullptr;
  if(Parent){
    ParentNode = Parent->GetOwner();
  }
  ComponentNode->Parent = ParentNode;
  ComponentNode->ComponentClass = ComponentClass;
  ComponentClass->ResolveComponent();
  RenderComponentSprite* Rc = new RenderComponentSprite(ComponentClass->GetId(),ComponentClass->GetX().ValueResolved,
    ComponentClass->GetY().ValueResolved,ComponentClass->GetWidth().ValueResolved,ComponentClass->GetHeight().ValueResolved,ComponentClass->GetTexture(),OwnerScene);
    float Y = ComponentClass->GetY().ValueResolved;
    Rc->OriginX = ComponentClass->GetOriginX();
    Rc->OriginY = ComponentClass->GetOriginY();
    Rc->OriginalComponent = ComponentClass;
    ComponentClass->SetRenderComponent(Rc);
  SunCore::instance().SunEngineConfig->Render.RenderVector.push_back(Rc);

 }
     

      





  



void RunScene(Scene* RequestScene){

    
    RequestScene->State = SceneState::OnLoad;
    SunCore::instance().ScenesDiagrams.emplace(RequestScene->SceneID,RequestScene);
   
     

}

void ScenesLoop(){
 for(const auto& pair : SunCore::instance().ScenesDiagrams){
    Scene* SceneDiagram = pair.second; 
  
  switch (SceneDiagram->State){
  case SceneState::OnLoad:
    SceneDiagram->OnLoad();
    SceneDiagram->State = SceneState::OnInit;
  break;
 case SceneState::OnInit:
    SceneDiagram->OnInit();
    SceneDiagram->State = SceneState::OnUpdate;
break;
case SceneState::OnUpdate:
   SceneDiagram->OnUpdate();
break;
 }
}
}