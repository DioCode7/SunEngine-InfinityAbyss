
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

                  glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glDrawArrays(GL_TRIANGLE_FAN,0,4);



 


                

            };
              
        };

class RenderComponentCircle : public RenderComponentClass{
    public:
       RenderComponentCircle(int Radius,int PosX,int PosY,int R,int G,int B,int A,std::string Id,Scene* OwnerScene) :
        RenderComponentClass(PosX,PosY,Radius * 2,Radius * 2,R,G,B,A,Id,OwnerScene){}
  
        void RenderMethod() override {
         GLuint Shader = SunCore::instance().Gl.ShaderProgram;

            

                float SizeX = (Width / SunCore::instance().WindowWidth) * 2.0f;
                float SizeY = (Height / SunCore::instance().WindowHeight) * 2.0f;
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

                  glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glDrawArrays(GL_TRIANGLE_FAN,0,4);



 
        }
};


class RenderComponentSprite : public RenderComponentClass{
public:
RenderComponentSprite(std:: string SpriteId,float PosX,float PosY,float W,float H,std::string TextureId,Scene* OwnerScene) :
RenderComponentClass(PosX,PosY,W,H,0,0,0,0,SpriteId,OwnerScene,TextureId){}

    void RenderMethod()override{
   
      GLuint Shader = SunCore::instance().Gl.ShaderProgram;
    Texture* Tex = SunCore::instance().SunRenderCore.GetTexture(this->TextureId);
    
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
                    GLint uTexture = SunCore::instance().Gl.UniformsLocations.uTexture;
                    GLint uFlipY = SunCore::instance().Gl.UniformsLocations.uFlipY;
                     GLint uFlipX = SunCore::instance().Gl.UniformsLocations.uFlipX;
                     GLint uBorderColor = SunCore::instance().Gl.UniformsLocations.uBorderColor;
                   GLint uBorderWidth = SunCore::instance().Gl.UniformsLocations.uBorderWidth;


                  glUniform2f(uPosLoc,PosX,PosY);
                  glUniform2f(uSizeLoc,SizeX,SizeY);
                  
                  glUniform1i(uShapeType,0);
              
                 glUniform1i(uTexture,0);
                 glUniform1i(uFlipY,1);
                 glUniform1i(uFlipX,0);
                 glUniform2f(uBorderWidth,BorderWidthX,BorderWidthY);
                  glUniform4f(uColorLoc,1.0f,1.0f,1.0f,1.0f);
                  glUniform4f(uBorderColor,this->BorderColorR,this->BorderColorG,this->BorderColorB,this->BorderColorA);
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D,Tex->GPUID);
                    glUniform1i(uUseTexture,1);
                  glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                 
                glDrawArrays(GL_TRIANGLE_FAN,0,4);



    

};
};



class RenderComponentText : public RenderComponentClass{
public:
RenderComponentText(std:: string Id,float PosX,float PosY,float W,float H,Scene* OwnerScene,std::string FontId,std::string Text,float R,float G,float B,float A) :
RenderComponentClass(PosX,PosY,W,H,R,G,B,A,Id,OwnerScene,"None",FontId,Text){}
    
void RenderMethod()override{
   GLuint Shader = SunCore::instance().Gl.TextShader;
    SunFont* Font = SunCore::instance().SunFontsControl.GetFont(this->Font);
    std::string Text = this->Text;
       float WindowHeight = SunCore::instance().WindowHeight;
  float WindowWidth = SunCore::instance().WindowWidth;
   float PosX = this->X;
   float PosY = WindowHeight - this->Y;


             


                float SizeX = this->Width;
                float SizeY =  this->Height;
    
          if(TextAlignX == Align::None){
                  switch(this->OriginX){
                case OriginClass::Center:
                PosX =  this->X - (SizeX / 2) ;
                break;
                case OriginClass::Start:
                  PosX =  this->X;
                break;
                 case OriginClass::End:
                  PosX =  this->X - (SizeX);
                break;
               }
              }
              if(TextAlignY == Align::None){
               switch(this->OriginY){
                case OriginClass::Center:
                 PosY = WindowHeight - (this->Y + Height / 2) ;
                 break;
                 case OriginClass::End:
                 PosY =  this->Y;
                 break;
                  case OriginClass::Start:
                 PosY = WindowHeight - (this->Y + Height);
                 break;
               }

              };


float Ortho[16] = {
    2.0f / WindowWidth,  0, 0, 0,
    0,  2.0f / WindowHeight, 0, 0,
    0,  0, -1, 0,
   -1, -1, 0, 1
};


                glUseProgram(Shader);
        GLuint Projection = SunCore::instance().Gl.TextUniformsLocations.ProjectionMatrix;
                 glUniformMatrix4fv(Projection,1,GL_FALSE,Ortho);
                glBindVertexArray(SunCore::instance().Gl.TextVAO);

                 GLint uPosLoc = SunCore::instance().Gl.TextUniformsLocations.uPos;
                  GLint uSizeLoc = SunCore::instance().Gl.TextUniformsLocations.uSize;
                  GLint uColorLoc = SunCore::instance().Gl.TextUniformsLocations.uColor;
                    GLint uTexture = SunCore::instance().Gl.TextUniformsLocations.uTexture;


                 glUniform1i(uTexture,0);
                
                  glUniform4f(uColorLoc,this->R,this->G,this->B,this->A);
                  
                  glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D,Font->AtlasTexture);
                  
                     float CursorX = PosX;
                 float CursorY = PosY;
                 
                 int i = 0;

              
            
                    for(char c : Text){
                      
                      Character ch = Font->GetCharacter(c);
                      float xpos = CursorX + ch.Bearing.x + CharactersMargin.x * i;
                      float ypos = CursorY - (ch.Size.y - ch.Bearing.y);
                      float w = ch.Size.x;
                      float h = ch.Size.y;
                      vector2 UvStart = ch.UvMin;
                      vector2 UvEnd = ch.UvMax;

                      
                      

   float vertices[] = {
    xpos,     ypos + h,   0.0f, UvStart.x, UvStart.y,
    xpos,     ypos,       0.0f, UvStart.x, UvEnd.y,
    xpos + w, ypos,       0.0f, UvEnd.x,   UvEnd.y,

    xpos,     ypos + h,   0.0f, UvStart.x, UvStart.y,
    xpos + w, ypos,       0.0f, UvEnd.x,   UvEnd.y,
    xpos + w, ypos + h,   0.0f, UvEnd.x,   UvStart.y
};


    glBindBuffer(GL_ARRAY_BUFFER, SunCore::instance().Gl.TextVBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

  glUseProgram(Shader);
  glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glDrawArrays(GL_TRIANGLES,0,6);
               // std::cout << "\n  Letra:  " << c << "Desenhada! \n  ";
                CursorX += ch.Advance >> 6;
                 i++;
                    }


               
                
             
               
                 
               
};
   
   
   



    


};



      
    void SunRender::AddRectangle(std::unique_ptr<Component> ComponentClass,Scene* OwnerScene,Component* Parent){
    auto ComponentNode = std::make_unique<NodeClass>();

  NodeClass* ParentNode = nullptr;
  if(Parent){
    ParentNode = Parent->GetOwner();
  }
  ComponentNode->Parent = ParentNode;
  ComponentNode->ComponentClass = ComponentClass.get();
    ComponentClass.get()->SetOwner(std::move(ComponentNode));
  ComponentClass.get()->ResolveComponent();
  RenderComponentRectangle* Rc = new RenderComponentRectangle(ComponentClass.get()->GetX().ValueResolved,
    ComponentClass.get()->GetY().ValueResolved,ComponentClass.get()->GetWidth().ValueResolved,ComponentClass.get()->GetHeight().ValueResolved,ComponentClass.get()->GetRGBA()->R,
    ComponentClass.get()->GetRGBA()->G,ComponentClass.get()->GetRGBA()->B,ComponentClass.get()->GetRGBA()->A,ComponentClass.get()->GetId(),OwnerScene);
    float Y = ComponentClass.get()->GetY().ValueResolved;
    Rc->OriginX = ComponentClass.get()->GetOriginX();
    Rc->OriginY = ComponentClass.get()->GetOriginY();
    Rc->OriginalComponent = ComponentClass.get();
    ComponentClass.get()->SetRenderComponent(Rc);
  SunCore::instance().SunEngineConfig->Render.RenderVector.push_back(Rc);
  SunCore::instance().SunWorld.AddNewWorldComponent(std::move(ComponentClass));

           

        };
    
 void SunRender::AddCircle(std::unique_ptr<Component>ComponentClass,Scene* OwnerScene,Component* Parent){
    auto ComponentNode = std::make_unique<NodeClass>();
 
  NodeClass* ParentNode = nullptr;
  if(Parent){
    ParentNode = Parent->GetOwner();
  }
  ComponentNode->Parent = ParentNode;
  ComponentNode->ComponentClass = ComponentClass.get();
   ComponentClass->SetOwner(std::move(ComponentNode));
   ComponentClass->ResolveComponent();
  RenderComponentCircle* Rc = new RenderComponentCircle(ComponentClass.get()->GetWidth().ValueResolved,ComponentClass.get()->GetX().ValueResolved,
    ComponentClass.get()->GetY().ValueResolved,
    ComponentClass.get()->GetRGBA()->R,ComponentClass.get()->GetRGBA()->G,ComponentClass.get()->GetRGBA()->B,ComponentClass.get()->GetRGBA()->A,ComponentClass.get()->GetId(),OwnerScene);
    Rc->OriginX = ComponentClass.get()->GetOriginX();
    Rc->OriginY = ComponentClass.get()->GetOriginY();
    Rc->OriginalComponent = ComponentClass.get();
  SunCore::instance().SunEngineConfig->Render.RenderVector.push_back(Rc);
  ComponentClass.get()->SetRenderComponent(Rc);
  SunCore::instance().SunWorld.AddNewWorldComponent(std::move(ComponentClass));
     
 }      
 
 void SunRender::AddSprite(std::unique_ptr<Component>ComponentClass,Scene* OwnerScene,Component* Parent){
 auto ComponentNode = std::make_unique<NodeClass>();

  NodeClass* ParentNode = nullptr;
  if(Parent){
    ParentNode = Parent->GetOwner();
  }
  ComponentNode->Parent = ParentNode;
  ComponentNode->ComponentClass = ComponentClass.get();
    ComponentClass.get()->SetOwner(std::move(ComponentNode));
  ComponentClass.get()->ResolveComponent();
  RenderComponentSprite* Rc = new RenderComponentSprite(ComponentClass.get()->GetId(),ComponentClass.get()->GetX().ValueResolved,
    ComponentClass.get()->GetY().ValueResolved,ComponentClass.get()->GetWidth().ValueResolved,ComponentClass.get()->GetHeight().ValueResolved,ComponentClass.get()->GetTexture(),OwnerScene);
    float Y = ComponentClass.get()->GetY().ValueResolved;
    Rc->OriginX = ComponentClass.get()->GetOriginX();
    Rc->OriginY = ComponentClass.get()->GetOriginY();
    Rc->OriginalComponent = ComponentClass.get();
    ComponentClass.get()->SetRenderComponent(Rc);
  SunCore::instance().SunEngineConfig->Render.RenderVector.push_back(Rc);
  SunCore::instance().SunWorld.AddNewWorldComponent(std::move(ComponentClass));

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


 void SunRender::AddText(std::unique_ptr<Component>ComponentClass,std::string FontId,std::string Text,Scene* OwnerScene,Component* Parent){
 auto ComponentNode = std::make_unique<NodeClass>();

  NodeClass* ParentNode = nullptr;
  if(Parent){
    ParentNode = Parent->GetOwner();
  }
  ComponentNode->Parent = ParentNode;
  ComponentNode->ComponentClass = ComponentClass.get();
    ComponentClass.get()->SetOwner(std::move(ComponentNode));
  ComponentClass.get()->ResolveComponent();
  RenderComponentText* Rc = new RenderComponentText(ComponentClass.get()->GetId(),ComponentClass.get()->GetX().ValueResolved,
    ComponentClass.get()->GetY().ValueResolved,ComponentClass.get()->GetWidth().ValueResolved,ComponentClass.get()->GetHeight().ValueResolved,OwnerScene,FontId,Text,
  ComponentClass.get()->GetRGBA()->R,ComponentClass.get()->GetRGBA()->G,ComponentClass.get()->GetRGBA()->B,ComponentClass.get()->GetRGBA()->A);
    ;
    Rc->OriginX = ComponentClass.get()->GetOriginX();
    Rc->OriginY = ComponentClass.get()->GetOriginY();
    Rc->OriginalComponent = ComponentClass.get();
    Rc->CharactersMargin = ComponentClass->GetCharactersMargin();
        Rc->TextAlignX = ComponentClass->GetTextAlignX();
         Rc->TextAlignX = ComponentClass->GetTextAlignY();
  ComponentClass->SetComponentType(ComponentType::Text);
  ComponentClass->SetText(Text);
 ComponentClass->SetFont(SunCore::instance().SunFontsControl.GetFont(FontId));
    ComponentClass.get()->SetRenderComponent(Rc);
  SunCore::instance().SunEngineConfig->Render.RenderVector.push_back(Rc);
  SunCore::instance().SunWorld.AddNewWorldComponent(std::move(ComponentClass));


 }
     