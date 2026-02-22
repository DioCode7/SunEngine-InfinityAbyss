
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
         
              void RenderMethod(float X,float Y,float W,float H,float R,float G,float B,float A,std::string TextureId = "None") override {


             
                
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
                    GLint uShapeType = glGetUniformLocation(Shader,"ShapeType");
                    GLint uUseTexture = glGetUniformLocation(Shader,"uUseTexture");

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

                float PosX = (((X / SunCore::instance().WindowWidth)*2.0f)-1.0f) + (W / SunCore::instance().WindowWidth) / 2.0f;
                float PosY = 0.0f - (((Y / SunCore::instance().WindowHeight)*2.0f)-1.0f) - (H / SunCore::instance().WindowHeight) / 2.0f;

                float SizeX = (W / SunCore::instance().WindowWidth) * 2.0f;
                float SizeY = (H / SunCore::instance().WindowHeight) * 2.0f;



                glUseProgram(Shader);

           
                glBindVertexArray(SunCore::instance().Gl.VAO);

                 GLint uPosLoc = glGetUniformLocation(Shader,"uPos");
                  GLint uSizeLoc = glGetUniformLocation(Shader,"uSize");
                  GLint uColorLoc = glGetUniformLocation(Shader,"uColor");
                    GLint uShapeType = glGetUniformLocation(Shader,"ShapeType");
                     GLint uUseTexture = glGetUniformLocation(Shader,"uUseTexture");

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
    
   
  
                float PosX = (((X / SunCore::instance().WindowWidth)*2.0f)-1.0f) + (W / SunCore::instance().WindowWidth) / 2.0f;
                float PosY = 0.0f - (((Y / SunCore::instance().WindowHeight)*2.0f)-1.0f) - (H / SunCore::instance().WindowHeight) / 2.0f;

                float SizeX = (W / SunCore::instance().WindowWidth) * 2.0f;
                float SizeY = (H / SunCore::instance().WindowHeight) * 2.0f;



                glUseProgram(Shader);

           
                glBindVertexArray(SunCore::instance().Gl.VAO);

                 GLint uPosLoc = glGetUniformLocation(Shader,"uPos");
                  GLint uSizeLoc = glGetUniformLocation(Shader,"uSize");
                  GLint uColorLoc = glGetUniformLocation(Shader,"uColor");
                    GLint uShapeType = glGetUniformLocation(Shader,"ShapeType");
                    GLint uUseTexture = glGetUniformLocation(Shader,"uUseTexture");
                    GLint uTexture = glGetUniformLocation(Shader,"uTexture");
                    GLint uFlipY = glGetUniformLocation(Shader,"uFlipY");
                     GLint uFlipX = glGetUniformLocation(Shader,"uFlipX");

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


void ResolveComponent(Component* ComponentClass,Component* Parent){
  
 switch(ComponentClass->Width.Unit){
  case UnitType::Pixel:
  ComponentClass->Width.ValueResolved = ComponentClass->Width.Value;
  break;
  case UnitType::Percent:
  
  break;
 }
 switch(ComponentClass->Height.Unit){
  case UnitType::Pixel:
  ComponentClass->Height.ValueResolved = ComponentClass->Height.Value;
  break;
  case UnitType::Percent:
  
  break;
 }
 switch(ComponentClass->PosX.Unit){
  case UnitType::Pixel:
   if(Parent){
  float RelativeX = ComponentClass->PosX.Value; // começa do valor local

NodeClass* ActualNode = ComponentClass->Owner->Parent;

while (ActualNode) {
    RelativeX += ActualNode->ComponentClass->PosX.ValueResolved;
    std::cout << "RelativeX: ";
    std::cout << RelativeX;
    ActualNode = ActualNode->Parent;
}

ComponentClass->PosX.ValueResolved = RelativeX;
   ComponentClass->PosX.ValueResolved = RelativeX;
  }else{
  ComponentClass->PosX.ValueResolved = ComponentClass->PosX.Value;
  }
  break;
  case UnitType::Percent:
  
  break;
 }
  switch(ComponentClass->PosY.Unit){
  case UnitType::Pixel:
   if(Parent){
    float RelativeY = 0.0f;
    NodeClass* ActualNode;
    bool WhileFlag = true;
    ActualNode = ComponentClass->Owner;
  while(WhileFlag){
  RelativeY += ActualNode->ComponentClass->PosY.ValueResolved;
  if(!ActualNode->Parent){
  WhileFlag = false;
  }else{
  ActualNode = ActualNode->Parent;
  }
  }
   ComponentClass->PosY.ValueResolved = RelativeY;
  }else{
  ComponentClass->PosY.ValueResolved = ComponentClass->PosY.Value;
  }
  break;
  case UnitType::Percent:
  
  break;
 }
};
      
    void SunRender::AddRectangle(std::string Id,float PosX,float PosY,float Width,float Height,float R,float G,float B,float A,Scene* OwnerScene){
     
    RenderComponentRectangle* Rc = new RenderComponentRectangle(PosX,PosY,Width,Height,R,G,B,A,Id,OwnerScene);



      SunCore::instance().SunEngineConfig->Render.RenderVector.push_back(Rc);
     
           
           

        };
    
 void SunRender::AddCircle(std::string Id, float PosX, float PosY,float Radius,float R,float G,float B,float A,Scene* OwnerScene){
    RenderComponentCircle* Rc = new RenderComponentCircle(Radius,PosX,PosY,R,G,B,A,Id,OwnerScene);
    SunCore::instance().SunEngineConfig->Render.RenderVector.push_back(Rc);
 }      
 
 void SunRender::AddSprite(Component* ComponentClass,Scene* OwnerScene,Component* Parent){
  NodeClass* ComponentNode = new NodeClass();
  ComponentClass->Owner = ComponentNode;
  NodeClass* ParentNode = nullptr;
  if(Parent){
    ParentNode = Parent->Owner;
  }
  ComponentNode->Parent = ParentNode;
  ComponentNode->ComponentClass = ComponentClass;
  ResolveComponent(ComponentClass,Parent);
  RenderComponentSprite* Rc = new RenderComponentSprite(ComponentClass->Id,ComponentClass->PosX.ValueResolved,
    ComponentClass->PosY.ValueResolved,ComponentClass->Width.ValueResolved,ComponentClass->Height.ValueResolved,ComponentClass->Texture,OwnerScene);
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