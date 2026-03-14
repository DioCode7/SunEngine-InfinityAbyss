#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include <variant>
#include <unordered_map>
#include "SunEngineCore.h"
#include "SunRender.h"
#include "SunFunctions.h"
#include "SunAnimations.h"

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
    case KeyCodes::F1:{
    return SDLK_F1;
    break;
  }
   case KeyCodes::F2:{
    return SDLK_F2;;
    break;
  }
 case KeyCodes::F3:{
    return SDLK_F3;;
    break;
  }

   case KeyCodes::F4:{
    return SDLK_F4;
    break;
  }

   case KeyCodes::F5:{
    return SDLK_F5;
    break;
  }

   case KeyCodes::F6:{
    return SDLK_F6;
    break;
  }

   case KeyCodes::F7:{
    return SDLK_F7;
    break;
  }

   case KeyCodes::F8:{
    return SDLK_F8;
    break;
  }

   case KeyCodes::F9:{
    return SDLK_F9;
    break;
  }

   case KeyCodes::F10:{
return SDLK_F10;
    break;
  }

   case KeyCodes::F11:{
    return SDLK_F11;
    break;
  }

   case KeyCodes::F12:{
    return SDLK_F12;
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
  case KeyCodes::F1:{
    return SDL_SCANCODE_F1;
    break;
  }
   case KeyCodes::F2:{
    return SDL_SCANCODE_F2;
    break;
  }
 case KeyCodes::F3:{
    return SDL_SCANCODE_F3;
    break;
  }

   case KeyCodes::F4:{
    return SDL_SCANCODE_F4;
    break;
  }

   case KeyCodes::F5:{
    return SDL_SCANCODE_F5;
    break;
  }

   case KeyCodes::F6:{
    return SDL_SCANCODE_F6;
    break;
  }

   case KeyCodes::F7:{
    return SDL_SCANCODE_F7;
    break;
  }

    case KeyCodes::F8:{
    return SDL_SCANCODE_F8;
    break;
  }

   case KeyCodes::F9:{
    return SDL_SCANCODE_F9;
    break;
  }

   case KeyCodes::F10:{
    return SDL_SCANCODE_F10;
    break;
  }

   case KeyCodes::F11:{
    return SDL_SCANCODE_F11;
    break;
  }

   case KeyCodes::F12:{
    return SDL_SCANCODE_F12;
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
  StaticBody = true;
  for(auto& b:Bodys){
    if(b.second->GetBodySunPhysics()){
      b.second->GetBodySunPhysics()->SetIgnoreGravity(true);
    }
    
  }
  SunCore::instance().SunWorld.AddNewStaticBody(Id,std::move(Body));
};


 class RenderComponentRectangle : public RenderComponentClass{
            public:
       
           RenderComponentRectangle(int PosX,int PosY,int W,int H, float R,float G,float B,float A,std::string Id,Scene* OwnerScene):
            RenderComponentClass(PosX,PosY,W,H, R, G, B,A,Id,OwnerScene){}
       
              void RenderMethod() override {


             
                
                GLuint Shader = SunCore::instance().Gl.ShaderProgram;
                float PosX;
                float PosY;
                float SizeX = ((Width * SunCore::instance().Camera.Zoom) / SunCore::instance().WindowWidth) * 2.0f;
                float SizeY = ((Height * SunCore::instance().Camera.Zoom) / SunCore::instance().WindowHeight) * 2.0f;

                float BorderWidthX = (BorderWidth / Width);
                float BorderWidthY = (BorderWidth / Height);
                switch(this->OriginX){
                case OriginClass::Center:
                PosX = ((((X - SunCore::instance().Camera.GetX()) / SunCore::instance().WindowWidth)*2.0f)-1.0f);
                break;
                case OriginClass::Start:
                  PosX = ((((X - SunCore::instance().Camera.GetX()) / SunCore::instance().WindowWidth)*2.0f)-1.0f) + (SizeX / 2.0f);
                break;
                 case OriginClass::End:
                  PosX = ((((X - SunCore::instance().Camera.GetX()) / SunCore::instance().WindowWidth)*2.0f)-1.0f) - (SizeX / 2.0f);
                break;
               }
               switch(this->OriginY){
                case OriginClass::Center:
                 PosY = 0.0f - ((((Y - SunCore::instance().Camera.GetY()) / SunCore::instance().WindowHeight)*2.0f)-1.0f);
                 break;
                 case OriginClass::Start:
                 PosY = 0.0f - ((((Y - SunCore::instance().Camera.GetY()) / SunCore::instance().WindowHeight)*2.0f)-1.0f) - (SizeY / 2.0f);
                 break;
                  case OriginClass::End:
                 PosY = 0.0f - ((((Y - - SunCore::instance().Camera.GetY()) / SunCore::instance().WindowHeight)*2.0f)-1.0f) + (SizeY / 2.0f);
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
    ComponentClass->GetRGBA().R,ComponentClass->GetRGBA().G,ComponentClass->GetRGBA().B,ComponentClass->GetRGBA().A,ComponentClass->GetId(),nullptr);
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
     OriginX = OriginClass::Start;
   }
   OriginClass OriginY;
   if(this->Owner->OwnerComponent){
   OriginY =this->Owner->OwnerComponent->GetOriginY();
   }else{
     OriginY = OriginClass::Start;
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
   BodyComp->SetLayer(20000);
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


 bool VerifyQuadColidesCalc(Body* A,Body* B){
  bool Verify = false;
   if(A == nullptr || B == nullptr){
    std::cout << "Body null\n";
    return false;
}

if(A->Owner == nullptr || B->Owner == nullptr){
    std::cout << "Owner null\n";
    return false;
}
  if(A->GetCollisionLayer() == nullptr || B->GetCollisionLayer() == nullptr){
    Verify = false;
  }else{
   auto& collidesWith = A->GetCollisionLayer()->GetCollidesWith();
auto it = collidesWith.find(B->GetCollisionLayer()->Id);

if(it != collidesWith.end()){
  Verify = true;
  }
}

//if(A->Owner->GetStatic() && B->Owner->GetStatic()){
  //Verify = false;
//}
  if(Verify){
     float Ax,Ay,Aw,Ah;
   float Bx,By,Bw,Bh;

   

if(A->Owner->GetStatic() || !A->Owner->OwnerComponent){
    Ax = A->OffsetX;
    Ay = A->OffsetY;
    Aw = A->Width;
    Ah = A->Height;
   }else{
   Ax = A->Owner->OwnerComponent->GetX().RenderValue + A->OffsetX;
   Ay = A->Owner->OwnerComponent->GetY().RenderValue + A->OffsetY;
   Aw = A->Width;
    Ah = A->Height;
    if(A->Owner->OwnerComponent->GetOriginX() == OriginClass::Center){
   Ax -= Aw / 2;
    }else if(A->Owner->OwnerComponent->GetOriginX() == OriginClass::End){
  Ax -= Aw;

    };
       if(A->Owner->OwnerComponent->GetOriginY() == OriginClass::Center){
   Ay -= Ah / 2;
    }else if(A->Owner->OwnerComponent->GetOriginY() == OriginClass::End){
  Ay -= Ah;
    };
   }
    if(B->Owner->GetStatic() || !B->Owner->OwnerComponent){
    Bx = B->OffsetX;
    By = B->OffsetY;
    Bw = B->Width;
    Bh = B->Height;
   }else{
   Bx = B->Owner->OwnerComponent->GetX().RenderValue + B->OffsetX;
   By = B->Owner->OwnerComponent->GetY().RenderValue + B->OffsetY;
   Bw = B->Width;
    Bh = B->Height;
         if(B->Owner->OwnerComponent->GetOriginX() == OriginClass::Center){
    Bx -= Bw / 2;
    }else if(B->Owner->OwnerComponent->GetOriginX() == OriginClass::End){
   Bx -= Bw;


    };
       if(B->Owner->OwnerComponent->GetOriginY() == OriginClass::Center){
     By -= Bh / 2;
    }else if(B->Owner->OwnerComponent->GetOriginY() == OriginClass::End){
   By -= Bh;
   }

 
  }
   std::cout << "\n BodyB X:" << Bx <<"\n";
   
   std::cout << "\n BodyA X:" << Ax <<"\n";
    
  bool XCollides = (Ax < Bx + Bw) && (Ax + Aw > Bx);
bool YCollides = (Ay < By + Bh) && (Ay + Ah > By);
 
if(XCollides && YCollides){
  return true;
}
return false;


  }

 return false;
  
 };  
 
 void SunCollisionPhysicCollision(Body* A,Body* B){
  auto* phys = A->GetBodySunPhysics();
  auto* physB = B->GetBodySunPhysics();

    if (!phys || !physB) return;

   
   std::cout << "Entrando No Calcullllll";
    float Acx = A->WorldX + A->Width * 0.5f;
    float Acy = A->WorldY + A->Height * 0.5f;
    float Bcx = B->WorldX + B->Width * 0.5f;
    float Bcy = B->WorldY + B->Height * 0.5f;

    float dx = Acx - Bcx;
    float dy = Acy - Bcy;

    float px = (A->Width * 0.5f + B->Width * 0.5f) - std::abs(dx);
    float py = (A->Height * 0.5f + B->Height * 0.5f) - std::abs(dy);

   

    UnitClass newPos;
    vector2 vel;
    Body* ActiveForceX = A;
    Body* ReactiveForceX = B;

    float beta = 0.1f;
    bool test = px < py;
   std::cout << test;
    if (px < py)
    {
   
        float sx = (dx < 0) ? -1.f : 1.f;

        if(A->Owner->OwnerComponent){
        newPos = A->Owner->OwnerComponent->GetX();
            float slop = 0.05f;
        float correction = std::max(px - slop,0.0f) * beta;
        newPos.ValueResolved += correction * sx;
        A->Owner->OwnerComponent->SetX(newPos);
        }else if(!A->Owner->OwnerComponent && B->Owner->OwnerComponent){
            newPos = B->Owner->OwnerComponent->GetX();
            float slop = 0.05f;
               float correction = std::max(px - slop,0.0f) * beta;
        newPos.ValueResolved += correction * sx;
        B->Owner->OwnerComponent->SetX(newPos);
        }
         
        vel.y = phys->GetVelocity().y;
       float vRel = phys->GetVelocity().x - physB->GetVelocity().x;



float invMassA = 1.0f / phys->GetMass();
float invMassB = 1.0f / physB->GetMass();

float j = -(vRel) / (invMassA + invMassB);
 vector2 vja;
 vector2 vjb;
 vja.y =  phys->GetVelocity().y;
 vjb.y =  physB->GetVelocity().y;
 vja.x = phys->GetVelocity().x + j * invMassA;
  vjb.x = physB->GetVelocity().x - j * invMassB;
phys->SetVelocity(vja);
physB->SetVelocity(vjb);

      
    }
    else
    {
        float sy = (dy < 0) ? -1.f : 1.f;
         if (sy > 0 && py < 2.0f){
    vector2 vel = phys->GetVelocity();
    vel.y = 0.0f;
    phys->SetVelocity(vel);
    physB->SetVelocity(vel);

    phys->OnGround = true;
     physB->OnGround = true;
}


        if(A->Owner->OwnerComponent){
        newPos = A->Owner->OwnerComponent->GetY();
  float slop = 0.08f;
               float correction = std::max(py - slop,0.0f) * beta;
        newPos.ValueResolved += correction * sy;
        A->Owner->OwnerComponent->SetY(newPos);
        }else if(!A->Owner->OwnerComponent && B->Owner->OwnerComponent){
            newPos = B->Owner->OwnerComponent->GetY();
            float slop = 0.08f;
               float correction = std::max(py - slop,0.0f) * beta;
        newPos.ValueResolved += correction * sy;
        B->Owner->OwnerComponent->SetY(newPos);
        }
            vel.x = phys->GetVelocity().x;
           
        float vRel = phys->GetVelocity().y - physB->GetVelocity().y;
        


float invMassA = 1.0f / phys->GetMass();
float invMassB = 1.0f / physB->GetMass();

float j = -(vRel) / (invMassA + invMassB);
 vector2 vja;
 vector2 vjb;
 vja.x =  phys->GetVelocity().x;
 vjb.x =  physB->GetVelocity().x;
 vja.y = 0.0;
  vjb.y = 0.0;
phys->SetVelocity(vja);
physB->SetVelocity(vjb);
    }
     

    
 };

 void ArcadeCollisionPhysicCollision(Body* A,Body* B){
  auto* phys = A->GetBodyArcadePhysics();
  
    if (!phys) return;
   std::cout << "Entrando No Calcullllll";
    float Acx = A->WorldX + A->Width * 0.5f;
    float Acy = A->WorldY + A->Height * 0.5f;
    float Bcx = B->WorldX + B->Width * 0.5f;
    float Bcy = B->WorldY + B->Height * 0.5f;

    float dx = Acx - Bcx;
    float dy = Acy - Bcy;

    float px = (A->Width * 0.5f + B->Width * 0.5f) - std::abs(dx);
    float py = (A->Height * 0.5f + B->Height * 0.5f) - std::abs(dy);

   

    UnitClass newPos;
    vector2 vel;
    bool test = px < py;
   std::cout << test;
    if (px < py)
    {
        float sx = (dx < 0) ? -1.f : 1.f;

        newPos = A->Owner->OwnerComponent->GetX();
        newPos.ValueResolved += px * sx;
        A->Owner->OwnerComponent->SetX(newPos);

          vel.x = 0.0f;
        vel.y = phys->GetVelocity().y;
        phys->SetVelocity(vel);
    }
    else
    {
        float sy = (dy < 0) ? -1.f : 1.f;

        newPos = A->Owner->OwnerComponent->GetY();
        newPos.ValueResolved += py * sy;
        A->Owner->OwnerComponent->SetY(newPos);

            vel.x = phys->GetVelocity().x;
            vel.y = 0.0f;
        phys->SetVelocity(vel);
    }
     

    
 };

  void ArcadeCollisionSensorCollision(Body* A,Body* B){

 };

  void SunCollisionSensorCollision(Body* A,Body* B){

 };

 void ArcadeCollisionMethods(Body* A,Body* B){
  
  if(A->CollissionType == CollisionsTypes::Solid && B->CollissionType == CollisionsTypes::Solid ){
  ArcadeCollisionPhysicCollision(A,B);
  };
   if(A->CollissionType == CollisionsTypes::Trigger || B->CollissionType == CollisionsTypes::Trigger ){
  ArcadeCollisionSensorCollision(A,B);
  }
 };

  void SunCollisionMethods(Body* A,Body* B){
  
  if(A->CollissionType == CollisionsTypes::Solid && B->CollissionType == CollisionsTypes::Solid ){
  SunCollisionPhysicCollision(A,B);
  };
   if(A->CollissionType == CollisionsTypes::Trigger || B->CollissionType == CollisionsTypes::Trigger ){
  SunCollisionSensorCollision(A,B);
  }
 };



void VerifyQuadCollisions(Body* A){
 auto& WorldGrid = SunCore::instance().SunWorld.CollisionsWorld.GetWorldGrid();
    float CellWidth = SunCore::instance().SunWorld.WorldGridCellsWidth;
    

    
int cellXStart = floor(A->WorldX / CellWidth);
int cellYStart = floor(A->WorldY / CellWidth);

int cellXEnd = floor((A->WorldX + A->Width) / CellWidth);
int cellYEnd = floor((A->WorldY + A->Height) / CellWidth);
   for(int cellX = cellXStart - 1;cellX <= cellXEnd + 1;cellX++){
      for(int cellY = cellYStart - 1;cellY <= cellYEnd + 1;cellY++){
      
        int x = cellX;
        int y = cellY;
            WorldGridCell cell{x,y};

            auto it = WorldGrid.find(cell);
            if(it == WorldGrid.end()) continue;
       
            for(Body* B : it->second){
             
                if(A == B) continue;
              //  if(!A->Owner->OwnerComponent && !B->Owner->OwnerComponent){
                //  continue;
                //}
                 
                if(!B->Collides || B->CollissionType == CollisionsTypes::None) continue;
               
                bool IsCollides = VerifyQuadColidesCalc(A,B);

                if(IsCollides){
                  std::cout << "//Colisao: " << "  //  ";
                  if(SunCore::instance().SunWorld.CollisionsWorld.CollisionPhysic == CollisionPhysicTypes::Arcade){
                  ArcadeCollisionMethods(A,B);
                  }
                     if(SunCore::instance().SunWorld.CollisionsWorld.CollisionPhysic == CollisionPhysicTypes::SunPhysic){
                  SunCollisionMethods(A,B);
                  }
                }else{
                  continue;
                }
            }
        
    
  }
}
};  

   void CollisionsWorld::CollisionsUpdate(float DeltaTime){

  WorldGrid.clear();
     for(auto& CollidesBody : SunCore::instance().BodysControl.GetSunBodysVector()){
        for(auto& InnerBody : CollidesBody->GetBodysMap()){
            AddNewBodyToWorld(InnerBody.second.get());
        }
    }
    
    
    for(auto& CollidesBody : SunCore::instance().BodysControl.GetSunBodysVector()){
      for(auto& InnerBody : CollidesBody->GetBodysMap()){
        if(InnerBody.second.get()->Collides && InnerBody.second.get()->CollissionType != CollisionsTypes::None && !CollidesBody->GetStatic()){
    VerifyQuadCollisions(InnerBody.second.get());

    if(InnerBody.second->GetBodySunPhysics()){
 InnerBody.second->GetBodySunPhysics()->OnGround = false;
    };
        }
      }
    }; 

    

      
  };
  void SunBodysControl::AddSunBody(SunBodys* Body){
  std::cout << "AddSunBody: " << Body << "\n";
 BodysVector.push_back(Body);
  if(!Body->OwnerComponent){
    for( auto& b : Body->GetBodysMap()){
    b.second->WorldX = b.second->OffsetX;
    b.second->WorldY = b.second->OffsetY;
    }
  }
 for(auto& B : Body->GetBodysMap()){
 SunWorld::instance().CollisionsWorld.AddNewBodyToWorld(B.second.get());
}
};


  void CollisionsWorld::AddNewBodyToWorld(Body* Body){
 float CellWidth = SunCore::instance().SunWorld.WorldGridCellsWidth;
 float WorldX = Body->WorldX;
 float WorldY = Body->WorldY;
 
 int startX = floor(Body->WorldX / CellWidth);
int startY = floor(Body->WorldY / CellWidth);

int endX = floor((Body->WorldX + Body->Width) / CellWidth);
int endY = floor((Body->WorldY + Body->Height) / CellWidth);

for(int x = startX; x <= endX; x++){
    for(int y = startY; y <= endY; y++){
        WorldGridCell cell{x,y};
       // std::cout << "\nWorlsGrid Cells:  " << "ID:  " << Body->Id << "  X:  " << x << "  Y:  " << y << "\n"; 
        WorldGrid[cell].push_back(Body);
    }
}


  };



  void Body::SetCollisionLayer(std::string Cl){
   auto It = SunCore::instance().SunWorld.CollisionsWorld.GetCollisionLayersMap().find(Cl);
   if(It !=SunCore::instance().SunWorld.CollisionsWorld.GetCollisionLayersMap().end()){
     BodyCollisionLayer = SunCore::instance().SunWorld.CollisionsWorld.GetCollisionLayersMap().find(Cl)->second.get();
   }else{
   std::cout << "Collision Layer don't Registred" << "\n";
   };
  };

  void CollisionsWorld::PhysicUpdate(float DeltaTime){
    if(SunCore::instance().SunWorld.CollisionsWorld.CollisionPhysic == CollisionPhysicTypes::Arcade){
  for(auto& CollidesBody : SunCore::instance().BodysControl.GetSunBodysVector()){
        for(auto& InnerBody : CollidesBody->GetBodysMap()){
          
          if(InnerBody.second->GetBodyArcadePhysics()){
            InnerBody.second->GetBodyArcadePhysics()->PhysicResolve(DeltaTime);
          }
        }
    }

  };
  if(SunCore::instance().SunWorld.CollisionsWorld.CollisionPhysic == CollisionPhysicTypes::SunPhysic){
  for(auto& CollidesBody : SunCore::instance().BodysControl.GetSunBodysVector()){
        for(auto& InnerBody : CollidesBody->GetBodysMap()){
          if(InnerBody.second->GetBodySunPhysics()){
            if(!InnerBody.second->GetBodySunPhysics()->Sleeping && InnerBody.second->Owner->OwnerComponent){
            InnerBody.second->GetBodySunPhysics()->PhysicResolve(DeltaTime);
            }
          }
        }
    }
   
  }
  
  };

  void BodyArcadePhysic::PhysicResolve(float DeltaTime){
//std::cout << "Resolvendo a fisica \n";

vector2 Accelleration;
vector2 Position;

  Accelleration.x = this->GetAccumulatedForces().x / GetMass();
  Accelleration.y = this->GetAccumulatedForces().y / GetMass();
  Velocity.x += Accelleration.x * DeltaTime;
  Velocity.y += Accelleration.y * DeltaTime;
  Position.x = Velocity.x * DeltaTime;
  Position.y = Velocity.y * DeltaTime;
  AccumulatedForces.x = 0.0f;
  AccumulatedForces.y = 0.0f;

  if(Owner){
    UnitClass X;
    X.Unit = UnitType::Pixel;
    X.Value =  Owner->Owner->OwnerComponent->GetX().ValueResolved + Position.x;
    Owner->Owner->OwnerComponent->SetX(X);

     UnitClass Y;
    Y.Unit = UnitType::Pixel;
    Y.Value = Owner->Owner->OwnerComponent->GetY().ValueResolved + Position.y;
    Owner->Owner->OwnerComponent->SetY(Y);
  };

  float damping = 1.0f - (2.0f * DeltaTime);
Velocity.x *= damping;
Velocity.y *= damping;
};


  void BodySunPhysic::PhysicResolve(float DeltaTime){
//std::cout << "Resolvendo a fisica \n";

vector2 Accelleration;
vector2 Position;
vector2 gravity;
gravity.x = 0.0;
gravity.y = SunCore::instance().SunWorld.SunGravity.GetGravity();
if(!this->GetIgnoreGravity() && !OnGround){
  this->AddForce(gravity);
}

  Accelleration.x = this->GetAccumulatedForces().x / GetMass();
  Accelleration.y = this->GetAccumulatedForces().y / GetMass();
  
  Velocity.x += Accelleration.x * DeltaTime;
  Velocity.y += Accelleration.y * DeltaTime;
  if(OnGround && Velocity.y > 0)
{
    Velocity.y = 0;
}
  Position.x = Velocity.x * DeltaTime;
  Position.y = Velocity.y * DeltaTime;
  AccumulatedForces.x = 0.0f;
  AccumulatedForces.y = 0.0f;
if(std::abs(Velocity.x) < 0.01f && std::abs(Velocity.y) < 0.01f){
    SleepTimer += DeltaTime;
    
    if(SleepTimer > 0.5f){
        Sleeping = true;
    }
}else{
    SleepTimer = 0.0f;
    Sleeping = false;
}
  if(Owner->Owner->OwnerComponent){
    UnitClass X;
    X.Unit = UnitType::Pixel;
    X.Value =  Owner->Owner->OwnerComponent->GetX().ValueResolved + Position.x;
    Owner->Owner->OwnerComponent->SetX(X);

     UnitClass Y;
    Y.Unit = UnitType::Pixel;
    Y.Value = Owner->Owner->OwnerComponent->GetY().ValueResolved + Position.y;
    Owner->Owner->OwnerComponent->SetY(Y);
  };

  float damping = pow(0.99f, DeltaTime * 60.0f);
 if(Accelleration.x < 0.05f){
    Velocity.x *= damping;
}
//Velocity.y *= damping;
};
 void SunWorld::AddMaterialToWorld(std::string MaterialId,std::string ShaderId){
      std::unique_ptr<Material> material = std::make_unique<Material>();
      material->Shader = SunCore::instance().SunShaders.GetShader(ShaderId);
      Materials.emplace(MaterialId,std::move(material));

    };
void Material::Apply(RenderComponentClass* rc,float t,float dt){
    
   auto Sh = Shader->GetShaderProgram();
    int ti = 0;

    glUseProgram(Sh);
    glBindVertexArray(Shader->GetVAO());

    vector2 UvStart;
    UvStart.x = 0.0f;
    UvStart.y = 0.0f;
    vector2 UvEnd;
    UvEnd.x = 1.0f;
    UvEnd.y = 1.0f;
    float xpos = rc->OriginalComponent->GetX().RenderValue - SunCore::instance().Camera.GetX();
     float ypos = rc->OriginalComponent->GetY().RenderValue - SunCore::instance().Camera.GetY();
      float h = rc->OriginalComponent->GetHeight().RenderValue * SunCore::instance().Camera.Zoom;
 float w = rc->OriginalComponent->GetWidth().RenderValue * SunCore::instance().Camera.Zoom;





 float vertices[] = {
    xpos,     ypos + h,   0.0f, 0.0f, 1.0f,
    xpos,     ypos,       0.0f, 0.0f, 0.0f,
    xpos + w, ypos,       0.0f, 1.0f, 0.0f,
    xpos + w, ypos + h,   0.0f, 1.0f, 1.0f,
};

    glBindBuffer(GL_ARRAY_BUFFER, Shader->GetVBO());
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    
  for(auto& su : Shader->GetSunUniforms()){

   switch(su.first){
   case SunUniformsTypes::uSunPos:{
   glUniform2f(su.second,rc->X,rc->Y);
   break;
   }
    case SunUniformsTypes::uSunSize:{
   glUniform2f(su.second,rc->Width,rc->Height);
   break;
   }
   case SunUniformsTypes::uSunProjection:{
 float Ortho[16] = {
    2.0f / SunCore::instance().WindowWidth, 0, 0, 0,
    0, -2.0f / SunCore::instance().WindowHeight, 0, 0,
    0, 0, -1, 0,
    -1, 1, 0, 1
};
 
  glUniformMatrix4fv(su.second,1,GL_FALSE,Ortho);

    break;
   }
   case SunUniformsTypes::uSunTime:{
    glUniform1f(su.second,t);
    break;
   }
   case SunUniformsTypes::uSunTexture:{
    auto tex = SunCore::instance().SunRenderCore.GetTexture(rc->TextureId)->GPUID;
     if(rc->OriginalComponent->GetAnimation()){
    tex = SunCore::instance().SunRenderCore.GetTexture
    (rc->OriginalComponent->GetAnimation()->GetFrames()[rc->OriginalComponent->GetAnimation()->GetActualFrame()])->GPUID;
    rc->OriginalComponent->GetAnimation()->UpdateActualFrame();
     }
    glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D,tex);
   glUniform1i(su.second,0);
 
    ti++;
    break;
   }
 case SunUniformsTypes::uSunTextureMask:{
     
    glActiveTexture(GL_TEXTURE1);
   glBindTexture(GL_TEXTURE_2D,SunCore::instance().SunRenderCore.GetTexture(rc->TextureMask)->GPUID);
   glUniform1i(su.second,1);
 
    ti++;
    break;
   }
   case SunUniformsTypes::uSunStartTime:{
     
    break;
   };
   };
  };



  
   for(auto& fu : FloatUniforms){
     
    auto u = Shader->GetUniform(fu.first);
    float f = fu.second;

    glUniform1f(u->Location,f);

   };
    

   for(auto& tfu : TwoFloatsUniforms){
   auto u = Shader->GetUniform(tfu.first);
    vector2 f = tfu.second;

    glUniform2f(u->Location,f.x,f.y);
   };

   
   for(auto& thfu : ThreeFloatUniforms){
   auto u = Shader->GetUniform(thfu.first);
    vector3 f = thfu.second;

    glUniform3f(u->Location,f.x,f.y,f.z);
   };

   
   for(auto& ffu : FourFloatUniforms){
   auto u = Shader->GetUniform(ffu.first);
    vector4 f = ffu.second;

    glUniform4f(u->Location,f.x,f.y,f.z,f.xy);
   };
 
   for(auto& tu : TexturesUniforms){
   auto u = Shader->GetUniform(tu.first);
         glActiveTexture(GL_TEXTURE0 + ti);
   glBindTexture(GL_TEXTURE_2D,tu.second->GPUID);
   glUniform1i(u->Location,ti);
   ti++;
   };

   for(auto& fu : rc->OriginalComponent->GetMaterialUniforms()->GetFloatsUniforms()){
     
    auto u = Shader->GetUniform(fu.first);
    float f = fu.second;

    glUniform1f(u->Location,f);

   };
    

   for(auto& tfu : rc->OriginalComponent->GetMaterialUniforms()->GetTwoFloatsUniforms()){
   auto u = Shader->GetUniform(tfu.first);
    vector2 f = tfu.second;

    glUniform2f(u->Location,f.x,f.y);
   };

   
   for(auto& thfu : rc->OriginalComponent->GetMaterialUniforms()->GetThreeFloatsUniforms()){
   auto u = Shader->GetUniform(thfu.first);
    vector3 f = thfu.second;

    glUniform3f(u->Location,f.x,f.y,f.z);
   };

   
   for(auto& ffu : rc->OriginalComponent->GetMaterialUniforms()->GetFourFloatsUniforms()){
   auto u = Shader->GetUniform(ffu.first);
    vector4 f = ffu.second;

    glUniform4f(u->Location,f.x,f.y,f.z,f.xy);
   };
 
   for(auto& tu : rc->OriginalComponent->GetMaterialUniforms()->GetTexturesUniforms()){
   auto u = Shader->GetUniform(tu.first);
         glActiveTexture(GL_TEXTURE0 + ti);
   glBindTexture(GL_TEXTURE_2D,tu.second->GPUID);
   glUniform1i(u->Location,ti);
   ti++;
   };

  switch(BlendMode){
   case BlendOptions::Alpha:{
      glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    break;
   }
   case BlendOptions::Add:{
    glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    break;
   }
   case BlendOptions::None:{
        glDisable(GL_BLEND);
    break;
   }
  }
  

  
  glDrawArrays(GL_TRIANGLE_FAN,0,4);
};


void Material::AddTextureUniform(std::string Id,std::string TextureId){
 auto it = SunCore::instance().SunRenderCore.GetTexture(TextureId);
 TexturesUniforms.emplace(Id,it);
};

void SunShadersCore::AddShaderToWorld(std::string Id,std::unique_ptr<SunShader> s){
    auto uSunPos = glGetUniformLocation(s->GetShaderProgram(),"uSunPos");
    auto uSunSize = glGetUniformLocation(s->GetShaderProgram(),"uSunSize");
    auto uSunProjection = glGetUniformLocation(s->GetShaderProgram(),"uSunProjection");
    auto uSunTime = glGetUniformLocation(s->GetShaderProgram(),"uSunTime");
     auto uSunTexture = glGetUniformLocation(s->GetShaderProgram(),"uSunTexture");
          auto uSunTextureMask = glGetUniformLocation(s->GetShaderProgram(),"uSunTextureMask");
          auto uSunStartTime = glGetUniformLocation(s->GetShaderProgram(),"uSunStartTime");
    if(uSunPos != -1){
    s->AddSunUniform(SunUniformsTypes::uSunPos,uSunPos);
    };
    if(uSunSize != -1){
     s->AddSunUniform(SunUniformsTypes::uSunSize,uSunSize);
    };
    if(uSunProjection != -1){
      s->AddSunUniform(SunUniformsTypes::uSunProjection,uSunProjection);
    }
    if(uSunTime != -1){
s->AddSunUniform(SunUniformsTypes::uSunTime,uSunTime);
    }
 if(uSunTexture != -1){
s->AddSunUniform(SunUniformsTypes::uSunTexture,uSunTexture);
    }

     if(uSunTextureMask != -1){
s->AddSunUniform(SunUniformsTypes::uSunTextureMask,uSunTextureMask);
    }

    if(uSunStartTime != -1){
      s->AddSunUniform(SunUniformsTypes::uSunStartTime,uSunStartTime);
    }

     CreateComponentVAO(s.get());
    

     Shaders.emplace(Id,std::move(s));
   };



  int TranslateMouseButton(MouseButtons b){
   switch(b){
    case MouseButtons::LMB:
    return 1;
    break;
    case MouseButtons::RMB:
    return 2;
    break;
   }
   return 0;
  };


  int TranslateKeyboardEventTrigger(KeyboardTriggersType t){
switch(t){
  case KeyboardTriggersType::KeyDown:
  return SDL_KEYDOWN;
  break;
   case KeyboardTriggersType::KeyUp:
  return SDL_KEYUP;
  break;
   case KeyboardTriggersType::KeyHeld:
  return 0;
  break;
}
return 0;
  };
int TranslateMouseEventTrigger(MouseTriggersType t){
  switch(t){
 case MouseTriggersType::PointerDown:
  return SDL_MOUSEBUTTONDOWN;
  break;
   case MouseTriggersType::PointerUp:
  return SDL_MOUSEBUTTONUP;
  break;
   case MouseTriggersType::MouseIn:
  return SDL_MOUSEMOTION;
  break;
  case MouseTriggersType::MouseOut:
  return SDL_MOUSEMOTION;
  break;
  case MouseTriggersType::MouseOn:
  return SDL_MOUSEMOTION;
  break;
}
return 0;
};


void SunAnimation::SetStartTime(){
  if(!Active){
StartTime = SunCore::instance().SunTime.GetTime();
Active = true;  
}
};

void PopUpComponent::SetPopUpContainer(std::unique_ptr<Component> c,ComponentType ct){
  SunRender sr;
switch(ct){
  case ComponentType::Rectangle:{
    std::string id = c->GetId();
    sr.AddRectangle(std::move(c),OwnerScene);
    PopUpContainer = SunCore::instance().SunWorld.GetWorldComponentsMap().find(id)->second.get();
  PopUpContainer->SetDisplay(DisplayType::None);
   break;
  }
   case ComponentType::Sprite:{
    std::string id = c->GetId();
    sr.AddSprite(std::move(c),OwnerScene);
    PopUpContainer = SunCore::instance().SunWorld.GetWorldComponentsMap().find(id)->second.get();
    PopUpContainer->SetDisplay(DisplayType::None);
   break;
  }
   case ComponentType::Circle:{
    std::string id = c->GetId();
    sr.AddCircle(std::move(c),OwnerScene);
    PopUpContainer = SunCore::instance().SunWorld.GetWorldComponentsMap().find(id)->second.get();
    PopUpContainer->SetDisplay(DisplayType::None);
   break;
  }
}
};


void PopUpComponent::AddNewChildren(std::unique_ptr<Component> c,ComponentType ct,PopUpAdditionalConfigs config){
SunRender sr;
switch(ct){
  case ComponentType::Rectangle:{
    std::string id = c->GetId();
    sr.AddRectangle(std::move(c),OwnerScene,config.Parent);
     PopUpChildrens.emplace(id,SunCore::instance().SunWorld.GetWorldComponentsMap().find(id)->second.get());
   break;
  }
   case ComponentType::Sprite:{
    std::string id = c->GetId();
    sr.AddSprite(std::move(c),OwnerScene,config.Parent);
   PopUpChildrens.emplace(id,SunCore::instance().SunWorld.GetWorldComponentsMap().find(id)->second.get());
   break;
  }
   case ComponentType::Circle:{
    std::string id = c->GetId();
    sr.AddCircle(std::move(c),OwnerScene,config.Parent);
 PopUpChildrens.emplace(id,SunCore::instance().SunWorld.GetWorldComponentsMap().find(id)->second.get());
   break;
  }
   case ComponentType::Text:{
    std::string id = c->GetId();
    sr.AddText(std::move(c),config.Font,config.Text,OwnerScene,config.Parent);
 PopUpChildrens.emplace(id,SunCore::instance().SunWorld.GetWorldComponentsMap().find(id)->second.get());
   break;
  }
}
};


void PopUpComponent::ShowPopUp(){
   for(auto& c : PopUpContainer->GetOwner()->Childrens){
       c->ComponentClass->SetDisplay(DisplayType::None);
      c->ComponentClass->SetRenderDisplay(DisplayType::None);
    }
    PopUpContainer->SetDisplay(DisplayType::Absolute);
    if(EntryAnimationBool){
      SunAnimationsRender Sar;
       Sar.PlayAnimation(PopUpContainer->GetId(),EntryAnimation);
    }
   

    ChildsStartTime = SunCore::instance().SunTime.GetTime();
    ChildsAwait = true;
    
};

void PopUpComponent::Update(){
if(!ChildsAwait) return;

if(ChildsStartTime + EntryChildsDelay < SunCore::instance().SunTime.GetTime()){

for(auto& c : PopUpContainer->GetOwner()->Childrens){
      c->ComponentClass->SetDisplay(DisplayType::Absolute);
    }
    ChildsAwait = false;
};
}

void PopUpComponent::DisablePopUp(){
  if(ChildsInstantLeave){
    for(auto& c : PopUpContainer->GetOwner()->Childrens){
      c->ComponentClass->SetDisplay(DisplayType::None);
       c->ComponentClass->SetRenderDisplay(DisplayType::None);
    }
  }
    if(LeaveAnimationBool){
      SunAnimationsRender Sar;
      Component* PopUpContainerptr = PopUpContainer;
      LeaveAnimation.OnFinish = [PopUpContainerptr](SunEvent& e){
        PopUpContainerptr->SetDisplay(DisplayType::None);
  
      };
       Sar.PlayAnimation(PopUpContainer->GetId(),LeaveAnimation);
    }
    else{
    PopUpContainer->SetDisplay(DisplayType::None);
    }
  };

DisplayType PopUpComponent::GetDisplay(){
return PopUpContainer->GetRenderDisplay();
};


void SpecialComponentsUpdate(){
  for(auto& popup : SunCore::instance().SunWorld.GetAllPopUps()){
  popup.second->Update();
  }
}

 void SunWorld::DeleteComponent(std::string Id){
    auto it = WorldComponents.find(Id);
    if(it != WorldComponents.end()){
      for(auto& l : SunCore::instance().SunBrain.GetListeners()){
      if(l.second->Trigger.GetComponentTarget()){
        if(l.second->Trigger.GetComponentTarget() == WorldComponents.find(Id)->second.get()){
          SunCore::instance().SunBrain.DeleteListener(l.second->Id);
        }

      }
    }
    int i = 0;
    for(auto* rc : SunCore::instance().SunEngineConfig->Render.RenderVector){
   if(rc->OriginalComponent == it->second.get()){
    SunCore::instance().SunEngineConfig->Render.RenderVector.erase(SunCore::instance().SunEngineConfig->Render.RenderVector.begin() + i);
    
   }
   i++;
    } 
      WorldComponents.erase(Id);
    }
    
  };


   void Scene::StopThisScene(){
    State = SceneState::None;
  for(auto* c : SceneComponents){
   SunCore::instance().SunWorld.DeleteComponent(c->GetId());
  };
  };


  void CameraInit(){
   SunCore::instance().Camera.Height = SunCore::instance().WindowHeight;
    SunCore::instance().Camera.Width = SunCore::instance().WindowWidth;
  };

  void SunWorld::AddNewStaticBody(std::string Id,std::unique_ptr<SunBodys> StaticBody){
    
 SunCore::instance().BodysControl.AddSunBody(StaticBody.get());


    StaticBodys.emplace(Id,std::move(StaticBody));
 
   };

   void SunCamera::StartFollow(std::string ComponentId){
  FollowedComponent = ComponentId;
 
};


void SunCamera::Update(float dt){
if(FollowedComponent != "SunNull"){

   auto c = SunCore::instance().SunWorld.GetWorldComponentsMap().find(FollowedComponent);
 if(c != SunCore::instance().SunWorld.GetWorldComponentsMap().end()){
  RenderComponentClass* Fc = c->second.get()->GetRenderComponent();

  float xdif =  (Fc->X + Fc->Width / 2) - x - Width / 2;
   float ydif = (Fc->Y + Fc->Height / 2) - y - Height / 2;

  
  x += (xdif * Smooth);
    y += (ydif * Smooth);
    if(CamLimited){
    if(x - Width / 2 < CamLimit.x){
      x = CamLimit.x + Width / 2;
    }
    if(x + Width / 2 > CamLimit.z){
      x = CamLimit.z - Width / 2; 
    }
    if(y - Height / 2 > CamLimit.xy){
      y = CamLimit.xy + Height/ 2;
    }
    if(y + Height / 2> CamLimit.y){
      y = CamLimit.y - Height/ 2; 
    }
    }
}
}
};

void FrameAnimation::SetAnimationTexture(GLuint at){
 AnimationTexture = at;
};


void SunFramesAnimations::MakeAnimationAtlas(std::string Id,FrameAnimation* fra){

float AtlasWidth = 0.0f;
float AtlasHeight = 0.0f;

for(auto& tex : fra->GetFrames()){
  auto texclass = SunCore::instance().SunRenderCore.GetTexture(tex);

  float w = texclass->Width;
  float h = texclass->Height;
   AtlasWidth += w;
   AtlasHeight = std::max(h,AtlasHeight); 

  
  
}

  GLuint texture;
glGenTextures(1, &texture);
glBindTexture(GL_TEXTURE_2D, texture);
    
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
glTexImage2D(
    GL_TEXTURE_2D,
    0,
    GL_RGBA,
    AtlasWidth,
    AtlasHeight,
    0,
    GL_RGBA,
    GL_UNSIGNED_BYTE,
    nullptr
);
fra->SetAnimationTexture(texture);
int currentX = 0;
int i = 0;
std::cout << "Atlas: " << AtlasWidth << " x " << AtlasHeight << "\n";
for(auto& tex : fra->GetFrames()){
  auto texclass = SunCore::instance().SunRenderCore.GetTexture(tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexSubImage2D(
        GL_TEXTURE_2D,
        0,
        currentX,
        0,
        texclass->Width,
        texclass->Height,
        GL_RED,
        GL_UNSIGNED_BYTE,
        texclass->Data
    );



    auto Frame = std::make_unique<AnimationFrame>();
    Frame->Width = texclass->Width;
    Frame->Height = texclass->Height;
    Frame->uvStart.x = (float)currentX / AtlasWidth;
    Frame->uvStart.y = 0.0f;
      Frame->uvEnd.x = (float)(currentX + Frame->Width) / AtlasWidth;
       Frame->uvEnd.y = (float)Frame->Height / AtlasWidth;

       fra->AnimationFrames.emplace(i,std::move(Frame));
  currentX += texclass->Width;
  i++;
}

};


void FrameAnimation::UpdateActualFrame(){
 if(Frames.empty()) return;

    FrameTimer += SunCore::instance().SunTime.GetDeltaTime();

    float frameDuration = 1.0f / FrameRate;

    while(FrameTimer >= frameDuration){

        FrameTimer -= frameDuration;

        ActualFrame = (ActualFrame + 1) % Frames.size();
    }
};
