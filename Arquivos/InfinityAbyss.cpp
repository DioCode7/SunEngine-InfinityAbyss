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
    SunText SunTextControl;
   
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
         
         SunTextures.NewTexture("InfinityAbyssLetterTexture","./Assets/Hud/InfinityAbyss - MainLetter.png");
          SunTextures.NewTexture("InfinityAbyssMenuArtTexture","./Assets/Arts/InfinityAbyss - MenuBackground1.png");
    };
    void OnInit() override{


            SunRender SunRendering;

         UnitClass MenuContainerW;
         MenuContainerW.Unit = UnitType::Percent;
         MenuContainerW.Value = 1.0f;
         UnitClass MenuContainerH;
         MenuContainerH.Unit = UnitType::Percent;
         MenuContainerH.Value = 1.0f;
        UnitClass MenuContainerX;
         MenuContainerX.Unit = UnitType::Pixel;
         MenuContainerX.Value = 0.0f;
         UnitClass MenuContainerY;
         MenuContainerY.Unit = UnitType::Pixel;
         MenuContainerY.Value = 0.0f;
         auto MenuContainer = std::make_unique<Component>
         ("MenuContainer",MenuContainerW,MenuContainerH,MenuContainerX,MenuContainerY,OriginClass::Start,OriginClass::Start);
         MenuContainer->SetRGBA(1.0f,1.0f,1.0f,1.0f);
         SunRendering.AddRectangle(std::move(MenuContainer),this);
         
         auto CinzelFont = std::make_unique<SunFont>();
         CinzelFont->Id = "Cinzel";
         CinzelFont->FontPath = "./Assets/Fonts/CinzelDecorative-Bold.ttf";
         CinzelFont->Height = 17;
    
     
       SunTextControl.AddFont(std::move(CinzelFont));

     UnitClass PlayButtonX;
     PlayButtonX.Unit = UnitType::Percent;
     PlayButtonX.Value = 0.1f;
   UnitClass PlayButtonY;
     PlayButtonY.Unit = UnitType::Percent;
     PlayButtonY.Value = 0.35f;
  UnitClass PlayButtonW;
     PlayButtonW.Unit = UnitType::Percent;
     PlayButtonW.Value = 0.15f;
    UnitClass PlayButtonH;
     PlayButtonH.Unit = UnitType::Percent;
     PlayButtonH.Value = 0.06f;
     auto PlayButton = std::make_unique<Component>("PlayButton",PlayButtonW,PlayButtonH,PlayButtonX,PlayButtonY);
     PlayButton->SetRGBA(0.1,0.4,0.0,0.4);
     SunRendering.AddRectangle(
      std::move(PlayButton),
      this
     );
      

     
     UnitClass OptionsButtonX;
     OptionsButtonX.Unit = UnitType::Percent;
     OptionsButtonX.Value = 0.1f;
   UnitClass OptionsButtonY;
     OptionsButtonY.Unit = UnitType::Percent;
     OptionsButtonY.Value = 0.47f;
  UnitClass OptionsButtonW;
     OptionsButtonW.Unit = UnitType::Percent;
     OptionsButtonW.Value = 0.15f;
    UnitClass OptionsButtonH;
     OptionsButtonH.Unit = UnitType::Percent;
     OptionsButtonH.Value = 0.06f;
     auto OptionsButton = std::make_unique<Component>("OptionsButton",OptionsButtonW,OptionsButtonH,OptionsButtonX,OptionsButtonY);
     OptionsButton->SetRGBA(0.1,0.4,0.0,0.4);
     SunRendering.AddRectangle(
      std::move(OptionsButton),
      this
     );
   

     
     UnitClass CreditsButtonX;
     CreditsButtonX.Unit = UnitType::Percent;
     CreditsButtonX.Value = 0.1f;
   UnitClass CreditsButtonY;
     CreditsButtonY.Unit = UnitType::Percent;
     CreditsButtonY.Value = 0.59f;
  UnitClass CreditsButtonW;
     CreditsButtonW.Unit = UnitType::Percent;
     CreditsButtonW.Value = 0.15f;
    UnitClass CreditsButtonH;
     CreditsButtonH.Unit = UnitType::Percent;
     CreditsButtonH.Value = 0.06f;
     auto CreditsButton = std::make_unique<Component>("CreditsButton",CreditsButtonW,CreditsButtonH,CreditsButtonX,CreditsButtonY);
     CreditsButton->SetRGBA(0.1,0.4,0.0,0.4);
     SunRendering.AddRectangle(
      std::move(CreditsButton),
      this
     );
   

  
     UnitClass LeaveButtonX;
     LeaveButtonX.Unit = UnitType::Percent;
     LeaveButtonX.Value = 0.1f;
   UnitClass LeaveButtonY;
     LeaveButtonY.Unit = UnitType::Percent;
     LeaveButtonY.Value = 0.71f;
  UnitClass LeaveButtonW;
     LeaveButtonW.Unit = UnitType::Percent;
     LeaveButtonW.Value = 0.15f;
    UnitClass LeaveButtonH;
     LeaveButtonH.Unit = UnitType::Percent;
     LeaveButtonH.Value = 0.06f;
     auto LeaveButton = std::make_unique<Component>("LeaveButton",LeaveButtonW,LeaveButtonH,LeaveButtonX,LeaveButtonY);
     LeaveButton->SetRGBA(0.1,0.4,0.0,0.4);
     SunRendering.AddRectangle(
      std::move(LeaveButton),
      this
     );
   
     
  
     UnitClass InfinityAbyssMenuArtX;
     InfinityAbyssMenuArtX.Unit = UnitType::Percent;
     InfinityAbyssMenuArtX.Value = -0.2f;
   UnitClass InfinityAbyssMenuArtY;
     InfinityAbyssMenuArtY.Unit = UnitType::Percent;
     InfinityAbyssMenuArtY.Value = 0.0f;
  UnitClass InfinityAbyssMenuArtW;
     InfinityAbyssMenuArtW.Unit = UnitType::Percent;
     InfinityAbyssMenuArtW.Value = 1.2f;
    UnitClass InfinityAbyssMenuArtH;
     InfinityAbyssMenuArtH.Unit = UnitType::Percent;
     InfinityAbyssMenuArtH.Value = 1.0f;
     auto InfinityAbyssMenuArt = std::make_unique<Component>(
      "InfinityAbyssMenuArt",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArt->SetTexture("InfinityAbyssMenuArtTexture");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArt),
      this
     );
   
     





     
  
     UnitClass InfinityAbyssLetterX;
     InfinityAbyssLetterX.Unit = UnitType::Percent;
     InfinityAbyssLetterX.Value = 0.05f;
   UnitClass InfinityAbyssLetterY;
     InfinityAbyssLetterY.Unit = UnitType::Percent;
     InfinityAbyssLetterY.Value = 0.12f;
  UnitClass InfinityAbyssLetterW;
     InfinityAbyssLetterW.Unit = UnitType::Percent;
     InfinityAbyssLetterW.Value = 0.22f;
    UnitClass InfinityAbyssLetterH;
     InfinityAbyssLetterH.Unit = UnitType::Percent;
     InfinityAbyssLetterH.Value = 0.18f;
     auto InfinityAbyssLetter = std::make_unique<Component>(
      "InfinityAbyssLetter",
       InfinityAbyssLetterW,
       InfinityAbyssLetterH,
        InfinityAbyssLetterX,
       InfinityAbyssLetterY,
       OriginClass::Start
      );

     InfinityAbyssLetter->SetTexture("InfinityAbyssLetterTexture");
     SunRendering.AddSprite(
      std::move(InfinityAbyssLetter),
      this
     );
   
     
     















        UnitClass PlayTextX;
        PlayTextX.Unit = UnitType::Pixel;
        PlayTextX.Value = 0.0f;
        UnitClass PlayTextY;
        PlayTextY.Unit = UnitType::Pixel;
        PlayTextY.Value = 5.0f;
        UnitClass PlayTextW;
        PlayTextW.Unit = UnitType::Pixel;
        PlayTextW.Value = 0.0f;
        UnitClass PlayTextH;
        PlayTextH.Unit = UnitType::Pixel;
        PlayTextH.Value = 0.0f;
       auto PlayTextComponent = std::make_unique<Component>("PlayText",PlayTextW,PlayTextH,PlayTextX,PlayTextY,OriginClass::Start,OriginClass::Start);
       PlayTextComponent->SetRGBA(0.0f,0.0f,0.0f,1.0f);
       PlayTextComponent->SetCharatersMargin(0.0f,0);
       PlayTextComponent->SetTextAlingX(Align::Center);
        PlayTextComponent->SetTextAlingY(Align::Center);
       SunRendering.AddText(
        std::move(PlayTextComponent),
        "Cinzel",
        "Jogar",
        this,
        SunCore::instance().SunWorld.GetWorldComponentsMap().find("PlayButton")->second.get()
      );








         
 /*
        auto WorldLayer = std::make_unique<CollisionLayer>();
             WorldLayer->Id = "WorldLayer";
             
               auto DioHurtLayer = std::make_unique<CollisionLayer>();
             DioHurtLayer->Id = "DioHurtLayer";
                WorldLayer->AddCollision(DioHurtLayer.get());
            DioHurtLayer->AddCollision(WorldLayer.get());
             SunCore::instance().SunWorld.CollisionsWorld.AddNewCollissionLayer(std::move(WorldLayer));
              SunCore::instance().SunWorld.CollisionsWorld.AddNewCollissionLayer(std::move(DioHurtLayer));

              


            UnitClass TestRectangleW;
            TestRectangleW.Unit = UnitType::Pixel;
            TestRectangleW.Value = 200.0f;
            UnitClass TestRectangleH;
            TestRectangleH.Unit = UnitType::Pixel;
            TestRectangleH.Value = 200.0f;
            UnitClass TestRectangleX;
            TestRectangleX.Unit = UnitType::Pixel;
            TestRectangleX.Value = 200.0f;
            UnitClass TestRectangleY;
            TestRectangleY.Unit = UnitType::Pixel;
            TestRectangleY.Value = 300.0f;
            
            
            std::unique_ptr<Component> TestRectangle = 
            std::make_unique<Component>("TestRectangle",TestRectangleW,TestRectangleH,TestRectangleX,TestRectangleY,OriginClass::Start,OriginClass::Start);
           TestRectangle.get()->SetRGBA(1.0f,0.0f,0.0f,1.0f);
           BorderClass TestRectangleBorder;
           UnitClass TestRectangleBorderW;
            TestRectangleBorderW.Unit = UnitType::Pixel;
            TestRectangleBorderW.Value = 30.0f;
            TestRectangleBorder.R = 1.0f;
            TestRectangleBorder.G = 1.0f;
            TestRectangleBorder.B = 0.0f;
            TestRectangleBorder.A = 1.0f;
            TestRectangleBorder.Use = true;
            TestRectangleBorder.Width = TestRectangleBorderW;
            TestRectangle.get()->SetBorder(TestRectangleBorder);
          SunRendering.AddRectangle(std::move(TestRectangle),this);
    
         
             
             auto Bodycomp = std::make_unique<SunBodys>();
     auto MainBody = std::make_unique<Body>();
     MainBody->Height = 200.0f;
     MainBody->Width = 200.0f;
     MainBody->OffsetX = 0;
     MainBody->OffsetY = 0;
     MainBody->SetCollisionLayer("WorldLayer");
     
     auto MainBodyPhysic = std::make_unique<BodySunPhysic>();
     MainBodyPhysic->SetMass(100.0f);
     MainBody->SetBodySunPhysic(std::move(MainBodyPhysic));

 


     Bodycomp->AddBody("TestMainBody",std::move(MainBody));
    SunCore::instance().SunWorld.GetWorldComponentsMap().find("TestRectangle")->second.get()->AddBody(std::move(Bodycomp));
            SunCore::instance().SunWorld.GetWorldComponentsMap().find("TestRectangle")->second.get()->SetX(TestRectangleX);

          
 

     

     UnitClass PlayerW;
     PlayerW.Unit = UnitType::Pixel;
     PlayerW.Value = 70.0f;
     UnitClass PlayerH;
     PlayerH.Unit = UnitType::Pixel;
     PlayerH.Value = 50.0f;
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
       BodyArcadePhysic Physic;
     vector2 ActualVelocity = Physic.GetVelocity();
     vector2 Velocity;
     Velocity.y = 0.0f;
     Velocity.x = -500.0f; 
       Player.PlayerComponent->ApplyForce(Velocity);
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
     Dio->UseAbility(1);
     };
     
     SunListenersControl.AddListener(std::move(DioMoveRightListener));
    
     struct MoveRight : Ability{
    void Activate(Player& Player)override{
       BodyArcadePhysic Physic;
     vector2 ActualVelocity = Physic.GetVelocity();
     vector2 Velocity;
     Velocity.y = 0.0f;
     Velocity.x = 500.0f; 
       Player.PlayerComponent->ApplyForce(Velocity);
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
     Dio->UseAbility(0);
     };
     SunListenersControl.AddListener(std::move(DioMoveLeftListener));

     
     struct MoveDown : Ability{
    void Activate(Player& Player)override{
     BodyArcadePhysic Physic;
     vector2 ActualVelocity = Physic.GetVelocity();
     vector2 Velocity;
     Velocity.x = 0.0f;
     Velocity.y = 500.0f; 
       Player.PlayerComponent->ApplyForce(Velocity);
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
      BodyArcadePhysic Physic;
     vector2 ActualVelocity = Physic.GetVelocity();
     vector2 Velocity;
     Velocity.x = 0.0f;
     Velocity.y = -500.0f; 
       Player.PlayerComponent->ApplyForce(Velocity);
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
     DioMainBody->Height = 50.0f;
     DioMainBody->Width = 200.0f;
     DioMainBody->OffsetX = 0.0f;
     DioMainBody->OffsetY = 0.0f;
     DioMainBody->SetCollisionLayer("DioHurtLayer");
     auto DioMainBodyPhysic = std::make_unique<BodyArcadePhysic>();
     DioMainBodyPhysic->SetMass(1.0f);
     DioMainBody->SetBodyArcadePhysic(std::move(DioMainBodyPhysic));

     auto DioMainBodySunPhysic = std::make_unique<BodySunPhysic>();
     DioMainBodySunPhysic->SetMass(0.2f);
     DioMainBody->SetBodySunPhysic(std::move(DioMainBodySunPhysic));
     
     DioBody->AddBody("DioMainBody",std::move(DioMainBody));
     Dio->PlayerComponent->AddBody(std::move(DioBody));

     
      SunCore::instance().SunWorld.CollisionsWorld.CollisionPhysic = CollisionPhysicTypes::SunPhysic;

   */
            

             
     

    };
    void OnUpdate() override{
     std::cout << "\n"<<SunCore::instance().SunWorld.GetWorldComponentsMap().find("PlayText")->second->GetRenderComponent()->X << "  ,  " << SunCore::instance().SunWorld.GetWorldComponentsMap().find("PlayText")->second->GetRenderComponent()->Y << " \n"  ;
    };
    
       

};
   
   InfinityAbyssConfig.Window.WindowName = "Infinity Abyss";
   MenuScene* Menu = new MenuScene();
   InfinityAbyssConfig.SunScenes.Scenes = {Menu};
   InfinityAbyssConfig.BodysDebug =true;
   
    
    
    
    
  

    StartEngine(InfinityAbyssConfig);
    return 0;
}