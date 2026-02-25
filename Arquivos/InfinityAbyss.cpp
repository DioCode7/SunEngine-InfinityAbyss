#include <iostream>
#include <ios>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include <vector>
#include <memory>

#include "SunEngine.h"

    SunTexturesControl SunTextures;
    SunListeners SunListenersControl;
   
    class Player;
    
    class PlayerAttributesClass{
    public:
    float WalkSpeedX;
    };

    class Ability{
     public:
     float Cooldown = 0;
     float CurrentCooldown = 0;

     virtual ~Ability() = default;
     virtual void Activate(Player& Player) = 0;
    
    };

    
    class Player{
 public:
 Player(Component* PlayerComp,PlayerAttributesClass Atribu):PlayerComponent(PlayerComp),Attributes(Atribu){}
 Component* PlayerComponent;
 PlayerAttributesClass Attributes;
 std::vector<std::unique_ptr<Ability>> Abilities;
 void UseAbility(int Index){
  if(Index < Abilities.size()){
    Abilities[Index]->Activate(*this);
  }
 };



 
 


};








int main(int argc, char** argv)
{




   SunEngineConfig InfinityAbyssConfig;
   
    class MenuScene : public Scene{
    public:
    std::string SceneID = "MenuScene"; 
    void SceneConfigs() override{
     
    };
    void OnLoad() override{
     SunTextures.NewTexture("TexturaTeste","./Assets/TestAssets/TestAsset.png");
       SunTextures.NewTexture("TexturaTeste2","./Assets/TestAssets/TestAsset2.jpg");
         SunTextures.NewTexture("DioTesteTexture","./Assets/TestAssets/DioTexture.png");
    };
    void OnInit() override{
            SunRender SunRendering;
            UnitClass TestRectangleW;
            TestRectangleW.Unit = UnitType::Pixel;
            TestRectangleW.Value = 200.0f;
            UnitClass TestRectangleH;
            TestRectangleH.Unit = UnitType::Pixel;
            TestRectangleH.Value = 200.0f;
            UnitClass TestRectangleX;
            TestRectangleX.Unit = UnitType::Pixel;
            TestRectangleX.Value = 800.0f;
            UnitClass TestRectangleY;
            TestRectangleY.Unit = UnitType::Pixel;
            TestRectangleY.Value = 300.0f;
            
            
            Component* TestRectangle = new Component("TestRectangle",TestRectangleW,TestRectangleH,TestRectangleX,TestRectangleY);
           TestRectangle->SetRGBA(1.0f,0.0f,0.0f,1.0f);
           BorderClass TestRectangleBorder;
           UnitClass TestRectangleBorderW;
            TestRectangleBorderW.Unit = UnitType::Pixel;
            TestRectangleBorderW.Value = 5.0f;
            TestRectangleBorder.R = 0.0f;
            TestRectangleBorder.G = 1.0f;
            TestRectangleBorder.B = 0.0f;
            TestRectangleBorder.A = 1.0f;
            TestRectangleBorder.Use = true;
            TestRectangleBorder.Width = TestRectangleBorderW;
            TestRectangle->SetBorder(TestRectangleBorder);
            SunRendering.AddRectangle(TestRectangle,this);
            

             UnitClass TestCircleW;
            TestCircleW.Unit = UnitType::Pixel;
            TestCircleW.Value = 200.0f;
            UnitClass TestCircleH;
            TestCircleH.Unit = UnitType::Pixel;
            TestCircleH.Value = 200.0f;
            UnitClass TestCircleX;
            TestCircleX.Unit = UnitType::Pixel;
            TestCircleX.Value = 1000.0f;
            UnitClass TestCircleY;
            TestCircleY.Unit = UnitType::Pixel;
            TestCircleY.Value = 500.0f;
            Component* TestCircle = new Component("TestCircle",TestCircleW,TestCircleH,TestCircleX,TestCircleY);
            TestCircle->SetRGBA(0.0f,1.0f,0.0f,1.0f);
            /*
     SunRendering.AddCircle(TestCircle,this);
*/
     UnitClass MenuBackgroundW;
     MenuBackgroundW.Unit = UnitType::Percent;
     MenuBackgroundW.Value = 0.5f;
       UnitClass MenuBackgroundH;
     MenuBackgroundH.Unit = UnitType::Percent;
     MenuBackgroundH.Value = 0.5f;
       UnitClass MenuBackgroundX;
     MenuBackgroundX.Unit = UnitType::Percent;
     MenuBackgroundX.Value = 0.5f;
     UnitClass MenuBackgroundY;
     MenuBackgroundY.Unit = UnitType::Percent;
     MenuBackgroundY.Value = 0.5f;
     OriginClass MenuBackgroundOriginX;
     MenuBackgroundOriginX = OriginClass::Center;
     OriginClass MenuBackgroundOriginY;
     MenuBackgroundOriginY = OriginClass::Center;
     Component* MenuBackground = new Component("MenuBackground",MenuBackgroundW,MenuBackgroundH,MenuBackgroundX,
      MenuBackgroundY,MenuBackgroundOriginX,MenuBackgroundOriginY);
      MenuBackground->SetTexture("TexturaTeste");
      /*
     SunRendering.AddSprite(MenuBackground,this);
     */

      UnitClass MenuW;
     MenuW.Unit = UnitType::Percent;
     MenuW.Value = 0.2f;
       UnitClass MenuH;
     MenuH.Unit = UnitType::Percent;
     MenuH.Value = 0.2f;
       UnitClass MenuX;
     MenuX.Unit = UnitType::Percent;
     MenuX.Value = 0.5f;
     UnitClass MenuY;
     MenuY.Unit = UnitType::Percent;
     MenuY.Value = 0.5f;
      OriginClass MenuOriginX;
     MenuOriginX = OriginClass::Center;
     OriginClass MenuOriginY;
     MenuOriginY = OriginClass::Center;
     Component* Menu = new Component("Menu",MenuW,MenuH,MenuX,MenuY,MenuOriginX,MenuOriginY);
     Menu->SetTexture("TexturaTeste2");
     /*SunRendering.AddSprite(Menu,this,MenuBackground);
*/
     

     UnitClass PlayerW;
     PlayerW.Unit = UnitType::Pixel;
     PlayerW.Value = 70.0f;
     UnitClass PlayerH;
     PlayerH.Unit = UnitType::Pixel;
     PlayerH.Value = 120.0f;
     UnitClass PlayerX;
     PlayerX.Unit = UnitType::Pixel;
     PlayerX.Value = 1.0f;
     UnitClass PlayerY;
     PlayerY.Unit = UnitType::Pixel;
     PlayerY.Value = 1.0f;
     OriginClass PlayerOriginX;
     PlayerOriginX = OriginClass::Start;
     OriginClass PlayerOriginY;
     PlayerOriginY = OriginClass::Start;
     std::unique_ptr<Component> DioComponentUnique = 
    std::make_unique<Component>("DioComponent", PlayerW, PlayerH, PlayerX, PlayerY,PlayerOriginX,PlayerOriginY);
     DioComponentUnique->SetTexture("DioTesteTexture");
      
     SunRendering.AddSprite(std::move(DioComponentUnique),this);
    auto* DioComponent = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioComponent")->second.get();
     
 
      
     PlayerAttributesClass DioAttributes;
     DioAttributes.WalkSpeedX = 1.0f;
     

  Player* Dio = new Player(DioComponent,DioAttributes);
     
     struct MoveLeft : Ability{
      public:
    void Activate(Player& Player)override{
      
      UnitClass X = Player.PlayerComponent->GetX();
      X.Value += Player.Attributes.WalkSpeedX;
       Player.PlayerComponent->SetX(X);
    }
    
};
    
Dio->Abilities.push_back(std::make_unique<MoveLeft>());
     
    
     auto DioMoveRightListener = std::make_unique<SunListener>(); 
     DioMoveRightListener->Id = "DioMoveRightListener";

     SunEventTrigger DioMoveRightTrigger;
      DioMoveRightTrigger.Type = TriggerType::KeyHeld;
      DioMoveRightTrigger.Key = KeyCodes::D;
     DioMoveRightListener->Trigger = DioMoveRightTrigger;
     DioMoveRightListener->UseFn = true;
     DioMoveRightListener->Fn = [Dio](SunEvent& e){
     Dio->UseAbility(0);
     };
     
     SunListenersControl.AddListener(std::move(DioMoveRightListener));
    
     struct MoveRight : Ability{
    void Activate(Player& Player)override{
     UnitClass X = Player.PlayerComponent->GetX();
      X.Value -= Player.Attributes.WalkSpeedX;
       Player.PlayerComponent->SetX(X);
    }
     };

     Dio->Abilities.push_back(std::make_unique<MoveRight>());

     auto DioMoveLeftListener = std::make_unique<SunListener>();
     DioMoveLeftListener->Id = "DioMoveLeftListener";
     SunEventTrigger DioMoveLeftTrigger;
     DioMoveLeftTrigger.Type = TriggerType::KeyHeld;
     DioMoveLeftTrigger.Key = KeyCodes::A;
     DioMoveLeftListener->Trigger = DioMoveLeftTrigger;
     DioMoveLeftListener->UseFn = true;
     DioMoveLeftListener->Fn = [Dio](SunEvent& e){
     Dio->UseAbility(1);
     };
     SunListenersControl.AddListener(std::move(DioMoveLeftListener));

     
     struct MoveDown : Ability{
    void Activate(Player& Player)override{
     UnitClass Y = Player.PlayerComponent->GetY();
      Y.Value += Player.Attributes.WalkSpeedX;
       Player.PlayerComponent->SetY(Y);
    }
     };

     Dio->Abilities.push_back(std::make_unique<MoveDown>());

     auto DioMoveDownListener = std::make_unique<SunListener>();
     DioMoveDownListener->Id = "DioMoveDownListener";
     SunEventTrigger DioMoveDownTrigger;
     DioMoveDownTrigger.Type = TriggerType::KeyHeld;
     DioMoveDownTrigger.Key = KeyCodes::S;
     DioMoveDownListener->Trigger = DioMoveDownTrigger;
     DioMoveDownListener->UseFn = true;
     DioMoveDownListener->Fn = [Dio](SunEvent& e){
     Dio->UseAbility(2);
     };
     SunListenersControl.AddListener(std::move(DioMoveDownListener));

      
     struct MoveUp : Ability{
    void Activate(Player& Player)override{
     UnitClass Y = Player.PlayerComponent->GetY();
      Y.Value -= Player.Attributes.WalkSpeedX;
       Player.PlayerComponent->SetY(Y);
    }
     };

     Dio->Abilities.push_back(std::make_unique<MoveUp>());

     auto DioMoveUpListener = std::make_unique<SunListener>();
     DioMoveUpListener->Id = "DioMoveUpListener";
     SunEventTrigger DioMoveUpTrigger;
     DioMoveUpTrigger.Type = TriggerType::KeyHeld;
     DioMoveUpTrigger.Key = KeyCodes::W;
     DioMoveUpListener->Trigger = DioMoveUpTrigger;
     DioMoveUpListener->UseFn = true;
     DioMoveUpListener->Fn = [Dio](SunEvent& e){
     Dio->UseAbility(3);
     };
     SunListenersControl.AddListener(std::move(DioMoveUpListener));

   
     auto DioBody = std::make_unique<SunBodys>();
     auto DioMainBody = std::make_unique<Body>();
     DioMainBody->Height = 120.0f;
     DioMainBody->Width = 70.0f;
     DioMainBody->OffsetX = 0;
     DioMainBody->OffsetY = 0;
     DioBody->AddBody("DioMainBody",std::move(DioMainBody));
     Dio->PlayerComponent->AddBody(std::move(DioBody));
     

      auto TestStaticBody = std::make_unique<SunBodys>();
     auto TestStaticMainBody = std::make_unique<Body>();
     TestStaticMainBody->Height = 300.0f;
     TestStaticMainBody->Width = 140.0f;
     TestStaticMainBody->OffsetX = 500.0f;
     TestStaticMainBody->OffsetY = 600.0f;
     TestStaticBody->AddBody("TestStaticBody",std::move(TestStaticMainBody));
     TestStaticBody->CreateStaticBody("TestRectangleBody",std::move(TestStaticBody));

    };
    void OnUpdate() override{

    };
    
       

};
   
   InfinityAbyssConfig.Window.WindowName = "Infinity Abyss";
   MenuScene* Menu = new MenuScene();
   InfinityAbyssConfig.SunScenes.Scenes = {Menu};
   InfinityAbyssConfig.BodysDebug =true;
   
    
    
    
    
  

    StartEngine(InfinityAbyssConfig);
    return 0;
}