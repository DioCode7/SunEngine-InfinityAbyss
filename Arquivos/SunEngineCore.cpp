#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include <variant>
#include <unordered_map>
#include "SunEngineCore.h"
#include "SunRender.h"
#include "SunFunctions.h"

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
                float SizeX = (Width / SunCore::instance().WindowWidth) * 2.0f;
                float SizeY = (Height / SunCore::instance().WindowHeight) * 2.0f;

                float BorderWidthX = (BorderWidth / Width);
                float BorderWidthY = (BorderWidth / Height);
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
  if(Verify){
     float Ax,Ay,Aw,Ah;
   float Bx,By,Bw,Bh;

   

if(A->Owner->GetStatic() || !A->Owner->OwnerComponent){
    Ax = A->OffsetX;
    Ay = A->OffsetY;
    Aw = A->Width;
    Ah = A->Height;
   }else{
   Ax = A->Owner->OwnerComponent->GetX().ValueResolved + A->OffsetX;
   Ay = A->Owner->OwnerComponent->GetY().ValueResolved + A->OffsetY;
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
   Bx = B->Owner->OwnerComponent->GetX().ValueResolved + B->OffsetX;
   By = B->Owner->OwnerComponent->GetY().ValueResolved + B->OffsetY;
   Bw = B->Width;
    Bh = B->Height;
         if(B->Owner->OwnerComponent->GetOriginX() == OriginClass::Center){
    Bx -= Bw / 2;
    }else if(B->Owner->OwnerComponent->GetOriginX() == OriginClass::End){
   Bx -= Bw;

    std::cout << "\n Entrando no if end meu mano \n";
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
    bool test = px < py;
   std::cout << test;
    if (px < py)
    {
   
        float sx = (dx < 0) ? -1.f : 1.f;

        newPos = A->Owner->OwnerComponent->GetX();
        newPos.ValueResolved += px * sx;
        A->Owner->OwnerComponent->SetX(newPos);

         
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

        newPos = A->Owner->OwnerComponent->GetY();
        newPos.ValueResolved += py * sy;
        A->Owner->OwnerComponent->SetY(newPos);

            vel.x = phys->GetVelocity().x;
           
        float vRel = phys->GetVelocity().x - physB->GetVelocity().x;



float invMassA = 1.0f / phys->GetMass();
float invMassB = 1.0f / physB->GetMass();

float j = -(vRel) / (invMassA + invMassB);
 vector2 vja;
 vector2 vjb;
 vja.x =  phys->GetVelocity().x;
 vjb.x =  physB->GetVelocity().x;
 vja.y = phys->GetVelocity().x + j * invMassA;
  vjb.y = physB->GetVelocity().x - j * invMassB;
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
      int cellXEnd = floor(A->WorldX + + A->Width / CellWidth);
    int cellYEnd = floor(A->WorldY + A->Height / CellWidth);
   for(int cellX = cellXStart - 1;cellX <= cellXEnd + 1;cellX++){
      for(int cellY = cellYStart - 1;cellY <= cellYEnd + 1;cellY++){
      
        int x = cellX;
        int y = cellY;
            WorldGridCell cell{x,y};

            auto it = WorldGrid.find(cell);
            if(it == WorldGrid.end()) continue;
       
            for(Body* B : it->second){
             
                if(A == B) continue;
                 
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
     for(auto& CollidesBody : SunCore::instance().SunWorld.GetStaticBodysMap()){
        for(auto& InnerBody : CollidesBody.second.get()->GetBodysMap()){
            AddNewBodyToWorld(InnerBody.second.get());
        }
    }
    for(auto& CollidesBody : SunCore::instance().BodysControl.GetSunBodysVector()){
      for(auto& InnerBody : CollidesBody->GetBodysMap()){
        if(InnerBody.second.get()->Collides && InnerBody.second.get()->CollissionType != CollisionsTypes::None){
    VerifyQuadCollisions(InnerBody.second.get());
        }
      }
    }; 

    

      
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
     for(auto& CollidesBody : SunCore::instance().SunWorld.GetStaticBodysMap()){
        for(auto& InnerBody : CollidesBody.second.get()->GetBodysMap()){
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
            InnerBody.second->GetBodySunPhysics()->PhysicResolve(DeltaTime);
          }
        }
    }
     for(auto& CollidesBody : SunCore::instance().SunWorld.GetStaticBodysMap()){
        for(auto& InnerBody : CollidesBody.second.get()->GetBodysMap()){
              if(InnerBody.second->GetBodySunPhysics()){
            InnerBody.second->GetBodySunPhysics()->PhysicResolve(DeltaTime);
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
    float xpos = rc->OriginalComponent->GetX().RenderValue;
     float ypos = rc->OriginalComponent->GetY().RenderValue;
      float h = rc->OriginalComponent->GetHeight().RenderValue;
 float w = rc->OriginalComponent->GetWidth().RenderValue;


    float vertices[] = {
    xpos,     ypos + h,   0.0f, UvStart.x, UvStart.y,
    xpos,     ypos,       0.0f, UvStart.x, UvEnd.y,
    xpos + w, ypos,       0.0f, UvEnd.x,   UvEnd.y,
    xpos + w, ypos + h,   0.0f, UvEnd.x, UvStart.y,
    
};

    glBindBuffer(GL_ARRAY_BUFFER, Shader->GetVBO());
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    
  for(auto& su : Shader->GetSunUniforms()){
std::cout << "Enteradi Certooo";
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
    2.0f / SunCore::instance().WindowWidth,  0, 0, 0,
    0,  2.0f / SunCore::instance().WindowHeight, 0, 0,
    0,  0, -1, 0,
   -1, -1, 0, 1
};
  std::cout << "\n Matriz \n";
  glUniformMatrix4fv(su.second,1,GL_FALSE,Ortho);

    break;
   }
   case SunUniformsTypes::uSunTime:{
    glUniform1f(su.second,t);
    break;
   }
   case SunUniformsTypes::uSunTexture:{
     
    glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D,SunCore::instance().SunRenderCore.GetTexture(rc->TextureId)->GPUID);
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
    PopUpContainer->SetDisplay(DisplayType::Absolute);
};


void PopUpComponent::DisablePopUp(){
    PopUpContainer->SetDisplay(DisplayType::None);
};

DisplayType PopUpComponent::GetDisplay(){
return PopUpContainer->GetRenderDisplay();
};