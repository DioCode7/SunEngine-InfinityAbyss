#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include <variant>
#include <unordered_map>
#include "SunEngineCore.h"

void Scene::SceneConfigs() {}
void Scene::OnLoad() {}
void Scene::OnInit() {}
void Scene::OnUpdate() {}

SDL_Keycode TranslateSDLKey(KeyCodes Key){
 switch(Key){
  case KeyCodes::D:{
    return SDLK_d;
    break;
  }
  case KeyCodes::A:{
    return SDLK_a;
    break;
  }
  case KeyCodes::W:{
    return SDLK_w;
    break;
  }
  case KeyCodes::S:{
    return SDLK_s;
    break;
  }

 };
 return SDLK_UNKNOWN;
};


SDL_Scancode TranslateSDLScan(KeyCodes Key){
 switch(Key){
  case KeyCodes::D:{
    return SDL_SCANCODE_D;
    break;
  }
  case KeyCodes::S:{
    return SDL_SCANCODE_S;
    break;
  }
  case KeyCodes::A:{
    return SDL_SCANCODE_A;
    break;
  }
  case KeyCodes::W:{
    return SDL_SCANCODE_W;
    break;
  }

 };
 return SDL_SCANCODE_UNKNOWN;
};



void SunBodysControl::Update(){
 
};

std::string SunBodys::GetId(){
   return OwnerComponent->GetId();
};

void SunBodys::CreateStaticBody(std::string Id,std::unique_ptr<SunBodys> Body){
  SunCore::instance().SunWorld.AddNewStaticBody(Id,std::move(Body));
};


 class RenderComponentRectangle : public RenderComponentClass{
            public:
       
           RenderComponentRectangle(int PosX,int PosY,int W,int H, float R,float G,float B,float A,std::string Id,Scene* OwnerScene):
            RenderComponentClass(PosX,PosY,W,H, R, G, B,A,Id,OwnerScene){}
         
              void RenderMethod(float X,float Y,float W,float H,float R,float G,float B,float A,float BorderWidth,std::string TextureId = "None") override {


             
                
                GLuint Shader = SunCore::instance().Gl.ShaderProgram;
                float PosX;
                float PosY;
                float SizeX = (W / SunCore::instance().WindowWidth) * 2.0f;
                float SizeY = (H / SunCore::instance().WindowHeight) * 2.0f;

                float BorderWidthX = (BorderWidth / W);
                float BorderWidthY = (BorderWidth / H);
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
                      GLint uBorderWidth = SunCore::instance().Gl.UniformsLocations.uBorderWidth;
                   GLint uBorderColor = SunCore::instance().Gl.UniformsLocations.uBorderColor;

                  glUniform2f(uPosLoc,PosX,PosY);
                  glUniform2f(uSizeLoc,SizeX,SizeY);
                  glUniform2f(uBorderWidth,BorderWidthX,BorderWidthY);
                  glUniform4f(uColorLoc,R,G,B,A);
                  glUniform4f(uBorderColor,this->BorderColorR,this->BorderColorG,this->BorderColorB,this->BorderColorA);
                  glUniform1i(uShapeType,0);
                  glUniform1i(uUseTexture,0);

                
                glDrawArrays(GL_TRIANGLE_FAN,0,4);



 


                

            };
              
        };

void CreateRC(Component* ComponentClass,Component* Parent){

  auto ComponentNode = std::make_unique<NodeClass>();
  NodeClass* ParentNode = nullptr;
  if(Parent){
    ParentNode = Parent->GetOwner();
  }
  ComponentNode->Parent = ParentNode;
  ComponentNode->ComponentClass = ComponentClass;
    ComponentClass->SetOwner(std::move(ComponentNode));
  RenderComponentRectangle* Rc = new RenderComponentRectangle(ComponentClass->GetX().ValueResolved,
    ComponentClass->GetY().ValueResolved,ComponentClass->GetWidth().ValueResolved,ComponentClass->GetHeight().ValueResolved,
    ComponentClass->GetRGBA()->R,ComponentClass->GetRGBA()->G,ComponentClass->GetRGBA()->B,ComponentClass->GetRGBA()->A,ComponentClass->GetId(),nullptr);
    Rc->OriginX = ComponentClass->GetOriginX();
    Rc->OriginY = ComponentClass->GetOriginY();
    Rc->OriginalComponent = ComponentClass;
     ComponentClass->SetRenderComponent(Rc);


     
           
       
};

void Body::CreateBodyComponent(){
   UnitClass BodyW;
   BodyW.Unit = UnitType::Pixel;
   BodyW.Value = this->Width;
   UnitClass BodyH;
   BodyH.Unit = UnitType::Pixel;
   BodyH.Value = this->Height;
   UnitClass BodyX;
   BodyX.Unit = UnitType::Pixel;
   BodyX.Value = this->OffsetX;
   UnitClass BodyY;
   BodyY.Value = this->OffsetY;
   BodyY.Unit = UnitType::Pixel;
   OriginClass OriginX;
   if(this->Owner->OwnerComponent){
   OriginX = this->Owner->OwnerComponent->GetOriginX();
   }else{
     OriginX = OriginClass::Center;
   }
   OriginClass OriginY;
   if(this->Owner->OwnerComponent){
   OriginY =this->Owner->OwnerComponent->GetOriginY();
   }else{
     OriginY = OriginClass::Center;
   }
   BorderClass Border;
   Border.Width.Value = 1.0f;
   Border.Width.Unit = UnitType::Pixel;
   Border.Use = true;
   Border.A = 1.0f;
   Border.R = 0.0f;
   Border.B = 0.0f;
   Border.G = 1.0f;
   
  std::unique_ptr<Component> BodyComp = 
    std::make_unique<Component>(this->Id, BodyW, BodyH, BodyX, BodyY,OriginX,OriginY);
   BodyComp->SetBorder(Border);
   BodyComp->SetRGBA(0.0f,0.0f,0.0,0.0f);

   this->BodyComponent = std::move(BodyComp);

   if(this->Owner->OwnerComponent){
  CreateRC(this->BodyComponent.get(),this->Owner->OwnerComponent->GetOwner()->ComponentClass);
   }else{
      CreateRC(this->BodyComponent.get(),nullptr);
   }
   
   
};

void SunWorld::AddNewWorldComponent(std::unique_ptr<Component> NewComponent){
   WorldComponents.emplace(NewComponent->GetId(),std::move(NewComponent));
   };