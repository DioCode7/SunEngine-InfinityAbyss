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

    class GameStartScene;
   
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

    enum class PlayerStates{
    WalkRight,
    WalkLeft,
    Idle
    };
    
    class Player{
 public:
 PlayerStates State = PlayerStates::Idle;
 Player(Component* PlayerComp,PlayerAttributesClass Atribu):PlayerComponent(PlayerComp),Attributes(Atribu){}
 Component* PlayerComponent;
 PlayerAttributesClass Attributes;
 std::vector<std::unique_ptr<Ability>> Abilities;
 void UseAbility(int Index){
  if(Index < Abilities.size()){
    Abilities[Index]->Activate(*this);
  }
 };

 void Update(){
  switch(State){
    case PlayerStates::Idle:{
    if(PlayerComponent->GetAnimation()->Id != "DioIdleAnimation"){
    auto* DioComponent = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioComponent")->second.get();
     auto* DioHair = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioHair")->second.get();
      auto* DioHead = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioHead")->second.get();
       auto* DioFallMark = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioFallMark")->second.get();
        auto* DioPants = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioPants")->second.get();
         auto* DioPantsBands = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioPantsBands")->second.get();
          auto* DioBoots = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioBoots")->second.get();
           auto* DioFrontBody = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioFrontBody")->second.get();
            auto* DioNamelessSword = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioNamelessSword")->second.get();
             auto* DioTShirt = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioTShirt")->second.get();
   DioComponent->SetAnimation("DioIdleAnimation");
        DioHair->SetAnimation("DioIdleHairAnimation");
   DioHead->SetAnimation("DioIdleHeadAnimation");
   DioBoots->SetAnimation("DioIdleBootsAnimation");
DioFallMark->SetAnimation("DioIdleFallMarkAnimation");
DioPants->SetAnimation("DioIdlePantsAnimation");
DioPantsBands->SetAnimation("DioIdlePantsBandsAnimation");
DioNamelessSword->SetAnimation("DioIdleNamelessSwordAnimation");
DioFrontBody->SetAnimation("DioIdleFrontBodyAnimation");     
DioTShirt->SetAnimation("DioIdleTShirtAnimation");
    }
    break;
    }
    case PlayerStates::WalkLeft:{
      BodyArcadePhysic Physic;
     vector2 ActualVelocity = Physic.GetVelocity();
     vector2 Velocity;
     Velocity.y = 0.0f;
     Velocity.x = -500.0f; 
       PlayerComponent->ApplyForce(Velocity);
    };
  }
 };


 
 


};


 Player* Dio;





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
          SunTextures.NewTexture("InfinityAbyssMenuArtTextureSky","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - Sky.png");
          SunTextures.NewTexture("InfinityAbyssMenuArtTextureSkyMist","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - SkyMist.png");
          SunTextures.NewTexture("InfinityAbyssMenuArtTextureSun","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - Sun.png");
              SunTextures.NewTexture("InfinityAbyssMenuArtTextureEarth","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - Earth.png");
  SunTextures.NewTexture("InfinityAbyssMenuArtTextureMidGrass1","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - MidGrass.png");
              SunTextures.NewTexture("InfinityAbyssMenuArtTextureMidGrass2","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - MidGrass2.png");      
      SunTextures.NewTexture("InfinityAbyssMenuArtTextureGrassFront","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - GrassFront.png");
      SunTextures.NewTexture("InfinityAbyssMenuArtTextureLastGrass","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - LastGrass.png");
      SunTextures.NewTexture("InfinityAbyssMenuArtTextureGrassBack1","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - GrassBack1.png");
    SunTextures.NewTexture("InfinityAbyssMenuArtTextureGrassBack2","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - GrassBack2.png");
      SunTextures.NewTexture("InfinityAbyssMenuArtTextureGrassBack3","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - GrassBack3.png");
  SunTextures.NewTexture("InfinityAbyssMenuArtTextureMist1","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - Mist1.png");
    SunTextures.NewTexture("InfinityAbyssMenuArtTextureMist2","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - Mist2.png");
      SunTextures.NewTexture("InfinityAbyssMenuArtTextureMist3","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - Mist3.png");
        SunTextures.NewTexture("InfinityAbyssMenuArtTextureMist4","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - Mist4.png");
  SunTextures.NewTexture("InfinityAbyssMenuArtTextureTree","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - Tree.png");
   SunTextures.NewTexture("InfinityAbyssMenuArtTextureTreeMask","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - TreeMask.png");
  SunTextures.NewTexture("InfinityAbyssMenuArtTextureHouseLight1","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - HouseLight1.png");
  SunTextures.NewTexture("InfinityAbyssMenuArtTextureHouseLight2","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - HouseLight2.png");
SunTextures.NewTexture("InfinityAbyssMenuArtTextureCabin","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - Cabin.png");
SunTextures.NewTexture("InfinityAbyssMenuArtTextureCabinMask","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - CabinMask.png");
SunTextures.NewTexture("InfinityAbyssMenuArtTextureGrassFrontMask","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - GrassFrontMask.png");
        SunTextures.NewTexture("InfinityAbyssMenuArtTextureMidGrass2Mask","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - MidGrass2Mask.png");  
    SunTextures.NewTexture("InfinityAbyssMenuArtTextureLastGrassMask","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - LastGrassMask.png");
            SunTextures.NewTexture("InfinityAbyssMenuArtTextureMidGrass1Mask","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - MidGrassMask.png");  
                  SunTextures.NewTexture("InfinityAbyssMenuArtTextureGrassBack1Mask","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - GrassBack1Mask.png");
    SunTextures.NewTexture("InfinityAbyssMenuArtTextureGrassBack2Mask","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - GrassBack2Mask.png");
      SunTextures.NewTexture("InfinityAbyssMenuArtTextureGrassBack3Mask","./Assets/Arts/MenuArt/InfinityAbyss - MenuBackground1 - GrassBack3Mask.png");
        
    
    SunTextures.NewTexture("PopUpShadowsContainer","./Assets/Hud/InfinityAbyss - PopUpContainerShadows.png");
    
    
    
    
    
    
    
    
    
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
         MenuContainer->SetRGBA(0.3f,0.3f,0.3f,1.0f);
         SunRendering.AddRectangle(std::move(MenuContainer),this);
         
auto CinzelSmallFont = std::make_unique<SunFont>();
         CinzelSmallFont->Id = "CinzelSmall";
         CinzelSmallFont->FontPath = "./Assets/Fonts/CinzelDecorative-Regular.ttf";
         CinzelSmallFont->Height = 13;
    
     
       SunTextControl.AddFont(std::move(CinzelSmallFont));

       auto CinzelMidFont = std::make_unique<SunFont>();
         CinzelMidFont->Id = "CinzelMid";
         CinzelMidFont->FontPath = "./Assets/Fonts/CinzelDecorative-Regular.ttf";
         CinzelMidFont->Height = 16;
    
     
       SunTextControl.AddFont(std::move(CinzelMidFont));
         
         
        auto CinzelFont = std::make_unique<SunFont>();
         CinzelFont->Id = "Cinzel";
         CinzelFont->FontPath = "./Assets/Fonts/CinzelDecorative-Regular.ttf";
         CinzelFont->Height = 24;
    
     
       SunTextControl.AddFont(std::move(CinzelFont));


       auto FullScreenListener = std::make_unique<SunListener>();
          FullScreenListener->Fn = [](SunEvent& e){
              WindowManipulate("LeaveFullScreen");
          };
          FullScreenListener->Id = "FullScreenListener";
          SunEventTrigger FullScreenListenerTrigger;
          FullScreenListenerTrigger.SetKeyboardTrigger(KeyboardTriggersType::KeyDown,KeyCodes::F11);
          FullScreenListener->Trigger = FullScreenListenerTrigger;
          FullScreenListener->UseFn = true;
          SunCore::instance().SunBrain.NewListener(std::move(FullScreenListener));
       

     UnitClass PlayButtonX;
     PlayButtonX.Unit = UnitType::Percent;
     PlayButtonX.Value = 0.165f;
   UnitClass PlayButtonY;
     PlayButtonY.Unit = UnitType::Percent;
     PlayButtonY.Value = 0.26f;
  UnitClass PlayButtonW;
     PlayButtonW.Unit = UnitType::Percent;
     PlayButtonW.Value = 0.15f;
    UnitClass PlayButtonH;
     PlayButtonH.Unit = UnitType::Percent;
     PlayButtonH.Value = 0.06f;
     auto PlayButton = std::make_unique<Component>("PlayButton",PlayButtonW,PlayButtonH,PlayButtonX,PlayButtonY,OriginClass::Center);
     PlayButton->SetRGBA(0.1,0.4,0.0,0.0);
     SunRendering.AddRectangle(
      std::move(PlayButton),
      this
     );
      

     
     UnitClass OptionsButtonX;
     OptionsButtonX.Unit = UnitType::Percent;
     OptionsButtonX.Value = 0.165f;
   UnitClass OptionsButtonY;
     OptionsButtonY.Unit = UnitType::Percent;
     OptionsButtonY.Value = 0.33f;
  UnitClass OptionsButtonW;
     OptionsButtonW.Unit = UnitType::Percent;
     OptionsButtonW.Value = 0.15f;
    UnitClass OptionsButtonH;
     OptionsButtonH.Unit = UnitType::Percent;
     OptionsButtonH.Value = 0.06f;
     auto OptionsButton = std::make_unique<Component>("OptionsButton",OptionsButtonW,OptionsButtonH,OptionsButtonX,OptionsButtonY,OriginClass::Center);
     OptionsButton->SetRGBA(0.1,0.4,0.0,0.0);
     SunRendering.AddRectangle(
      std::move(OptionsButton),
      this
     );
   

     
     UnitClass CreditsButtonX;
     CreditsButtonX.Unit = UnitType::Percent;
     CreditsButtonX.Value = 0.165f;
   UnitClass CreditsButtonY;
     CreditsButtonY.Unit = UnitType::Percent;
     CreditsButtonY.Value = 0.40f;
  UnitClass CreditsButtonW;
     CreditsButtonW.Unit = UnitType::Percent;
     CreditsButtonW.Value = 0.15f;
    UnitClass CreditsButtonH;
     CreditsButtonH.Unit = UnitType::Percent;
     CreditsButtonH.Value = 0.06f;
     auto CreditsButton = std::make_unique<Component>("CreditsButton",CreditsButtonW,CreditsButtonH,CreditsButtonX,CreditsButtonY,OriginClass::Center);
     CreditsButton->SetRGBA(0.1,0.4,0.0,0.0);
     SunRendering.AddRectangle(
      std::move(CreditsButton),
      this
     );
   

  
     UnitClass LeaveButtonX;
     LeaveButtonX.Unit = UnitType::Percent;
     LeaveButtonX.Value = 0.165f;
   UnitClass LeaveButtonY;
     LeaveButtonY.Unit = UnitType::Percent;
     LeaveButtonY.Value = 0.47f;
  UnitClass LeaveButtonW;
     LeaveButtonW.Unit = UnitType::Percent;
     LeaveButtonW.Value = 0.15f;
    UnitClass LeaveButtonH;
     LeaveButtonH.Unit = UnitType::Percent;
     LeaveButtonH.Value = 0.06f;
     auto LeaveButton = std::make_unique<Component>("LeaveButton",LeaveButtonW,LeaveButtonH,LeaveButtonX,LeaveButtonY,OriginClass::Center);
     LeaveButton->SetRGBA(0.1,0.4,0.0,0.0);
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
     auto InfinityAbyssMenuArtSky = std::make_unique<Component>(
      "InfinityAbyssMenuArtSky",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtSky->SetTexture("InfinityAbyssMenuArtTextureSky");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtSky),
      this
     );

       auto InfinityAbyssMenuArtSun = std::make_unique<Component>(
      "InfinityAbyssMenuArtSun",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtSun->SetTexture("InfinityAbyssMenuArtTextureSun");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtSun),
      this
     );

       auto InfinityAbyssMenuArtSkyMist = std::make_unique<Component>(
      "InfinityAbyssMenuArtSkyMist",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtSkyMist->SetTexture("InfinityAbyssMenuArtTextureSkyMist");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtSkyMist),
      this
     );

       auto InfinityAbyssMenuArtEarth = std::make_unique<Component>(
      "InfinityAbyssMenuArtEarth",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtEarth->SetTexture("InfinityAbyssMenuArtTextureEarth");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtEarth),
      this
     );

      auto InfinityAbyssMenuArtLastGrass = std::make_unique<Component>(
      "InfinityAbyssMenuArtLastGrass",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtLastGrass->SetTexture("InfinityAbyssMenuArtTextureLastGrass");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtLastGrass),
      this
     );

     auto& MenuLastGrass =  SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtLastGrass")->second;
     MenuLastGrass->SetTextureMask("InfinityAbyssMenuArtTextureLastGrassMask");

     
       auto InfinityAbyssMenuArtMist3 = std::make_unique<Component>(
      "InfinityAbyssMenuArtMist3",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtMist3->SetTexture("InfinityAbyssMenuArtTextureMist3");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtMist3),
      this
     );



        auto InfinityAbyssMenuArtGrassBack3 = std::make_unique<Component>(
      "InfinityAbyssMenuArtGrassBack3",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtGrassBack3->SetTexture("InfinityAbyssMenuArtTextureGrassBack3");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtGrassBack3),
      this
     );

       
 auto& MenuGrassBack3 = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtGrassBack3")->second;
     MenuGrassBack3->SetTextureMask("InfinityAbyssMenuArtTextureGrassBack3Mask");

     


          auto InfinityAbyssMenuArtHouseLight2 = std::make_unique<Component>(
      "InfinityAbyssMenuArtHouseLight2",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start

      );

     InfinityAbyssMenuArtHouseLight2->SetTexture("InfinityAbyssMenuArtTextureHouseLight2");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtHouseLight2),
      this
     );


       auto InfinityAbyssMenuArtCabin = std::make_unique<Component>(
      "InfinityAbyssMenuArtCabin",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
       
      );

     InfinityAbyssMenuArtCabin->SetTexture("InfinityAbyssMenuArtTextureCabin");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtCabin),
      this
     );

     auto& MenuCabin = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtCabin")->second;
     MenuCabin->SetTextureMask("InfinityAbyssMenuArtTextureCabinMask");
     

     


     
       auto InfinityAbyssMenuArtTree = std::make_unique<Component>(
      "InfinityAbyssMenuArtTree",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtTree->SetTexture("InfinityAbyssMenuArtTextureTree");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtTree),
      this
     );

  auto& MenuTree = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtTree")->second;
     MenuTree->SetTextureMask("InfinityAbyssMenuArtTextureTreeMask");


     
       auto InfinityAbyssMenuArtMist2 = std::make_unique<Component>(
      "InfinityAbyssMenuArtMist2",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtMist2->SetTexture("InfinityAbyssMenuArtTextureMist2");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtMist2),
      this
     );

    

       auto InfinityAbyssMenuArtGrassBack2 = std::make_unique<Component>(
      "InfinityAbyssMenuArtGrassBack2",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

      
     InfinityAbyssMenuArtGrassBack2->SetTexture("InfinityAbyssMenuArtTextureGrassBack2");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtGrassBack2),
      this
     );

       
 auto& MenuGrassBack2 = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtGrassBack2")->second;
     MenuGrassBack2->SetTextureMask("InfinityAbyssMenuArtTextureGrassBack2Mask");

     


      
         auto InfinityAbyssMenuArtMidGrass2 = std::make_unique<Component>(
      "InfinityAbyssMenuArtMidGrass2",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtMidGrass2->SetTexture("InfinityAbyssMenuArtTextureMidGrass2");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtMidGrass2),
      this
     );

      auto& MenuMidGrass2 = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtMidGrass2")->second;
      MenuMidGrass2->SetTextureMask("InfinityAbyssMenuArtTextureMidGrass2Mask");
     
       auto InfinityAbyssMenuArtMist4 = std::make_unique<Component>(
      "InfinityAbyssMenuArtMist4",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtMist4->SetTexture("InfinityAbyssMenuArtTextureMist4");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtMist4),
      this
     );

            auto InfinityAbyssMenuArtHouseLight1 = std::make_unique<Component>(
      "InfinityAbyssMenuArtHouseLight1",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtHouseLight1->SetTexture("InfinityAbyssMenuArtTextureHouseLight1");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtHouseLight1),
      this
     );

       auto InfinityAbyssMenuArtMidGrass1 = std::make_unique<Component>(
      "InfinityAbyssMenuArtMidGrass1",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );



     InfinityAbyssMenuArtMidGrass1->SetTexture("InfinityAbyssMenuArtTextureMidGrass1");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtMidGrass1),
      this
     );

     
      auto& MenuMidGrass = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtMidGrass1")->second;
      MenuMidGrass->SetTextureMask("InfinityAbyssMenuArtTextureMidGrass1Mask");




          auto InfinityAbyssMenuArtGrassBack1 = std::make_unique<Component>(
      "InfinityAbyssMenuArtGrassBack1",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtGrassBack1->SetTexture("InfinityAbyssMenuArtTextureGrassBack1");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtGrassBack1),
      this
     );

     
 auto& MenuGrassBack = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtGrassBack1")->second;
     MenuGrassBack->SetTextureMask("InfinityAbyssMenuArtTextureGrassBack1Mask");

     





       auto InfinityAbyssMenuArtGrassFront = std::make_unique<Component>(
      "InfinityAbyssMenuArtGrassFront",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtGrassFront->SetTexture("InfinityAbyssMenuArtTextureGrassFront");
   
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtGrassFront),
      this
     );

 auto& MenuGrassFront = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtGrassFront")->second;
     MenuGrassFront->SetTextureMask("InfinityAbyssMenuArtTextureGrassFrontMask");

       auto InfinityAbyssMenuArtMist1 = std::make_unique<Component>(
      "InfinityAbyssMenuArtMist1",
       InfinityAbyssMenuArtW,
       InfinityAbyssMenuArtH,
        InfinityAbyssMenuArtX,
       InfinityAbyssMenuArtY,
       OriginClass::Start,
       OriginClass::Start
      );

     InfinityAbyssMenuArtMist1->SetTexture("InfinityAbyssMenuArtTextureMist1");
     SunRendering.AddSprite(
      std::move(InfinityAbyssMenuArtMist1),
      this
     );

     
     

     

        const char* MenuWindVertexShader = R"(
        #version 330 core

                layout (location = 0) in vec3 aPos;
                layout (location = 1) in vec2 aUV;

                out vec2 vUV;

                uniform vec2 uSunPos;     
                uniform vec2 uSunSize;
                uniform mat4 uSunProjection;
                    
                    
                void main(){
              
              gl_Position = uSunProjection * vec4(aPos.xy, 0.0, 1.0);
              vUV = aUV;
               
                }
        
        )";

          const char* MenuWindFragmentShader = R"(
      #version 330 core

      in vec2 vUV;


      uniform float wind_intensity;
      uniform float wind_direction;
      uniform sampler2D uSunTexture;
      uniform sampler2D uSunTextureMask;
      uniform float uSunTime;
      out vec4 FragColor;

      float hash(vec2 p){
          return fract(sin(dot(p, vec2(127.1,311.7))) * 43758.5453);
      };

      float noise(vec2 p){
        vec2 i = floor(p);
        vec2 f = fract(p);

        float a = hash(i);
        float b = hash(i + vec2(1.0,0.0));
        float c = hash(i + vec2(0.0,1.0));
        float d = hash(i + vec2(1.0,1.0));

        vec2 u = f * f * (3.0 - 2.0 * f);

        return mix(a,b,u.x) +
        (c - a) * u.y * (1.0 -u.x) +
        (d- b) * u.x * u.y;
      };

      float fbm(vec2 p)
{
    float value = 0.0;
    float amplitude = 0.5;
    float frequency = 1.0;

    for(int i = 0; i < 5; i++)
    {
        value += amplitude * noise(p * frequency);
        frequency *= 2.0;
        amplitude *= 0.5;
    }

    return value;
}

      void main(){

          vec2 uv = vUV;

          float Noise = fbm(uv * 14.0 + uSunTime * 0.6) * 0.017;

          float Mask = texture(uSunTextureMask,vUV).r;
          Mask = clamp(Mask,0.14,1.0);

          uv.x += (Noise * Mask) * wind_intensity;
          uv.y +=  ((Noise * Mask) * wind_intensity) * 5.0;

          vec4 texColor = texture(uSunTexture, uv);
          FragColor = texColor;
      }
          
          )";

    GLuint MenuWindShaderProgram = CreateFullShaderProgram(MenuWindVertexShader,MenuWindFragmentShader);


     Component* MenuComponent = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArt")->second.get();


    std::unique_ptr<ShaderUniform> uMenuWindIntensity = std::make_unique<ShaderUniform>();
    uMenuWindIntensity->Type = UniformType::OneFloat;

      std::unique_ptr<ShaderUniform> uMenuWindDirection = std::make_unique<ShaderUniform>();
    uMenuWindDirection->Type = UniformType::OneFloat;

  
     std::unique_ptr<SunShader>MenuWindShader = std::make_unique<SunShader>();

     MenuWindShader->SetShaderProgram(MenuWindShaderProgram);
        SunCore::instance().SunShaders.AddShaderToWorld("MenuWindShader",std::move(MenuWindShader));
   auto* RMenuWindShader =  SunCore::instance().SunShaders.GetShader("MenuWindShader");
   RMenuWindShader->AddUniform("wind_direction",std::move(uMenuWindDirection));
      RMenuWindShader->AddUniform("wind_intensity",std::move(uMenuWindIntensity));
        
  
     SunCore::instance().SunWorld.AddMaterialToWorld("MenuWindMaterial","MenuWindShader");
     Material* MenuMaterial = SunCore::instance().SunWorld.GetMaterial("MenuWindMaterial");
     
          MenuMaterial->AddFloatUniform("wind_direction",-1.0f);    
          MenuMaterial->AddFloatUniform("wind_intensity",1.7f);

   
   MenuGrassFront->AddMaterial("MenuWindMaterial");

 MenuMidGrass2->AddMaterial("MenuWindMaterial"); 
  MenuMidGrass->AddMaterial("MenuWindMaterial"); 
 MenuLastGrass->AddMaterial("MenuWindMaterial");
  MenuGrassBack2->AddMaterial("MenuWindMaterial"); 
  MenuGrassBack->AddMaterial("MenuWindMaterial"); 
 MenuGrassBack3->AddMaterial("MenuWindMaterial");



  



     
  
     UnitClass InfinityAbyssLetterX;
     InfinityAbyssLetterX.Unit = UnitType::Percent;
     InfinityAbyssLetterX.Value = 0.17f;
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
       OriginClass::Center
      );

     InfinityAbyssLetter->SetTexture("InfinityAbyssLetterTexture");
     SunRendering.AddSprite(
      std::move(InfinityAbyssLetter),
      this
     );
   
     
     



        const char* MenuCabinLightVertexShader = R"(
        #version 330 core

                layout (location = 0) in vec3 aPos;
                layout (location = 1) in vec2 aUV;

                out vec2 vUV;

                uniform vec2 uSunPos;     
                uniform vec2 uSunSize;
                uniform mat4 uSunProjection;
                    
                    
                void main(){
              
              gl_Position = uSunProjection * vec4(aPos.xy, 0.0, 1.0);
              vUV = aUV;
               
                }
        
        )";

          const char* MenuCabinLightFragmentShader = R"(
      #version 330 core

      in vec2 vUV;


   
      uniform sampler2D uSunTexture;
      uniform sampler2D uSunTextureMask;
      uniform float uSunTime;
      out vec4 FragColor;

      float hash(vec2 p){
          return fract(sin(dot(p, vec2(127.1,311.7))) * 43758.5453);
      };

      float noise(vec2 p){
        vec2 i = floor(p);
        vec2 f = fract(p);

        float a = hash(i);
        float b = hash(i + vec2(1.0,0.0));
        float c = hash(i + vec2(0.0,1.0));
        float d = hash(i + vec2(1.0,1.0));

        vec2 u = f * f * (3.0 - 2.0 * f);

        return mix(a,b,u.x) +
        (c - a) * u.y * (1.0 -u.x) +
        (d- b) * u.x * u.y;
      };

      float fbm(vec2 p)
{
    float value = 0.0;
    float amplitude = 0.5;
    float frequency = 1.0;

    for(int i = 0; i < 5; i++)
    {
        value += amplitude * noise(p * frequency);
        frequency *= 2.0;
        amplitude *= 0.5;
    }

    return value;
}

      void main(){
        vec2 uv = vUV;
          float Noise = fbm(uv * 20.0 + uSunTime * 1.2) * 0.9;
         
          vec4 tex = texture(uSunTexture,uv);
          tex.a -= fbm(vec2(uv.x * 2.0, 2.0) + uSunTime) * 0.4;
        
        
          FragColor = tex;
      }
          
          )";
     std::unique_ptr<SunShader>MenuCabinLightShader = std::make_unique<SunShader>();
     
    GLuint MenuCabinLightShaderProgram = CreateFullShaderProgram(MenuCabinLightVertexShader,MenuCabinLightFragmentShader);
    MenuCabinLightShader->SetShaderProgram(MenuCabinLightShaderProgram);

    SunCore::instance().SunShaders.AddShaderToWorld("MenuCabinLightShader",std::move(MenuCabinLightShader));
   auto* RMenuCabinLightShader =  SunCore::instance().SunShaders.GetShader("MenuCabinLightShader");

    SunCore::instance().SunWorld.AddMaterialToWorld("MenuCabinLightMaterial","MenuCabinLightShader");
     Material* MenuCabinLightMaterial = SunCore::instance().SunWorld.GetMaterial("MenuCabinLightMaterial");
  MenuCabinLightMaterial->BlendMode = BlendOptions::Add;

     auto& MenuCabinLight = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtHouseLight1")->second;
          auto& MenuCabinLight2 = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtHouseLight2")->second;

          MenuCabinLight->AddMaterial("MenuCabinLightMaterial");
             MenuCabinLight2->AddMaterial("MenuCabinLightMaterial");





        const char* MenuMistVertexShader = R"(
        #version 330 core

                layout (location = 0) in vec3 aPos;
                layout (location = 1) in vec2 aUV;

                out vec2 vUV;

                uniform vec2 uSunPos;     
                uniform vec2 uSunSize;
                uniform mat4 uSunProjection;
                    
                    
                void main(){
              
              gl_Position = uSunProjection * vec4(aPos.xy, 0.0, 1.0);
              vUV = aUV;
               
                }
        
        )";


     const char* MenuMistFragmentShader = R"(
      #version 330 core

      in vec2 vUV;


   
      uniform sampler2D uSunTexture;
      uniform sampler2D uSunTextureMask;
      uniform float uSunTime;
      out vec4 FragColor;

      float hash(vec2 p){
          return fract(sin(dot(p, vec2(127.1,311.7))) * 43758.5453);
      };

      float noise(vec2 p){
        vec2 i = floor(p);
        vec2 f = fract(p);

        float a = hash(i);
        float b = hash(i + vec2(1.0,0.0));
        float c = hash(i + vec2(0.0,1.0));
        float d = hash(i + vec2(1.0,1.0));

        vec2 u = f * f * (3.0 - 2.0 * f);

        return mix(a,b,u.x) +
        (c - a) * u.y * (1.0 -u.x) +
        (d- b) * u.x * u.y;
      };

      float fbm(vec2 p)
{
    float value = 0.0;
    float amplitude = 0.5;
    float frequency = 1.0;

    for(int i = 0; i < 5; i++)
    {
        value += amplitude * noise(p * frequency);
        frequency *= 2.0;
        amplitude *= 0.5;
    }

    return value;
}

      void main(){
        vec2 uv = vUV;
        float t = sin(uSunTime * 0.2);
          float Noise = fbm(uv * 5.0 + uSunTime * 0.2) * 0.2;
               float NoiseAlpha = fbm(vUV * 2.0 + uSunTime * 0.5) * 0.2; 
          uv.x += Noise;
          uv.y -= Noise * 0.7;

          vec4 tex = texture(uSunTexture,uv);
       tex.a -= NoiseAlpha;
        
        
          FragColor = tex;
      }
          
          )";

     std::unique_ptr<SunShader>MenuMistShader = std::make_unique<SunShader>();
     
    GLuint MenuMistShaderProgram = CreateFullShaderProgram(MenuMistVertexShader,MenuMistFragmentShader);
    MenuMistShader->SetShaderProgram(MenuMistShaderProgram);

    SunCore::instance().SunShaders.AddShaderToWorld("MenuMistShader",std::move(MenuMistShader));
   auto* RMenuMistShader =  SunCore::instance().SunShaders.GetShader("MenuMistShader");

    SunCore::instance().SunWorld.AddMaterialToWorld("MenuMistMaterial","MenuMistShader");
     Material* MenuMistMaterial = SunCore::instance().SunWorld.GetMaterial("MenuMistMaterial");
//MenuMistMaterial->BlendMode = BlendOptions::Add;

 auto& MenuMist1 = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtMist1")->second;
  auto& MenuMist2 = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtMist2")->second;
   auto& MenuMist3 = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtMist3")->second;
    auto& MenuMist4 = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtMist4")->second;
     auto& MenuMistSkyMist = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtSkyMist")->second;

     MenuMist1->AddMaterial("MenuMistMaterial");
         MenuMist2->AddMaterial("MenuMistMaterial");
             MenuMist3->AddMaterial("MenuMistMaterial");
                 MenuMist4->AddMaterial("MenuMistMaterial");

                MenuMistSkyMist->AddMaterial("MenuMistMaterial");    
                
                

                

        const char* MenuSkyVertexShader = R"(
        #version 330 core

                layout (location = 0) in vec3 aPos;
                layout (location = 1) in vec2 aUV;

                out vec2 vUV;

                uniform vec2 uSunPos;     
                uniform vec2 uSunSize;
                uniform mat4 uSunProjection;
                    
                    
                void main(){
              
              gl_Position = uSunProjection * vec4(aPos.xy, 0.0, 1.0);
              vUV = aUV;
               
                }
        
        )";


     const char* MenuSkyFragmentShader = R"(
      #version 330 core

      in vec2 vUV;


   
      uniform sampler2D uSunTexture;
      uniform sampler2D uSunTextureMask;
      uniform float uSunTime;
      out vec4 FragColor;

      float hash(vec2 p){
          return fract(sin(dot(p, vec2(127.1,311.7))) * 43758.5453);
      };

      float noise(vec2 p){
        vec2 i = floor(p);
        vec2 f = fract(p);

        float a = hash(i);
        float b = hash(i + vec2(1.0,0.0));
        float c = hash(i + vec2(0.0,1.0));
        float d = hash(i + vec2(1.0,1.0));

        vec2 u = f * f * (3.0 - 2.0 * f);

        return mix(a,b,u.x) +
        (c - a) * u.y * (1.0 -u.x) +
        (d- b) * u.x * u.y;
      };

      float fbm(vec2 p)
{
    float value = 0.0;
    float amplitude = 0.5;
    float frequency = 1.0;

    for(int i = 0; i < 5; i++)
    {
        value += amplitude * noise(p * frequency);
        frequency *= 2.0;
        amplitude *= 0.5;
    }

    return value;
}

      void main(){
        vec2 uv = vUV;
        float t = sin(uSunTime * 0.2);
          float Noise = fbm(uv * 6.0 + uSunTime * 0.1);
        
          uv.x -= (Noise * 0.2) * sin(uSunTime * 0.1);
         

          vec4 tex = texture(uSunTexture,uv);
   
        
          FragColor = tex;
      }
          
          )";



     std::unique_ptr<SunShader>MenuSkyShader = std::make_unique<SunShader>();
     
    GLuint MenuSkyShaderProgram = CreateFullShaderProgram(MenuSkyVertexShader,MenuSkyFragmentShader);
    MenuSkyShader->SetShaderProgram(MenuSkyShaderProgram);

    SunCore::instance().SunShaders.AddShaderToWorld("MenuSkyShader",std::move(MenuSkyShader));
   auto* RMenuSkyShader =  SunCore::instance().SunShaders.GetShader("MenuSkyShader");

    SunCore::instance().SunWorld.AddMaterialToWorld("MenuSkyMaterial","MenuSkyShader");
     Material* MenuSkyMaterial = SunCore::instance().SunWorld.GetMaterial("MenuSkyMaterial");


 auto& MenuSky = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtSky")->second;
MenuSky->AddMaterial("MenuSkyMaterial");



        

        const char* MenuSunVertexShader = R"(
        #version 330 core

                layout (location = 0) in vec3 aPos;
                layout (location = 1) in vec2 aUV;

                out vec2 vUV;

                uniform vec2 uSunPos;     
                uniform vec2 uSunSize;
                uniform mat4 uSunProjection;
                    
                    
                void main(){
              
              gl_Position = uSunProjection * vec4(aPos.xy, 0.0, 1.0);
              vUV = aUV;
               
                }
        
        )";


     const char* MenuSunFragmentShader = R"(
      #version 330 core

      in vec2 vUV;


   
      uniform sampler2D uSunTexture;
      uniform sampler2D uSunTextureMask;
      uniform float uSunTime;
      out vec4 FragColor;

      float hash(vec2 p){
          return fract(sin(dot(p, vec2(127.1,311.7))) * 43758.5453);
      };

      float noise(vec2 p){
        vec2 i = floor(p);
        vec2 f = fract(p);

        float a = hash(i);
        float b = hash(i + vec2(1.0,0.0));
        float c = hash(i + vec2(0.0,1.0));
        float d = hash(i + vec2(1.0,1.0));

        vec2 u = f * f * (3.0 - 2.0 * f);

        return mix(a,b,u.x) +
        (c - a) * u.y * (1.0 -u.x) +
        (d- b) * u.x * u.y;
      };

      float fbm(vec2 p)
{
    float value = 0.0;
    float amplitude = 0.5;
    float frequency = 1.0;

    for(int i = 0; i < 5; i++)
    {
        value += amplitude * noise(p * frequency);
        frequency *= 2.0;
        amplitude *= 0.5;
    }

    return value;
}

      void main(){
        vec2 uv = vUV;
        float t = sin(uSunTime * 0.2);
          float Noise = fbm(uv * 30.0 + uSunTime * 0.1);
        
          uv -= (Noise * 0.3) * sin(uSunTime * 0.01);
         
          
          vec4 tex = texture(uSunTexture,uv);

        
          FragColor = tex;
      }
          
          )";

          

     std::unique_ptr<SunShader>MenuSunShader = std::make_unique<SunShader>();
     
    GLuint MenuSunShaderProgram = CreateFullShaderProgram(MenuSunVertexShader,MenuSunFragmentShader);
    MenuSunShader->SetShaderProgram(MenuSunShaderProgram);

    SunCore::instance().SunShaders.AddShaderToWorld("MenuSunShader",std::move(MenuSunShader));
   auto* RMenuSunShader =  SunCore::instance().SunShaders.GetShader("MenuSunShader");

    SunCore::instance().SunWorld.AddMaterialToWorld("MenuSunMaterial","MenuSunShader");
     Material* MenuSunMaterial = SunCore::instance().SunWorld.GetMaterial("MenuSunMaterial");


 auto& MenuSun = SunCore::instance().SunWorld.GetWorldComponentsMap().find("InfinityAbyssMenuArtSun")->second;
MenuSun->AddMaterial("MenuSunMaterial");




        const char* MenuCabinVertexShader = R"(
        #version 330 core

                layout (location = 0) in vec3 aPos;
                layout (location = 1) in vec2 aUV;

                out vec2 vUV;

                uniform vec2 uSunPos;     
                uniform vec2 uSunSize;
                uniform mat4 uSunProjection;
                    
                    
                void main(){
              
              gl_Position = uSunProjection * vec4(aPos.xy, 0.0, 1.0);
              vUV = aUV;
               
                }
        
        )";


     const char* MenuCabinFragmentShader = R"(
      #version 330 core

      in vec2 vUV;


   
      uniform sampler2D uSunTexture;
      uniform sampler2D uSunTextureMask;
      uniform float uSunTime;
      out vec4 FragColor;

      float hash(vec2 p){
          return fract(sin(dot(p, vec2(127.1,311.7))) * 43758.5453);
      };

      float noise(vec2 p){
        vec2 i = floor(p);
        vec2 f = fract(p);

        float a = hash(i);
        float b = hash(i + vec2(1.0,0.0));
        float c = hash(i + vec2(0.0,1.0));
        float d = hash(i + vec2(1.0,1.0));

        vec2 u = f * f * (3.0 - 2.0 * f);

        return mix(a,b,u.x) +
        (c - a) * u.y * (1.0 -u.x) +
        (d- b) * u.x * u.y;
      };

      float fbm(vec2 p)
{
    float value = 0.0;
    float amplitude = 0.5;
    float frequency = 1.0;

    for(int i = 0; i < 5; i++)
    {
        value += amplitude * noise(p * frequency);
        frequency *= 2.0;
        amplitude *= 0.5;
    }

    return value;
}

      void main(){
        vec2 uv = vUV;
        float t = sin(uSunTime * 0.2);
          float Noise = fbm(uv * 50.0 + uSunTime * 0.5);
        
          vec4 mask = texture(uSunTextureMask,uv);
          uv.y += (Noise * 0.1) * mask.r;
         
          
          vec4 tex = texture(uSunTexture,uv);

        
          FragColor = tex;
      }
          
          )";

          

     std::unique_ptr<SunShader>MenuCabinShader = std::make_unique<SunShader>();
     
    GLuint MenuCabinShaderProgram = CreateFullShaderProgram(MenuCabinVertexShader,MenuCabinFragmentShader);
    MenuCabinShader->SetShaderProgram(MenuCabinShaderProgram);

    SunCore::instance().SunShaders.AddShaderToWorld("MenuCabinShader",std::move(MenuCabinShader));
   auto* RMenuCabinShader =  SunCore::instance().SunShaders.GetShader("MenuCabinShader");

    SunCore::instance().SunWorld.AddMaterialToWorld("MenuCabinMaterial","MenuCabinShader");
     Material* MenuCabinMaterial = SunCore::instance().SunWorld.GetMaterial("MenuCabinMaterial");


MenuCabin->AddMaterial("MenuCabinMaterial");






        const char* MenuTreeVertexShader = R"(
        #version 330 core

                layout (location = 0) in vec3 aPos;
                layout (location = 1) in vec2 aUV;

                out vec2 vUV;

                uniform vec2 uSunPos;     
                uniform vec2 uSunSize;
                uniform mat4 uSunProjection;
                    
                    
                void main(){
              
              gl_Position = uSunProjection * vec4(aPos.xy, 0.0, 1.0);
              vUV = aUV;
               
                }
        
        )";


     const char* MenuTreeFragmentShader = R"(
      #version 330 core

      in vec2 vUV;


   
      uniform sampler2D uSunTexture;
      uniform sampler2D uSunTextureMask;
      uniform float uSunTime;
      out vec4 FragColor;

      float hash(vec2 p){
          return fract(sin(dot(p, vec2(127.1,311.7))) * 43758.5453);
      };

      float noise(vec2 p){
        vec2 i = floor(p);
        vec2 f = fract(p);

        float a = hash(i);
        float b = hash(i + vec2(1.0,0.0));
        float c = hash(i + vec2(0.0,1.0));
        float d = hash(i + vec2(1.0,1.0));

        vec2 u = f * f * (3.0 - 2.0 * f);

        return mix(a,b,u.x) +
        (c - a) * u.y * (1.0 -u.x) +
        (d- b) * u.x * u.y;
      };

      float fbm(vec2 p)
{
    float value = 0.0;
    float amplitude = 0.5;
    float frequency = 1.0;

    for(int i = 0; i < 5; i++)
    {
        value += amplitude * noise(p * frequency);
        frequency *= 2.0;
        amplitude *= 0.5;
    }

    return value;
}

      void main(){
        vec2 uv = vUV;
        float t = sin(uSunTime * 0.2);

        
          vec4 mask = texture(uSunTextureMask,uv);

                    float Noise = fbm((uv * 50.0 * (mask.r)) + uSunTime * 0.5);
                    if(mask.r > 0.0){
          uv.y -= (Noise * 0.014);
    }
          
          vec4 tex = texture(uSunTexture,uv);

        
          FragColor = tex;
      }
          
          )";

          

     std::unique_ptr<SunShader>MenuTreeShader = std::make_unique<SunShader>();
     
    GLuint MenuTreeShaderProgram = CreateFullShaderProgram(MenuTreeVertexShader,MenuTreeFragmentShader);
    MenuTreeShader->SetShaderProgram(MenuTreeShaderProgram);

    SunCore::instance().SunShaders.AddShaderToWorld("MenuTreeShader",std::move(MenuTreeShader));
   auto* RMenuTreeShader =  SunCore::instance().SunShaders.GetShader("MenuTreeShader");

    SunCore::instance().SunWorld.AddMaterialToWorld("MenuTreeMaterial","MenuTreeShader");
     Material* MenuTreeMaterial = SunCore::instance().SunWorld.GetMaterial("MenuTreeMaterial");


MenuTree->AddMaterial("MenuTreeMaterial");







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
       PlayTextComponent->SetRGBA(1.0f,1.0f,1.0f,1.0f);
       PlayTextComponent->SetCharatersMargin(5.0f,0);
       PlayTextComponent->SetTextAlingX(Align::Center);
        PlayTextComponent->SetTextAlingY(Align::Center);
       SunRendering.AddText(
        std::move(PlayTextComponent),
        "Cinzel",
        "Jogar",
        this,
        SunCore::instance().SunWorld.GetWorldComponentsMap().find("PlayButton")->second.get()
      );

         auto OptionsTextComponent = std::make_unique<Component>("OptionsText",PlayTextW,PlayTextH,PlayTextX,PlayTextY,OriginClass::Start,OriginClass::Start);
       OptionsTextComponent->SetRGBA(1.0f,1.0f,1.0f,1.0f);
       OptionsTextComponent->SetCharatersMargin(5.0f,0);
       OptionsTextComponent->SetTextAlingX(Align::Center);
        OptionsTextComponent->SetTextAlingY(Align::Center);
       SunRendering.AddText(
        std::move(OptionsTextComponent),
        "Cinzel",
        "Opcoes",
        this,
        SunCore::instance().SunWorld.GetWorldComponentsMap().find("OptionsButton")->second.get()
      );

      
         auto CreditsTextComponent = std::make_unique<Component>("CreditsText",PlayTextW,PlayTextH,PlayTextX,PlayTextY,OriginClass::Start,OriginClass::Start);
       CreditsTextComponent->SetRGBA(1.0f,1.0f,1.0f,1.0f);
       CreditsTextComponent->SetCharatersMargin(5.0f,0);
       CreditsTextComponent->SetTextAlingX(Align::Center);
        CreditsTextComponent->SetTextAlingY(Align::Center);
       SunRendering.AddText(
        std::move(CreditsTextComponent),
        "Cinzel",
        "Creditos",
        this,
        SunCore::instance().SunWorld.GetWorldComponentsMap().find("CreditsButton")->second.get()
      );

      
         auto LeaveTextComponent = std::make_unique<Component>("LeaveText",PlayTextW,PlayTextH,PlayTextX,PlayTextY,OriginClass::Start,OriginClass::Start);
       LeaveTextComponent->SetRGBA(1.0f,1.0f,1.0f,1.0f);
       LeaveTextComponent->SetCharatersMargin(5.0f,0);
       LeaveTextComponent->SetTextAlingX(Align::Center);
        LeaveTextComponent->SetTextAlingY(Align::Center);
       SunRendering.AddText(
        std::move(LeaveTextComponent),
        "Cinzel",
        "Sair",
        this,
        SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeaveButton")->second.get()
      );

      
  
     UnitClass FooterCreditsContainerX;
     FooterCreditsContainerX.Unit = UnitType::Percent;
     FooterCreditsContainerX.Value = 0.98f;
     UnitClass FooterCreditsContainerY;
     FooterCreditsContainerY.Unit = UnitType::Percent;
     FooterCreditsContainerY.Value = 1.0f;
     UnitClass FooterCreditsContainerW;
     FooterCreditsContainerW.Unit = UnitType::Percent;
     FooterCreditsContainerW.Value = 0.4f;
      UnitClass FooterCreditsContainerH;
     FooterCreditsContainerH.Unit = UnitType::Percent;
     FooterCreditsContainerH.Value = 0.05f;
     auto FooterCreditsContainer = std::make_unique<Component>("FooterCreditsContainer",
      FooterCreditsContainerW,
      FooterCreditsContainerH,
      FooterCreditsContainerX,
      FooterCreditsContainerY,
      OriginClass::End,
      OriginClass::End);
      FooterCreditsContainer->SetRGBA(1.0f,0.0f,0.0f,0.0f);
      SunRendering.AddRectangle(
        std::move(FooterCreditsContainer),
        this
      );

      
     UnitClass FooterCreditsTextX;
     UnitClass FooterCreditsTextY;
     UnitClass FooterCreditsTextW;
      UnitClass FooterCreditsTextH;
     auto FooterCreditsText = std::make_unique<Component>("FooterCreditsText",
    PlayTextW,PlayTextH,PlayTextX,PlayTextY,
      OriginClass::Start,
      OriginClass::Start);
      FooterCreditsText->SetCharatersMargin(1.0f,0.0f);
      
      SunRendering.AddText(
        std::move(FooterCreditsText),
        "CinzelSmall",
        "@LucSun 2026. Todos Os Direitos Reservados. Ver. 0.1 Alpha",
        this,
        SunCore::instance().SunWorld.GetWorldComponentsMap().find("FooterCreditsContainer")->second.get()
      );

      SunCore::instance().SunWorld.GetWorldComponentsMap().find("FooterCreditsText")->second->SetTextAlingX(Align::End);
   SunCore::instance().SunWorld.GetWorldComponentsMap().find("FooterCreditsText")->second->SetTextAlingY(Align::Center);
     


  auto LeaveButtonListener = std::make_unique<SunListener>();
  SunEventTrigger LeaveButtonListenerTrigger;
  LeaveButtonListenerTrigger.SetMouseTrigger(MouseTriggersType::PointerDown,MouseButtons::LMB,
  SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeaveButton")->second.get());
  LeaveButtonListenerTrigger.SetKeyboardTrigger(KeyboardTriggersType::KeyDown,KeyCodes::A);
  LeaveButtonListener->UseFn = true;
  LeaveButtonListener->Trigger = LeaveButtonListenerTrigger;
  LeaveButtonListener->Id = "LeaveButtonListener";
  

  auto LeavePopUp = std::make_unique<PopUpComponent>();
  LeavePopUp->OwnerScene = this;
  UnitClass LeavePopUpContainerX;
  LeavePopUpContainerX.Unit = UnitType::Percent;
  LeavePopUpContainerX.Value = -0.3f;
  UnitClass LeavePopUpContainerY;
  LeavePopUpContainerY.Unit = UnitType::Percent;
  LeavePopUpContainerY.Value = 0.5f;
  UnitClass LeavePopUpContainerW;
  LeavePopUpContainerW.Unit = UnitType::Percent;
  LeavePopUpContainerW.Value = 0.6f;
  UnitClass LeavePopUpContainerH;
  LeavePopUpContainerH.Unit = UnitType::Percent;
  LeavePopUpContainerH.Value = 0.4f;

  

  auto LeavePopUpContainer = std::make_unique<Component>("LeavePopUpContainer",LeavePopUpContainerW,LeavePopUpContainerH,LeavePopUpContainerX,LeavePopUpContainerY,
  OriginClass::Center,OriginClass::Center);
  LeavePopUpContainer->SetRGBA(0.3,0.3,0.3,1.0);


  UnitClass LeavePopUpTextX;
  LeavePopUpTextX.Unit = UnitType::Percent;
  LeavePopUpTextX.Value = 0.5f;
  UnitClass LeavePopUpTextY;
  LeavePopUpTextY.Unit = UnitType::Percent;
  LeavePopUpTextY.Value = 0.3f;
  UnitClass LeavePopUpTextW;
  LeavePopUpTextW.Unit = UnitType::Percent;
  LeavePopUpTextW.Value = 0.0f;
  UnitClass LeavePopUpTextH;
  LeavePopUpTextH.Unit = UnitType::Percent;
  LeavePopUpTextH.Value = 0.0f;

  PopUpAdditionalConfigs LeavePopUpTextConfigs;
  LeavePopUpTextConfigs.Font = "Cinzel";
  LeavePopUpTextConfigs.Text = "Deseja Sair Do Jogo?";

  

  auto LeavePopUpText = std::make_unique<Component>("LeavePopUpText",LeavePopUpTextW,LeavePopUpTextH,LeavePopUpTextX,LeavePopUpTextY,
  OriginClass::Center,OriginClass::Center);
  LeavePopUpText->SetRGBA(1.0,1.0,1.0,1.0);
  LeavePopUpText->SetTextAlingX(Align::Center);


  
  UnitClass LeavePopUpButtonNoX;
  LeavePopUpButtonNoX.Unit = UnitType::Percent;
  LeavePopUpButtonNoX.Value = 0.65f;
  UnitClass LeavePopUpButtonNoY;
  LeavePopUpButtonNoY.Unit = UnitType::Percent;
  LeavePopUpButtonNoY.Value = 0.6f;
  UnitClass LeavePopUpButtonNoW;
  LeavePopUpButtonNoW.Unit = UnitType::Percent;
  LeavePopUpButtonNoW.Value = 0.1f;
  UnitClass LeavePopUpButtonNoH;
  LeavePopUpButtonNoH.Unit = UnitType::Percent;
  LeavePopUpButtonNoH.Value = 0.09f;

  PopUpAdditionalConfigs LeavePopUpNoButtonConfigs;


  

  auto LeavePopUpButtonNo = std::make_unique<Component>("LeavePopUpButtonNo",LeavePopUpButtonNoW,LeavePopUpButtonNoH,LeavePopUpButtonNoX,LeavePopUpButtonNoY,
  OriginClass::End,OriginClass::Center);
  LeavePopUpButtonNo->SetRGBA(0.0,0.0,0.0,0.0);


  UnitClass LeavePopUpTextNoX;
  LeavePopUpTextNoX.Unit = UnitType::Percent;
  LeavePopUpTextNoX.Value = 0.5f;
  UnitClass LeavePopUpTextNoY;
  LeavePopUpTextNoY.Unit = UnitType::Percent;
  LeavePopUpTextNoY.Value = 0.3f;
  UnitClass LeavePopUpTextNoW;
  LeavePopUpTextNoW.Unit = UnitType::Percent;
  LeavePopUpTextNoW.Value = 0.0f;
  UnitClass LeavePopUpTextNoH;
  LeavePopUpTextNoH.Unit = UnitType::Percent;
  LeavePopUpTextNoH.Value = 0.0f;

  PopUpAdditionalConfigs LeavePopUpTextNoConfigs;
  LeavePopUpTextNoConfigs.Font = "CinzelMid";
  LeavePopUpTextNoConfigs.Text = "NAO";

  

  auto LeavePopUpTextNo = std::make_unique<Component>("LeavePopUpTextNo",LeavePopUpTextNoW,LeavePopUpTextNoH,LeavePopUpTextNoX,LeavePopUpTextNoY,
  OriginClass::Center,OriginClass::Center);
  LeavePopUpTextNo->SetRGBA(1.0,1.0,1.0,1.0);
  LeavePopUpTextNo->SetTextAlingX(Align::Center);
  LeavePopUpTextNo->SetTextAlingY(Align::Center);
    LeavePopUpTextNo->SetCharatersMargin(0.1,0.0);

  

  
  UnitClass LeavePopUpButtonYesX;
  LeavePopUpButtonYesX.Unit = UnitType::Percent;
  LeavePopUpButtonYesX.Value = 0.35f;
  UnitClass LeavePopUpButtonYesY;
  LeavePopUpButtonYesY.Unit = UnitType::Percent;
  LeavePopUpButtonYesY.Value = 0.6f;
  UnitClass LeavePopUpButtonYesW;
  LeavePopUpButtonYesW.Unit = UnitType::Percent;
  LeavePopUpButtonYesW.Value = 0.1f;
  UnitClass LeavePopUpButtonYesH;
  LeavePopUpButtonYesH.Unit = UnitType::Percent;
  LeavePopUpButtonYesH.Value = 0.09f;

  PopUpAdditionalConfigs LeavePopUpYesButtonConfigs;


  

  auto LeavePopUpButtonYes = std::make_unique<Component>("LeavePopUpButtonYes",LeavePopUpButtonYesW,LeavePopUpButtonYesH,LeavePopUpButtonYesX,LeavePopUpButtonYesY,
  OriginClass::Start,OriginClass::Center);
  LeavePopUpButtonYes->SetRGBA(0.0,0.0,0.0,0.0);


  UnitClass LeavePopUpTextYesX;
  LeavePopUpTextYesX.Unit = UnitType::Percent;
  LeavePopUpTextYesX.Value = 0.5f;
  UnitClass LeavePopUpTextYesY;
  LeavePopUpTextYesY.Unit = UnitType::Percent;
  LeavePopUpTextYesY.Value = 0.3f;
  UnitClass LeavePopUpTextYesW;
  LeavePopUpTextYesW.Unit = UnitType::Percent;
  LeavePopUpTextYesW.Value = 0.0f;
  UnitClass LeavePopUpTextYesH;
  LeavePopUpTextYesH.Unit = UnitType::Percent;
  LeavePopUpTextYesH.Value = 0.0f;

  PopUpAdditionalConfigs LeavePopUpTextYesConfigs;
  LeavePopUpTextYesConfigs.Font = "CinzelMid";
  LeavePopUpTextYesConfigs.Text = "SIM";

  

  auto LeavePopUpTextYes = std::make_unique<Component>("LeavePopUpTextYes",LeavePopUpTextYesW,LeavePopUpTextYesH,LeavePopUpTextYesX,LeavePopUpTextYesY,
  OriginClass::Center,OriginClass::Center);
  LeavePopUpTextYes->SetRGBA(1.0,1.0,1.0,1.0);
  LeavePopUpTextYes->SetTextAlingX(Align::Center);
  LeavePopUpTextYes->SetTextAlingY(Align::Center);
  LeavePopUpTextYes->SetCharatersMargin(0.1,0.0);






 LeavePopUp->ChildsInstantLeave = true;


     LeavePopUpContainer->SetTexture("PopUpShadowsContainer");

     
        const char* PopUpShadowsContainerVertexShader = R"(
        #version 330 core

                layout (location = 0) in vec3 aPos;
                layout (location = 1) in vec2 aUV;

                out vec2 vUV;

                uniform vec2 uSunPos;     
                uniform vec2 uSunSize;
                uniform mat4 uSunProjection;
                    
                    
                void main(){
              
              gl_Position = uSunProjection * vec4(aPos.xy, 0.0, 1.0);
              vUV = aUV;
               
                }
        
        )";


     const char* PopUpShadowsContainerFragmentShader = R"(
      #version 330 core

      in vec2 vUV;
      


   
      uniform sampler2D uSunTexture;
      uniform sampler2D uSunTextureMask;
      uniform float uSunTime;
      uniform float Start;
      uniform float EndTime;
      uniform float YesHoverStart;
      uniform float YesHoverEnd;
      uniform float YesOnHover;
      uniform vec2 hoverspot;
      out vec4 FragColor;



      float hash(vec2 p){
          return fract(sin(dot(p, vec2(127.1,311.7))) * 43758.5453);
      };

      float noise(vec2 p){
        vec2 i = floor(p);
        vec2 f = fract(p);

        float a = hash(i);
        float b = hash(i + vec2(1.0,0.0));
        float c = hash(i + vec2(0.0,1.0));
        float d = hash(i + vec2(1.0,1.0));

        vec2 u = f * f * (3.0 - 2.0 * f);

        return mix(a,b,u.x) +
        (c - a) * u.y * (1.0 -u.x) +
        (d- b) * u.x * u.y;
      };

      float fbm(vec2 p)
{
    float value = 0.0;
    float amplitude = 0.5;
    float frequency = 1.0;

    for(int i = 0; i < 5; i++)
    {
        value += amplitude * noise(p * frequency);
        frequency *= 2.0;
        amplitude *= 0.5;
    }

    return value;
}

      void main(){
        vec2 uv = vUV;
        float dt = uSunTime - Start;
        float startedge = 1.5;
         float d = distance(uv, vec2(0.5));
     float t = smoothstep(0.0,startedge,dt);

     float end_dt = uSunTime - EndTime;
        float end_edge = 1.0;
     float end_t = smoothstep(end_edge,0.0,end_dt);

     float end_distance = smoothstep(0.0,1.0,end_dt);

float end_progress = clamp(end_dt / end_edge, 0.0, 1.0);
float edge_noise = fbm(uv * 20.0 + uSunTime);

float end_sweep = smoothstep(
    1.0 - end_progress - edge_noise * 0.1,
    1.0 - end_progress,
    uv.x
);
     float yes_hover_dt = uSunTime - YesHoverStart;
     float yes_hover_edge = 1.5;
     float yes_hover_t = smoothstep(0.0,yes_hover_edge,yes_hover_dt);

        float yes_hover_end_dt = uSunTime - YesHoverEnd;
     float yes_hover_end_edge = 1.5;
     float yes_hover_end_t = smoothstep(0.0,yes_hover_end_edge,yes_hover_end_dt);

 

      float fade = smoothstep(0.01, 0.99, d);

     float dirx = smoothstep(0.0, 0.5, uv.x) - smoothstep(0.5, 1.0, uv.x);
      float diry = smoothstep(0.0, 0.5, uv.y) - smoothstep(0.5, 1.0, uv.y);
      uv.y -= smoothstep(startedge,fbm(vec2(uv.x * 20.0 + uSunTime * 0.6,uSunTime * 3.0)),dt);
    float line = 1.0 - smoothstep(0.04, 0.02, abs(uv.y - 0.5));

float progress = clamp(dt / startedge, 0.0, 1.0);



float sweep = smoothstep(progress - 0.1, progress, uv.x);

float StartNoise = (line * sweep);
      float Noise = fbm((uv * dirx) * 10.0 + uSunTime * 0.5);
     float end_noise = (fbm(vec2((uv.x * uv.y * dirx) * 100.0 + uSunTime * 10.0, uv.y * 10.0)));
    
  

     

          vec4 tex = texture(uSunTexture,uv);
         float FinalNoise = mix(StartNoise,Noise,t);
         tex.a -= mix(FinalNoise,end_noise,end_t) * fade * 0.5;
         uv -= mix(FinalNoise,end_noise,end_t) * fade * 0.5;

         float yes_distance = smoothstep(0.0,1.0,0.3 - distance(uv,hoverspot));

          float hover_noise = fbm((uv * dirx) * 30.0 + uSunTime * 3.0);
          float start_hover_noise = fbm(vec2((uv.y * uv.x * diry) * 100.0 + uSunTime * 20.0,uv.x * 10.0)) * 0.2;
          
          float hover_final_noise = mix(start_hover_noise,hover_noise,yes_hover_t);



          tex.a -= (hover_final_noise * yes_distance) * (YesOnHover + smoothstep(yes_hover_end_edge,0.0,yes_hover_end_t));
      
         if(tex.a < 0.95){
         discard;
         };
         tex.a = 1.0;
         tex.r = 0.0 + ((hover_final_noise * yes_distance) * (YesOnHover + (smoothstep(yes_hover_end_edge,0.0,yes_hover_end_t) * 0.6))) * 2.0;
         tex.b = 0.0;
         tex.g =  0.0 + ((hover_final_noise * yes_distance) * (YesOnHover + (smoothstep(yes_hover_end_edge,0.0,yes_hover_end_t)* 0.6))) * 0.3;

         if(uv.x < 0.05 || uv.x > 0.95){
         discard;
         }
          if(uv.y < 0.05 || uv.y > 0.95){
         discard;
         }


        
       
        
        
          FragColor = tex;
      }
          
          )";

     std::unique_ptr<SunShader>PopUpShadowsContainerShader = std::make_unique<SunShader>();
     
    GLuint PopUpShadowsContainerShaderProgram = CreateFullShaderProgram(PopUpShadowsContainerVertexShader,PopUpShadowsContainerFragmentShader);
   PopUpShadowsContainerShader->SetShaderProgram(PopUpShadowsContainerShaderProgram);

   auto StartUniform = std::make_unique<ShaderUniform>();
   StartUniform->Type = UniformType::OneFloat;

   auto EndTimeUniform = std::make_unique<ShaderUniform>();
   EndTimeUniform->Type = UniformType::OneFloat;


   auto YesStartUniform = std::make_unique<ShaderUniform>();
   YesStartUniform->Type = UniformType::OneFloat;

   
   auto YesEndUniform = std::make_unique<ShaderUniform>();
   YesEndUniform->Type = UniformType::OneFloat;
   
   auto YesOnHoverUniform = std::make_unique<ShaderUniform>();
   YesOnHoverUniform->Type = UniformType::TwoFLoat;

     auto YesSpotHoverUniform = std::make_unique<ShaderUniform>();
   YesSpotHoverUniform->Type = UniformType::OneFloat;
   PopUpShadowsContainerShader->AddUniform("Start",std::move(StartUniform));
      PopUpShadowsContainerShader->AddUniform("EndTime",std::move(EndTimeUniform));
   PopUpShadowsContainerShader->AddUniform("YesHoverStart",std::move(YesStartUniform));
    PopUpShadowsContainerShader->AddUniform("YesHoverEnd",std::move(YesEndUniform));
   PopUpShadowsContainerShader->AddUniform("YesOnHover",std::move(YesOnHoverUniform));
     PopUpShadowsContainerShader->AddUniform("hoverspot",std::move(YesSpotHoverUniform));
    SunCore::instance().SunShaders.AddShaderToWorld("PopUpShadowsContainerShader",std::move(PopUpShadowsContainerShader));

    SunCore::instance().SunWorld.AddMaterialToWorld("PopUpShadowsContainerMaterial","PopUpShadowsContainerShader");
     Material* PopUpShadowsContainerMaterial = SunCore::instance().SunWorld.GetMaterial("PopUpShadowsContainerMaterial");
   PopUpShadowsContainerMaterial->AddFloatUniform("Start",0);
    PopUpShadowsContainerMaterial->AddFloatUniform("EndTime",0);
   PopUpShadowsContainerMaterial->AddFloatUniform("YesOnHover",0);
   PopUpShadowsContainerMaterial->AddFloatUniform("YesHoverStart",0);
   PopUpShadowsContainerMaterial->AddFloatUniform("YesHoverEnd",0);
   PopUpShadowsContainerMaterial->AddTwoFloatsUniform("hoverspot",0,0);

LeavePopUpContainer->SetzIndex(100);



  LeavePopUp->SetPopUpContainer(std::move(LeavePopUpContainer),ComponentType::Sprite);
  SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpContainer")->second->AddMaterial("PopUpShadowsContainerMaterial");

    LeavePopUpTextConfigs.Parent = SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpContainer")->second.get();
      LeavePopUpNoButtonConfigs.Parent = SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpContainer")->second.get();
            LeavePopUpYesButtonConfigs.Parent = SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpContainer")->second.get();
     
  LeavePopUp->AddNewChildren(std::move(LeavePopUpText),ComponentType::Text,LeavePopUpTextConfigs);
  LeavePopUp->AddNewChildren(std::move(LeavePopUpButtonNo),ComponentType::Rectangle,LeavePopUpNoButtonConfigs);
    LeavePopUp->AddNewChildren(std::move(LeavePopUpButtonYes),ComponentType::Rectangle,LeavePopUpYesButtonConfigs);

   LeavePopUpTextNoConfigs.Parent = SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpButtonNo")->second.get();
    LeavePopUp->AddNewChildren(std::move(LeavePopUpTextNo),ComponentType::Text,LeavePopUpTextNoConfigs);

       LeavePopUpTextYesConfigs.Parent = SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpButtonYes")->second.get();
    LeavePopUp->AddNewChildren(std::move(LeavePopUpTextYes),ComponentType::Text,LeavePopUpTextYesConfigs);

   SunAnimation LeavePopUpEntryAnimation;
   Animations LeavePopUpEntryAnimationX;
   LeavePopUpEntryAnimationX.EaseType = EaseTypes::EaseOut;
   LeavePopUpEntryAnimationX.Propertie = AnimationProperties::X;
   UnitClass LeavePopUpEntryAnimationXUnitClass;
   LeavePopUpEntryAnimationXUnitClass.Unit = UnitType::Percent;
   LeavePopUpEntryAnimationXUnitClass.Value = 0.5f;

   UnitClass LeavePopUpEntryAnimationXUnitClassInit;
   LeavePopUpEntryAnimationXUnitClassInit.Unit = UnitType::Percent;
   LeavePopUpEntryAnimationXUnitClassInit.Value = -0.3f;
   LeavePopUpEntryAnimationX.Target = LeavePopUpEntryAnimationXUnitClass;
   LeavePopUpEntryAnimationX.SetFixedStartValue(LeavePopUpEntryAnimationXUnitClassInit);
   LeavePopUpEntryAnimation.SetDuration(0.5);
   LeavePopUpEntryAnimation.AddInnerAnimation(LeavePopUpEntryAnimationX);

     LeavePopUp->SetEntryAnimation(LeavePopUpEntryAnimation);

     
   SunAnimation LeavePopUpLeaveAnimation;
   Animations LeavePopUpLeaveAnimationX;
   LeavePopUpLeaveAnimationX.EaseType = EaseTypes::EaseIn;
   LeavePopUpLeaveAnimationX.Propertie = AnimationProperties::X;
   UnitClass LeavePopUpLeaveAnimationXUnitClass;
   LeavePopUpLeaveAnimationXUnitClass.Unit = UnitType::Percent;
   LeavePopUpLeaveAnimationXUnitClass.Value = -0.3f;

   UnitClass LeavePopUpLeaveAnimationXUnitClassInit;
   LeavePopUpLeaveAnimationXUnitClassInit.Unit = UnitType::Percent;
   LeavePopUpLeaveAnimationXUnitClassInit.Value = 0.5f;
   LeavePopUpLeaveAnimationX.Target = LeavePopUpLeaveAnimationXUnitClass;
   LeavePopUpLeaveAnimationX.SetFixedStartValue(LeavePopUpLeaveAnimationXUnitClassInit);
   LeavePopUpLeaveAnimation.SetDuration(0.3);
   LeavePopUpLeaveAnimation.AddInnerAnimation(LeavePopUpLeaveAnimationX);

     LeavePopUp->SetLeaveAnimation(LeavePopUpLeaveAnimation);
  LeavePopUp->SetEntryChildsDelay(1.5);
  SunCore::instance().SunWorld.AddPopUpToWorld("LeavePopUp",std::move(LeavePopUp));


  LeaveButtonListener->Fn = [this,PopUpShadowsContainerMaterial](SunEvent& e){
    if(SunCore::instance().SunWorld.GetPopUp("LeavePopUp")->GetDisplay() == DisplayType::None){
  SunCore::instance().SunWorld.ShowPopUp("LeavePopUp");
    PopUpShadowsContainerMaterial->GetFloatsUniforms().find("Start")->second = SunCore::instance().SunTime.GetTime();
    }else{
       PopUpShadowsContainerMaterial->GetFloatsUniforms().find("EndTime")->second = SunCore::instance().SunTime.GetTime();
      SunCore::instance().SunWorld.DisablePopUp("LeavePopUp");

    }
       PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesOnHover")->second = 0;
  }; 
  SunCore::instance().SunBrain.NewListener(std::move(LeaveButtonListener));  



    auto LeavePopUpNoListener = std::make_unique<SunListener>();
  SunEventTrigger LeavePopUpNoListenerTrigger;
  LeavePopUpNoListenerTrigger.SetMouseTrigger(MouseTriggersType::PointerDown,MouseButtons::LMB,
  SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpButtonNo")->second.get());
  LeavePopUpNoListener->UseFn = true;
  LeavePopUpNoListener->Trigger = LeavePopUpNoListenerTrigger;
  LeavePopUpNoListener->Id = "LeavePopUpNoListener";

  
  LeavePopUpNoListener->Fn = [this,PopUpShadowsContainerMaterial](SunEvent& e){
    if(SunCore::instance().SunWorld.GetPopUp("LeavePopUp")->GetDisplay() == DisplayType::None){
  SunCore::instance().SunWorld.ShowPopUp("LeavePopUp");
    }else{
      SunCore::instance().SunWorld.DisablePopUp("LeavePopUp");
    }
  }; 


  
  SunCore::instance().SunBrain.NewListener(std::move(LeavePopUpNoListener));



    auto LeavePopUpYesListener = std::make_unique<SunListener>();
  SunEventTrigger LeavePopUpYesListenerTrigger;
  LeavePopUpYesListenerTrigger.SetMouseTrigger(MouseTriggersType::PointerDown,MouseButtons::LMB,
  SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpButtonYes")->second.get());

  LeavePopUpYesListener->UseFn = true;
  LeavePopUpYesListener->Trigger = LeavePopUpYesListenerTrigger;
  LeavePopUpYesListener->Id = "LeavePopUpYesListener";

  
  LeavePopUpYesListener->Fn = [this](SunEvent& e){
    SunQuit();
  }; 


  
  SunCore::instance().SunBrain.NewListener(std::move(LeavePopUpYesListener));




    auto LeavePopUpYesHoverListener = std::make_unique<SunListener>();
  SunEventTrigger LeavePopUpYesHoverListenerTrigger;
  LeavePopUpYesHoverListenerTrigger.SetMouseTrigger(MouseTriggersType::MouseOn,MouseButtons::LMB,
  SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpButtonYes")->second.get());

  LeavePopUpYesHoverListener->UseFn = true;
  LeavePopUpYesHoverListener->Trigger = LeavePopUpYesHoverListenerTrigger;
  LeavePopUpYesHoverListener->Id = "LeavePopUpYesHoverListener";

  
  LeavePopUpYesHoverListener->Fn = [this,PopUpShadowsContainerMaterial](SunEvent& e){
    SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpTextYes")->second->SetRGBA(1.0,1.0,1.0,1.0);
     vector2 spot;
    spot.x = 0.38;
    spot.y = 0.6;
     PopUpShadowsContainerMaterial->GetTwoFloatsUniforms().find("hoverspot")->second = spot;
   if(PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesOnHover")->second == 0){
    PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesHoverStart")->second = SunCore::instance().SunTime.GetTime();
   }
   PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesOnHover")->second = 1;

  }; 



  
  SunCore::instance().SunBrain.NewListener(std::move(LeavePopUpYesHoverListener));





  auto LeavePopUpYesHoverOutListener = std::make_unique<SunListener>();
  SunEventTrigger LeavePopUpYesHoverOutListenerTrigger;
  LeavePopUpYesHoverOutListenerTrigger.SetMouseTrigger(MouseTriggersType::MouseOut,MouseButtons::LMB,
  SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpButtonYes")->second.get());
  LeavePopUpYesHoverOutListenerTrigger.SetKeyboardTrigger(KeyboardTriggersType::KeyDown,KeyCodes::A);
  LeavePopUpYesHoverOutListener->UseFn = true;
  LeavePopUpYesHoverOutListener->Trigger = LeavePopUpYesHoverOutListenerTrigger;
  LeavePopUpYesHoverOutListener->Id = "LeavePopUpYesHoverOutListener";

  
  LeavePopUpYesHoverOutListener->Fn = [this,PopUpShadowsContainerMaterial](SunEvent& e){
    SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpTextYes")->second->SetRGBA(1.0,1.0,1.0,1.0);
    vector2 spot;
    spot.x = 0.38;
    spot.y = 0.6;
     PopUpShadowsContainerMaterial->GetTwoFloatsUniforms().find("hoverspot")->second = spot;
  if(PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesOnHover")->second == 1){
    PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesHoverEnd")->second = SunCore::instance().SunTime.GetTime();
  }
   PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesOnHover")->second = 0;

  }; 
  


  
  SunCore::instance().SunBrain.NewListener(std::move(LeavePopUpYesHoverOutListener));




    auto LeavePopUpNoHoverListener = std::make_unique<SunListener>();
  SunEventTrigger LeavePopUpNoHoverListenerTrigger;
  LeavePopUpNoHoverListenerTrigger.SetMouseTrigger(MouseTriggersType::MouseOn,MouseButtons::LMB,
  SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpButtonNo")->second.get());
  LeavePopUpNoHoverListenerTrigger.SetKeyboardTrigger(KeyboardTriggersType::KeyDown,KeyCodes::A);
  LeavePopUpNoHoverListener->UseFn = true;
  LeavePopUpNoHoverListener->Trigger = LeavePopUpNoHoverListenerTrigger;
  LeavePopUpNoHoverListener->Id = "LeavePopUpNoHoverListener";

  
  LeavePopUpNoHoverListener->Fn = [this,PopUpShadowsContainerMaterial](SunEvent& e){
    SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpTextNo")->second->SetRGBA(1.0,1.0,1.0,1.0);
   vector2 spot;
    spot.x = 0.68;
    spot.y = 0.6;
     PopUpShadowsContainerMaterial->GetTwoFloatsUniforms().find("hoverspot")->second = spot;
   if(PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesOnHover")->second == 0){
    PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesHoverStart")->second = SunCore::instance().SunTime.GetTime();
    PopUpShadowsContainerMaterial->GetFloatsUniforms().find("EndTime")->second = SunCore::instance().SunTime.GetTime();
   }
   PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesOnHover")->second = 1;

  }; 



  
  SunCore::instance().SunBrain.NewListener(std::move(LeavePopUpNoHoverListener));



  auto LeavePopUpNoHoverOutListener = std::make_unique<SunListener>();
  SunEventTrigger LeavePopUpNoHoverOutListenerTrigger;
  LeavePopUpNoHoverOutListenerTrigger.SetMouseTrigger(MouseTriggersType::MouseOut,MouseButtons::LMB,
  SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpButtonNo")->second.get());
  LeavePopUpNoHoverOutListenerTrigger.SetKeyboardTrigger(KeyboardTriggersType::KeyDown,KeyCodes::A);
  LeavePopUpNoHoverOutListener->UseFn = true;
  LeavePopUpNoHoverOutListener->Trigger = LeavePopUpNoHoverOutListenerTrigger;
  LeavePopUpNoHoverOutListener->Id = "LeavePopUpNoHoverOutListener";

  
  LeavePopUpNoHoverOutListener->Fn = [this,PopUpShadowsContainerMaterial](SunEvent& e){
    SunCore::instance().SunWorld.GetWorldComponentsMap().find("LeavePopUpTextNo")->second->SetRGBA(1.0,1.0,1.0,1.0);
    vector2 spot;
    spot.x = 0.68;
    spot.y = 0.6;
     PopUpShadowsContainerMaterial->GetTwoFloatsUniforms().find("hoverspot")->second = spot;
  if(PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesOnHover")->second == 1){
    PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesHoverEnd")->second = SunCore::instance().SunTime.GetTime();
  }
   PopUpShadowsContainerMaterial->GetFloatsUniforms().find("YesOnHover")->second = 0;

  }; 
  


  
  SunCore::instance().SunBrain.NewListener(std::move(LeavePopUpNoHoverOutListener));

  
  

  auto PlayButtonListener = std::make_unique<SunListener>();
  SunEventTrigger PlayButtonListenerTrigger;
  PlayButtonListenerTrigger.SetMouseTrigger(MouseTriggersType::PointerDown,MouseButtons::LMB,
  SunCore::instance().SunWorld.GetWorldComponentsMap().find("PlayButton")->second.get());
  PlayButtonListener->UseFn = true;
  PlayButtonListener->Trigger = PlayButtonListenerTrigger;
  PlayButtonListener->Id = "PlayButtonListener";

  
 PlayButtonListener->Fn = [this](SunEvent& e){
   RunScene("GameStartScene");
 StopThisScene();


   
  }; 


  
  SunCore::instance().SunBrain.NewListener(std::move(PlayButtonListener));





 




         
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
     
    // std::cout << "\n"<<SunCore::instance().SunWorld.GetWorldComponentsMap().find("PlayText")->second->GetRenderComponent()->X << "  ,  " << SunCore::instance().SunWorld.GetWorldComponentsMap().find("PlayText")->second->GetRenderComponent()->Y << " \n"  ;
    };
    
       

};


class GameStartScene : public Scene{
   std::string SceneID = "GameStartScene"; 
    void SceneConfigs() override{
     
    };
    void OnLoad() override{
   SunTextures.NewTexture("FirstGrassTileTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstGrassTile.png");
    SunTextures.NewTexture("FirstGrassTileMask","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstGrassTileMask.png");
      SunTextures.NewTexture("FirstGroundTileTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstGroundTile.png");
      SunTextures.NewTexture("SecondGroundTileTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/SecondGroundTile.png");
         SunTextures.NewTexture("FirstGrassTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstGrass.png");
              SunTextures.NewTexture("FirstGrassMask","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstGrassMask.png");
      SunTextures.NewTexture("FallAltarTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FallAltar.png");
      SunTextures.NewTexture("FirstGroundWallTileTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstGroundWallTile.png");

         SunTextures.NewTexture("FirstWallTileTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstWallTile.png");
        SunTextures.NewTexture("SecondWallTileTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/SecondWallTile.png");  
         SunTextures.NewTexture("ThirdWallTileTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/ThirdWallTile.png");
           SunTextures.NewTexture("FourWallTileTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FourWallTile.png");
            
             SunTextures.NewTexture("FirstWallsDecorationTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstWallsDecoration.png");
                SunTextures.NewTexture("SecondGrassTileTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/SecondGrassTile.png");
                   SunTextures.NewTexture("ThirdGrassTileTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/ThirdGrassTile.png");
                           SunTextures.NewTexture("SecondGrassTileMask","./Assets/Maps/Pradarias Do Limiar/Tiles/SecondGrassTileMask.png");
                   SunTextures.NewTexture("ThirdGrassTileMask","./Assets/Maps/Pradarias Do Limiar/Tiles/ThirdGrassTileMask.png");

                           SunTextures.NewTexture("FirstGreatGrassTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstGreatGrass.png");
                     SunTextures.NewTexture("FirstGreatGrassMask","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstGreatGrassMask.png");
            SunTextures.NewTexture("FirstShadowTileTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstShadowTile.png");  
            
            SunTextures.NewTexture("FirstMountainTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstMountain.png"); 
            SunTextures.NewTexture("SecondMountainTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/SecondMountain.png"); 
            SunTextures.NewTexture("ThirdMountainTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/ThirdMountain.png"); 

             SunTextures.NewTexture("FirstMountainMask","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstMountainMask.png"); 
         
       

                SunTextures.NewTexture("WhiteBlockTileTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/WhiteBlockTile.png");
                                SunTextures.NewTexture("FirstSkyTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstSky.png");

                      SunTextures.NewTexture("SecondColinTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/SecondColin.png");
                        SunTextures.NewTexture("FirstColinTexture","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstColin.png");
        SunTextures.NewTexture("SecondColinMask","./Assets/Maps/Pradarias Do Limiar/Tiles/SecondColinMask.png");
                        SunTextures.NewTexture("FirstColinMask","./Assets/Maps/Pradarias Do Limiar/Tiles/FirstColinMask.png");
                        SunTextures.NewTexture("AvoiedDioTexture1","./Assets/Characters/Dio/AvoiedDio0000.png");
                         SunTextures.NewTexture("AvoiedDioTexture2","./Assets/Characters/Dio/AvoiedDio0001.png");
                           SunTextures.NewTexture("AvoiedDioWindMask1","./Assets/Characters/Dio/AvoiedDio0000WindTexture.png");
                            SunTextures.NewTexture("AvoiedDioWindMask1Bands","./Assets/Characters/Dio/AvoiedDio0000WindTextureBands.png");
                             SunTextures.NewTexture("AvoiedDioWindMask1NamelessSword","./Assets/Characters/Dio/AvoiedDioNamelessSwordMask0000.png");
           SunTextures.NewTexture("AvoiedDioWindMask2NamelessSword","./Assets/Characters/Dio/AvoiedDioNamelessSwordMask0001.png");
           SunTextures.NewTexture("AvoiedDioWindMask3NamelessSword","./Assets/Characters/Dio/AvoiedDioNamelessSwordMask0002.png");
                         
              SunTextures.NewTexture("AvoiedDioHairTexture1","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Hair0000.png"); 
              SunTextures.NewTexture("AvoiedDioHairTexture2","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Hair0001.png");
                 SunTextures.NewTexture("AvoiedDioHairTexture3","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Hair0002.png");
              SunTextures.NewTexture("AvoiedDioHeadTexture1","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Head0000.png"); 
              SunTextures.NewTexture("AvoiedDioHeadTexture2","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Head0001.png");  
              SunTextures.NewTexture("AvoiedDioHeadTexture3","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Head0002.png");  
              SunTextures.NewTexture("AvoiedDioBootsTexture1","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Boots0000.png"); 
              SunTextures.NewTexture("AvoiedDioBootsTexture2","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Boots0001.png");
               SunTextures.NewTexture("AvoiedDioBootsTexture3","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Boots0002.png");         
              SunTextures.NewTexture("AvoiedDioPantsBandsTexture1","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - PantsBands0000.png"); 
              SunTextures.NewTexture("AvoiedDioPantsBandsTexture2","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - PantsBands0001.png");
              SunTextures.NewTexture("AvoiedDioPantsBandsTexture3","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - PantsBands0002.png");    
              SunTextures.NewTexture("AvoiedDioPantsTexture1","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Pants0000.png"); 
              SunTextures.NewTexture("AvoiedDioPantsTexture2","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Pants0001.png"); 
               SunTextures.NewTexture("AvoiedDioPantsTexture3","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Pants0002.png");     
              SunTextures.NewTexture("AvoiedDioNamelessSwordTexture1","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Nameless Sword0000.png"); 
              SunTextures.NewTexture("AvoiedDioNamelessSwordTexture2","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Nameless Sword0001.png");  
              SunTextures.NewTexture("AvoiedDioNamelessSwordTexture3","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Nameless Sword0002.png"); 
              SunTextures.NewTexture("AvoiedDioBodyTexture1","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Body0000.png"); 
              SunTextures.NewTexture("AvoiedDioBodyTexture2","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Body0001.png"); 
               SunTextures.NewTexture("AvoiedDioBodyTexture3","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - Body0002.png"); 
              SunTextures.NewTexture("AvoiedDioBodyFrontTexture1","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - FrontBody0000.png"); 
              SunTextures.NewTexture("AvoiedDioBodyFrontTexture2","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - FrontBody0001.png");
              SunTextures.NewTexture("AvoiedDioBodyFrontTexture3","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - FrontBody0002.png");  
              SunTextures.NewTexture("AvoiedDioTShirtTexture1","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - TShirt0000.png"); 
              SunTextures.NewTexture("AvoiedDioTShirtTexture2","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - TShirt0001.png"); 
                 SunTextures.NewTexture("AvoiedDioTShirtTexture3","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - TShirt0002.png"); 
              SunTextures.NewTexture("AvoiedDioFallMarkTexture1","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - FallMark0000.png"); 
              SunTextures.NewTexture("AvoiedDioFallMarkTexture2","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - FallMark0001.png"); 
     SunTextures.NewTexture("AvoiedDioFallMarkTexture3","./Assets/Characters/Dio/AvoiedDio/AvoiedDio - FallMark0002.png"); 
   
   
                                        }
    void OnInit() override{
        SunCore::instance().Camera.SetCamPosition(0.0,SunCore::instance().WindowHeight);  
   SunRender SunRendering;
  auto& St = SunCore::instance().SunTiledCore;



  auto WorldLayer = std::make_unique<CollisionLayer>();
             WorldLayer->Id = "WorldLayer";
             
               auto DioHurtLayer = std::make_unique<CollisionLayer>();
             DioHurtLayer->Id = "DioHurtLayer";
                WorldLayer->AddCollision(DioHurtLayer.get());
            DioHurtLayer->AddCollision(WorldLayer.get());
             SunCore::instance().SunWorld.CollisionsWorld.AddNewCollissionLayer(std::move(WorldLayer));
              SunCore::instance().SunWorld.CollisionsWorld.AddNewCollissionLayer(std::move(DioHurtLayer));










        const char* WindVertexShader = R"(
        #version 330 core

                layout (location = 0) in vec3 aPos;
                layout (location = 1) in vec2 aUV;

                out vec2 vUV;

                uniform vec2 uSunPos;     
                uniform vec2 uSunSize;
                uniform mat4 uSunProjection;
                    
                    
                void main(){
              
              gl_Position = uSunProjection * vec4(aPos.xy, 0.0, 1.0);
              vUV = aUV;
               
                }
        
        )";


     const char* WindFragmentShader = R"(
      #version 330 core

      in vec2 vUV;


   
      uniform sampler2D uSunTexture;
      uniform sampler2D uSunTextureMask;
      uniform float uSunTime;
      out vec4 FragColor;
      uniform float uWindYFactor;
      uniform float uWindXFactor;
      uniform float uWindIntensity;
      uniform float uWindDirection;
      uniform float uWindForce;
      uniform float uWindSize;
      uniform float uWindPulseFactor;
      uniform float uWindThreeshold;

      float hash(vec2 p){
          return fract(sin(dot(p, vec2(127.1,311.7))) * 43758.5453);
      };

      float noise(vec2 p){
        vec2 i = floor(p);
        vec2 f = fract(p);

        float a = hash(i);
        float b = hash(i + vec2(1.0,0.0));
        float c = hash(i + vec2(0.0,1.0));
        float d = hash(i + vec2(1.0,1.0));

        vec2 u = f * f * (3.0 - 2.0 * f);

        return mix(a,b,u.x) +
        (c - a) * u.y * (1.0 -u.x) +
        (d- b) * u.x * u.y;
      };

      float fbm(vec2 p)
{
    float value = 0.0;
    float amplitude = 0.5;
    float frequency = 1.0;

    for(int i = 0; i < 5; i++)
    {
        value += amplitude * noise(p * frequency);
        frequency *= 2.0;
        amplitude *= 0.5;
    }

    return value;
}

      void main(){
       vec2 uv = vUV;
       vec4 mask = texture(uSunTextureMask,uv);
       float wind_noise = fbm(vUV * uWindSize + ((uSunTime * 0.1) * uWindIntensity )) * uWindForce;
          float wind_noiseY = fbm(vUV * (uWindSize + vec2(15.0,0.0)) + ((uSunTime * 0.1) * uWindIntensity )) * uWindForce;
      float influence = mask.r;

     float wind_pulse = fbm(uv * uWindSize + ((uSunTime * 0.9) * uWindIntensity));
     wind_pulse = smoothstep(uWindThreeshold,1.0,wind_pulse);
      
       uv.y += ((wind_noiseY * influence) * uWindYFactor) * (wind_pulse * uWindPulseFactor + 0.01);
        uv.x += ((wind_noise * influence) * uWindXFactor) * (wind_pulse * uWindPulseFactor + 0.01);
       
      uv.y = clamp(uv.y, 0.0, 1.0);
          vec4 tex = texture(uSunTexture,uv);

        
          FragColor = tex;
      }
          
          )";





          GLuint WindShaderProgram = CreateFullShaderProgram(WindVertexShader,WindFragmentShader);

      auto WindShader = std::make_unique<SunShader>();
      WindShader->SetShaderProgram(WindShaderProgram);

      auto uWindIntensity = std::make_unique<ShaderUniform>();
      uWindIntensity->Type = UniformType::OneFloat;

            auto uWindXFactor = std::make_unique<ShaderUniform>();
      uWindXFactor->Type = UniformType::OneFloat;

            auto uWindYFactor = std::make_unique<ShaderUniform>();
      uWindYFactor->Type = UniformType::OneFloat;

         auto uWindSize = std::make_unique<ShaderUniform>();
      uWindSize->Type = UniformType::OneFloat;

               auto uWindForce = std::make_unique<ShaderUniform>();
      uWindForce->Type = UniformType::OneFloat;

        auto uWindPulseFactor = std::make_unique<ShaderUniform>();
      uWindPulseFactor->Type = UniformType::OneFloat;

         auto uWindThreeshold = std::make_unique<ShaderUniform>();
      uWindThreeshold->Type = UniformType::OneFloat;


      auto uWindDirection = std::make_unique<ShaderUniform>();
      uWindDirection->Type = UniformType::OneFloat;

      WindShader->AddUniform("uWindDirection",std::move(uWindDirection));
      WindShader->AddUniform("uWindIntensity",std::move(uWindIntensity));
            WindShader->AddUniform("uWindSize",std::move(uWindSize));
             WindShader->AddUniform("uWindForce",std::move(uWindForce));
                WindShader->AddUniform("uWindXFactor",std::move(uWindXFactor));
                    WindShader->AddUniform("uWindYFactor",std::move(uWindYFactor));
           WindShader->AddUniform("uWindPulseFactor",std::move(uWindPulseFactor));
            WindShader->AddUniform("uWindThreeshold",std::move(uWindThreeshold));

       SunCore::instance().SunShaders.AddShaderToWorld("WindShader",std::move(WindShader));
       SunCore::instance().SunWorld.AddMaterialToWorld("WindMaterial","WindShader");
       auto WindMaterial = SunCore::instance().SunWorld.GetMaterial("WindMaterial");
       WindMaterial->AddFloatUniform("uWindDirection",1);
       WindMaterial->AddFloatUniform("uWindIntensity",1);
        WindMaterial->AddFloatUniform("uWindSize",2.0);
           WindMaterial->AddFloatUniform("uWindForce",0.1);
                 WindMaterial->AddFloatUniform("uWindYFactor",1.0);
                 WindMaterial->AddFloatUniform("uWindXFactor",1.0);
              WindMaterial->AddFloatUniform("uWindPulseFactor",0.4);
                WindMaterial->AddFloatUniform("uWindThreeshold",0.4);
        
         MaterialUniforms StrongWindGrass;
       StrongWindGrass.AddFloatUniform("uWindIntensity",2.5);

          MaterialUniforms DistantWeakWindGrass;
        DistantWeakWindGrass.AddFloatUniform("uWindIntensity",1.0);
          DistantWeakWindGrass.AddFloatUniform("uWindSize",10.0);

             MaterialUniforms DistantGreatWeakWindGrass;
       DistantGreatWeakWindGrass.AddFloatUniform("uWindIntensity",0.6);
         DistantGreatWeakWindGrass.AddFloatUniform("uWindSize",5.0);
         DistantGreatWeakWindGrass.AddFloatUniform("uWindXFactor",0.0);
       
          MaterialUniforms MediumWindGrass;
       MediumWindGrass.AddFloatUniform("uWindIntensity",1.5);
         MediumWindGrass.AddFloatUniform("uWindSize",10);
       
          MaterialUniforms DioWindUniforms;
       DioWindUniforms.AddFloatUniform("uWindIntensity",3);
         DioWindUniforms.AddFloatUniform("uWindSize",0.2);
          DioWindUniforms.AddFloatUniform("uWindForce",0.02);
               DioWindUniforms.AddFloatUniform("uWindXFactor",5.0);

                     MaterialUniforms DioHairWindUniforms;
       DioHairWindUniforms.AddFloatUniform("uWindIntensity",0.6);
         DioHairWindUniforms.AddFloatUniform("uWindSize",20.0);
          DioHairWindUniforms.AddFloatUniform("uWindForce",0.1);
                    DioHairWindUniforms.AddFloatUniform("uWindYFactor",-1.0);
               DioHairWindUniforms.AddFloatUniform("uWindXFactor",-1.0);
                DioHairWindUniforms.AddFloatUniform("uWindPulseFactor",1.0);

                        MaterialUniforms DioTShirtWindUniforms;
        DioTShirtWindUniforms.AddFloatUniform("uWindIntensity",0.5);
        DioTShirtWindUniforms.AddFloatUniform("uWindSize",5.0);
         DioTShirtWindUniforms.AddFloatUniform("uWindForce",0.08);
                   DioTShirtWindUniforms.AddFloatUniform("uWindYFactor",1.0);
              DioTShirtWindUniforms.AddFloatUniform("uWindXFactor",1.0);
              DioTShirtWindUniforms.AddFloatUniform("uWindPulseFactor",1.0);

                       MaterialUniforms DioPantsWindUniforms;
        DioPantsWindUniforms.AddFloatUniform("uWindIntensity",0.5);
       DioPantsWindUniforms.AddFloatUniform("uWindSize",5.0);
        DioPantsWindUniforms.AddFloatUniform("uWindForce",0.07);
                   DioPantsWindUniforms.AddFloatUniform("uWindYFactor",1.0);
             DioPantsWindUniforms.AddFloatUniform("uWindXFactor",0.5);
              DioPantsWindUniforms.AddFloatUniform("uWindPulseFactor",1.0);

               MaterialUniforms DioNamelessSwordWindUniforms;
         DioNamelessSwordWindUniforms.AddFloatUniform("uWindIntensity",0.7);
       DioNamelessSwordWindUniforms.AddFloatUniform("uWindSize",5.0);
      DioNamelessSwordWindUniforms.AddFloatUniform("uWindForce",0.2);
                   DioNamelessSwordWindUniforms.AddFloatUniform("uWindYFactor",1.0);
              DioNamelessSwordWindUniforms.AddFloatUniform("uWindXFactor",1.0);
              DioNamelessSwordWindUniforms.AddFloatUniform("uWindPulseFactor",2.0);
    DioNamelessSwordWindUniforms.AddFloatUniform("uWindThreeshold",0.3);

                MaterialUniforms DioBandsWindUniforms;
        DioBandsWindUniforms.AddFloatUniform("uWindIntensity",0.7);
      DioBandsWindUniforms.AddFloatUniform("uWindSize",10.0);
      DioBandsWindUniforms.AddFloatUniform("uWindForce",0.1);
                   DioBandsWindUniforms.AddFloatUniform("uWindYFactor",0.5);
            DioBandsWindUniforms.AddFloatUniform("uWindXFactor",1.0);
              DioBandsWindUniforms.AddFloatUniform("uWindPulseFactor",1.0);
                 DioBandsWindUniforms.AddFloatUniform("uWindThreeshold",0.0);






        const char* SkyVertexShader = R"(
        #version 330 core

                layout (location = 0) in vec3 aPos;
                layout (location = 1) in vec2 aUV;

                out vec2 vUV;

                uniform vec2 uSunPos;     
                uniform vec2 uSunSize;
                uniform mat4 uSunProjection;
                    
                    
                void main(){
              
              gl_Position = uSunProjection * vec4(aPos.xy, 0.0, 1.0);
              vUV = aUV;
               
                }
        
        )";


     const char* SkyFragmentShader = R"(
      #version 330 core

      in vec2 vUV;


   
      uniform sampler2D uSunTexture;
      uniform float uSunTime;
      out vec4 FragColor;


      float hash(vec2 p){
          return fract(sin(dot(p, vec2(127.1,311.7))) * 43758.5453);
      };

      float noise(vec2 p){
        vec2 i = floor(p);
        vec2 f = fract(p);

        float a = hash(i);
        float b = hash(i + vec2(1.0,0.0));
        float c = hash(i + vec2(0.0,1.0));
        float d = hash(i + vec2(1.0,1.0));

        vec2 u = f * f * (3.0 - 2.0 * f);

        return mix(a,b,u.x) +
        (c - a) * u.y * (1.0 -u.x) +
        (d- b) * u.x * u.y;
      };

      float fbm(vec2 p)
{
    float value = 0.0;
    float amplitude = 0.5;
    float frequency = 1.0;

    for(int i = 0; i < 5; i++)
    {
        value += amplitude * noise(p * frequency);
        frequency *= 2.0;
        amplitude *= 0.5;
    }

    return value;
}

      void main(){
       vec2 uv = vUV;
       float wind_noise = fbm(uv * 30.0 + ((uSunTime * 0.1)));
       //uv.x -= wind_noise;
       
       
          vec4 tex = texture(uSunTexture,uv);
          tex.a -= wind_noise;
          if(tex.a < 0.2){
          discard;
          } 
        
          FragColor = tex;
      }
          
          )";





          GLuint SkyShaderProgram = CreateFullShaderProgram(SkyVertexShader,SkyFragmentShader);

      auto SkyShader = std::make_unique<SunShader>();
      SkyShader->SetShaderProgram(SkyShaderProgram);


       SunCore::instance().SunShaders.AddShaderToWorld("SkyShader",std::move(SkyShader));
       SunCore::instance().SunWorld.AddMaterialToWorld("SkyMaterial","SkyShader");
       auto SkyMaterial = SunCore::instance().SunWorld.GetMaterial("SkyMaterial");

        
      

        const char* FallMarkVertexShader = R"(
        #version 330 core

                layout (location = 0) in vec3 aPos;
                layout (location = 1) in vec2 aUV;

                out vec2 vUV;

                uniform vec2 uSunPos;     
                uniform vec2 uSunSize;
                uniform mat4 uSunProjection;
                    
                    
                void main(){
              
              gl_Position = uSunProjection * vec4(aPos.xy, 0.0, 1.0);
              vUV = aUV;
               
                }
        
        )";


     const char*  FallMarkFragmentShader = R"(
      #version 330 core

      in vec2 vUV;


   
      uniform sampler2D uSunTexture;
      uniform float uSunTime;
      out vec4 FragColor;


      float hash(vec2 p){
          return fract(sin(dot(p, vec2(127.1,311.7))) * 43758.5453);
      };

      float noise(vec2 p){
        vec2 i = floor(p);
        vec2 f = fract(p);

        float a = hash(i);
        float b = hash(i + vec2(1.0,0.0));
        float c = hash(i + vec2(0.0,1.0));
        float d = hash(i + vec2(1.0,1.0));

        vec2 u = f * f * (3.0 - 2.0 * f);

        return mix(a,b,u.x) +
        (c - a) * u.y * (1.0 -u.x) +
        (d- b) * u.x * u.y;
      };

      float fbm(vec2 p)
{
    float value = 0.0;
    float amplitude = 0.5;
    float frequency = 1.0;

    for(int i = 0; i < 5; i++)
    {
        value += amplitude * noise(p * frequency);
        frequency *= 2.0;
        amplitude *= 0.5;
    }

    return value;
}

      void main(){
       vec2 uv = vUV;
          vec4 tex = texture(uSunTexture,uv);
          FragColor = tex;
      }
          
          )";





          GLuint  FallMarkShaderProgram = CreateFullShaderProgram(FallMarkVertexShader,FallMarkFragmentShader);

      auto  FallMarkShader = std::make_unique<SunShader>();
       FallMarkShader->SetShaderProgram(FallMarkShaderProgram);
      

       SunCore::instance().SunShaders.AddShaderToWorld("FallMarkShader",std::move( FallMarkShader));
       SunCore::instance().SunWorld.AddMaterialToWorld("FallMarkMaterial","FallMarkShader");
       auto FallMarkMaterial = SunCore::instance().SunWorld.GetMaterial("FallMarkMaterial");

        
      


              

          


              

          




  St.AddTiledMap("PradariasDoLimiar","./Assets/Maps/Pradarias Do Limiar/PradariasDoLimiar.json");

  auto* PradariasDoLimiar = St.GetTiledMap("PradariasDoLimiar");
  auto FirstGrassTileClass = std::make_unique<Tile>();
  FirstGrassTileClass->SetTexture("FirstGrassTileTexture");
  FirstGrassTileClass->SetMaterial("WindMaterial");
    FirstGrassTileClass->SetTextureMask("FirstGrassTileMask");
    FirstGrassTileClass->SetMaterialUniforms(MediumWindGrass);

   auto SecondGrassTileClass = std::make_unique<Tile>();
  SecondGrassTileClass->SetTexture("SecondGrassTileTexture");
   SecondGrassTileClass->SetMaterial("WindMaterial");
   SecondGrassTileClass->SetTextureMask("SecondGrassTileMask");
   auto ThirdGrassTileClass = std::make_unique<Tile>();
  ThirdGrassTileClass->SetTexture("ThirdGrassTileTexture");
   ThirdGrassTileClass->SetMaterial("WindMaterial");
     ThirdGrassTileClass->SetTextureMask("ThirdGrassTileMask");

   auto FirstSkyClass = std::make_unique<Tile>();
  FirstSkyClass->SetTexture("FirstSkyTexture");
    FirstSkyClass->SetMaterial("SkyMaterial");

   
    auto FirstShadowTileClass = std::make_unique<Tile>();
  FirstShadowTileClass->SetTexture("FirstShadowTileTexture");

    auto FirstGroundTileClass = std::make_unique<Tile>();
  FirstGroundTileClass->SetTexture("FirstGroundTileTexture");

   auto WhiteBlockTileClass = std::make_unique<Tile>();
  WhiteBlockTileClass->SetTexture("WhiteBlockTileTexture");

      auto SecondGroundTileClass = std::make_unique<Tile>();
  SecondGroundTileClass->SetTexture("SecondGroundTileTexture");

  auto FirstGrassClass = std::make_unique<Tile>();
  FirstGrassClass->SetTexture("FirstGrassTexture");
  FirstGrassClass->SetMaterial("WindMaterial");
  FirstGrassClass->SetTextureMask("FirstGrassMask");

  FirstGrassClass->TileWidth = 200;
  FirstGrassClass->TileHeight = 200;
  
  auto FirstGreatGrassClass = std::make_unique<Tile>();
  FirstGreatGrassClass->SetTexture("FirstGreatGrassTexture");
  FirstGreatGrassClass->SetMaterial("WindMaterial");
    FirstGreatGrassClass->SetTextureMask("FirstGreatGrassMask");
    FirstGreatGrassClass->SetMaterialUniforms(StrongWindGrass);
 
//
  auto FallAltarClass = std::make_unique<Tile>();
  FallAltarClass->SetTexture("FallAltarTexture");
  FallAltarClass->TileWidth = 88;
  FallAltarClass->TileHeight = 86;

  
  auto FirstGroundWallClass = std::make_unique<Tile>();
  FirstGroundWallClass->SetTexture("FirstGroundWallTileTexture");

  auto FirstWallTileClass = std::make_unique<Tile>();
  FirstWallTileClass->SetTexture("FirstWallTileTexture");

  
  auto SecondWallTileClass = std::make_unique<Tile>();
  SecondWallTileClass->SetTexture("SecondWallTileTexture");

  
  auto ThirdWallTileClass = std::make_unique<Tile>();
  ThirdWallTileClass->SetTexture("ThirdWallTileTexture");

  
  auto ThirdWallTileNoBodyClass = std::make_unique<Tile>();
  ThirdWallTileNoBodyClass->SetTexture("ThirdWallTileTexture");

  
  auto FourWallTileClass = std::make_unique<Tile>();
  FourWallTileClass->SetTexture("FourWallTileTexture");
  
   auto FirstMountainClass = std::make_unique<Tile>();
  FirstMountainClass->SetTexture("FirstMountainTexture");
    FirstMountainClass->SetTextureMask("FirstMountainMask");
     FirstMountainClass->SetMaterial("WindMaterial");
     FirstMountainClass->SetMaterialUniforms(DistantGreatWeakWindGrass);

  
      auto ThirdMountainClass = std::make_unique<Tile>();
  ThirdMountainClass->SetTexture("ThirdMountainTexture");
     //ThirdMountainClass->SetMaterial("GrassMaterial");
  
  
  
  
 auto FirstWallsDecorationClass = std::make_unique<Tile>();
  FirstWallsDecorationClass->SetTexture("FirstWallsDecorationTexture");
    FirstWallsDecorationClass->TileWidth = 200;
  FirstWallsDecorationClass->TileHeight = 200;

   auto FirstColinClass = std::make_unique<Tile>();
  FirstColinClass->SetTexture("FirstColinTexture");
  FirstColinClass->SetTextureMask("FirstColinMask");
  FirstColinClass->SetMaterial("WindMaterial");
  FirstColinClass->SetMaterialUniforms(DistantWeakWindGrass);

  
   auto SecondColinClass = std::make_unique<Tile>();
  SecondColinClass->SetTexture("SecondColinTexture");
   SecondColinClass->SetMaterial("WindMaterial");
   SecondColinClass->SetTextureMask("SecondColinMask");
      SecondColinClass->SetMaterialUniforms(DistantWeakWindGrass);

 
 


  PradariasDoLimiar->AddTile("FirstGrassTile",std::move(FirstGrassTileClass));
    PradariasDoLimiar->AddTile("FirstShadowTile",std::move(FirstShadowTileClass));
    PradariasDoLimiar->AddTile("SecondGrassTile",std::move(SecondGrassTileClass));
      PradariasDoLimiar->AddTile("ThirdGrassTile",std::move(ThirdGrassTileClass));
    PradariasDoLimiar->AddTile("FirstGroundTile",std::move(FirstGroundTileClass));
        PradariasDoLimiar->AddTile("SecondGroundTile",std::move(SecondGroundTileClass));
         PradariasDoLimiar->AddTile("FirstGrass",std::move(FirstGrassClass));
               PradariasDoLimiar->AddTile("FirstGreatGrass",std::move(FirstGreatGrassClass));

          PradariasDoLimiar->AddTile("FirstWallTile",std::move(FirstWallTileClass));
            PradariasDoLimiar->AddTile("SecondWallTile",std::move(SecondWallTileClass));
              PradariasDoLimiar->AddTile("ThirdWallTile",std::move(ThirdWallTileClass));
               PradariasDoLimiar->AddTile("ThirdWallTileNoBody",std::move(ThirdWallTileNoBodyClass));
                PradariasDoLimiar->AddTile("FourWallTile",std::move(FourWallTileClass));

                PradariasDoLimiar->AddTile("FirstGroundWallTile",std::move(FirstGroundWallClass));
                      PradariasDoLimiar->AddTile("FallAltar",std::move(FallAltarClass));
 PradariasDoLimiar->AddTile("FirstWallsDecoration",std::move(FirstWallsDecorationClass));
   PradariasDoLimiar->AddTile("WhiteBlockTile",std::move(WhiteBlockTileClass));
     PradariasDoLimiar->AddTile("FirstMountain",std::move(FirstMountainClass));
          PradariasDoLimiar->AddTile("ThirdMountain",std::move(ThirdMountainClass));

                PradariasDoLimiar->AddTile("FirstSky",std::move(FirstSkyClass));

          PradariasDoLimiar->AddTile("FirstColin",std::move(FirstColinClass));
              PradariasDoLimiar->AddTile("SecondColin",std::move(SecondColinClass));
          
    auto BaseSkyLayer = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("BaseSky",std::move(BaseSkyLayer));
    
    St.AddLayerToWorld("PradariasDoLimiar","BaseSky",this);

        auto SkyLayer = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("Sky",std::move(SkyLayer));
    
    St.AddLayerToWorld("PradariasDoLimiar","Sky",this);
 

        auto ColinsLayer = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("Sky",std::move(ColinsLayer));
    
    St.AddLayerToWorld("PradariasDoLimiar","Colins",this);
 

    auto FirstMountainsLayer = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("FirstMountains",std::move(FirstMountainsLayer));
    
    St.AddLayerToWorld("PradariasDoLimiar","FirstMountains",this);

 auto BackWallsLayer = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("BackWalls",std::move(BackWallsLayer));
    
    St.AddLayerToWorld("PradariasDoLimiar","BackWalls",this);

    
    auto BackWallsLayer2 = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("BackWalls2",std::move(BackWallsLayer2));
    
    St.AddLayerToWorld("PradariasDoLimiar","BackWalls2",this);

    
 
    
    auto BackWallsDecorationObjectsLayer0 = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("BackWallsDecorationObjects0",std::move(BackWallsDecorationObjectsLayer0));
    
    St.AddLayerToWorld("PradariasDoLimiar","BackWallsDecorationObjects0",this);


    auto BackWallsDecorationObjectsLayer2 = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("BackWallsDecorationObjects2",std::move(BackWallsDecorationObjectsLayer2));
    
    St.AddLayerToWorld("PradariasDoLimiar","BackWallsDecorationObjects2",this);

    
    auto BackWallsShadowsLayer = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("BackWallsShadows",std::move(BackWallsShadowsLayer));
    
    St.AddLayerToWorld("PradariasDoLimiar","BackWallsShadows",this);




 
    auto BackWallsDecorationObjectsLayer = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("BackWallsDecorationObjects",std::move(BackWallsDecorationObjectsLayer));
    
    St.AddLayerToWorld("PradariasDoLimiar","BackWallsDecorationObjects",this);


  auto GroundLayer = std::make_unique<TileLayer>(); 
  PradariasDoLimiar->AddLayer("Ground",std::move(GroundLayer));
  

  St.AddLayerToWorld("PradariasDoLimiar","Ground",this);

  
     auto WallsLayer = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("Walls",std::move(WallsLayer));
    
    St.AddLayerToWorld("PradariasDoLimiar","Walls",this);

    
    auto WallsShadowsLayer = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("WallsShadows",std::move(WallsShadowsLayer));
    
    St.AddLayerToWorld("PradariasDoLimiar","WallsShadows",this);

    auto GrassDecorationLayer = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("GrassDecoration",std::move(GrassDecorationLayer));
    
    St.AddLayerToWorld("PradariasDoLimiar","GrassDecoration",this);

      auto FrontDecorationsLayer = std::make_unique<TileLayer>(); 
    PradariasDoLimiar->AddLayer("FrontDecorations",std::move(FrontDecorationsLayer));
    
    St.AddLayerToWorld("PradariasDoLimiar","FrontDecorations",this);



    
    















 

     

     UnitClass PlayerW;
     PlayerW.Unit = UnitType::Pixel;
     PlayerW.Value = 128.0f;
     UnitClass PlayerH;
     PlayerH.Unit = UnitType::Pixel;
     PlayerH.Value = 128.0f;
     UnitClass PlayerX;
     PlayerX.Unit = UnitType::Pixel;
     PlayerX.Value = 0.0f;
     UnitClass PlayerY;
     PlayerY.Unit = UnitType::Pixel;
     PlayerY.Value = 0.0f;
     OriginClass PlayerOriginX;
     PlayerOriginX = OriginClass::Start;
     OriginClass PlayerOriginY;
     PlayerOriginY = OriginClass::Start;
     std::unique_ptr<Component> DioComponentUnique = 
    std::make_unique<Component>("DioComponent", PlayerW, PlayerH, PlayerX, PlayerY,PlayerOriginX,PlayerOriginY);
     DioComponentUnique->SetTexture("AvoiedDioTexture1");
        DioComponentUnique->SetLayer(42);
        
   auto DioIdleAnimation = std::make_unique<FrameAnimation>();
   DioIdleAnimation->FrameRate = 4;
   std::vector<std::string> DioIdleVectorFrames;
   DioIdleVectorFrames.push_back("AvoiedDioBodyTexture1");
   DioIdleVectorFrames.push_back("AvoiedDioBodyTexture2");
      DioIdleVectorFrames.push_back("AvoiedDioBodyTexture3");
         DioIdleVectorFrames.push_back("AvoiedDioBodyTexture3");
   DioIdleVectorFrames.push_back("AvoiedDioBodyTexture2");
      DioIdleVectorFrames.push_back("AvoiedDioBodyTexture1");
   DioIdleAnimation->SetFrames(DioIdleVectorFrames);
   SunCore::instance().FrameAnimations.CreateFrameAnimation("DioIdleAnimation",std::move(DioIdleAnimation));

    
   auto DioIdleHairAnimation = std::make_unique<FrameAnimation>();
   DioIdleHairAnimation->FrameRate = 4;
   std::vector<std::string> DioIdleHairVectorFrames;
   DioIdleHairVectorFrames.push_back("AvoiedDioHairTexture1");
   DioIdleHairVectorFrames.push_back("AvoiedDioHairTexture2");
      DioIdleHairVectorFrames.push_back("AvoiedDioHairTexture3");
         DioIdleHairVectorFrames.push_back("AvoiedDioHairTexture3");
   DioIdleHairVectorFrames.push_back("AvoiedDioHairTexture2");
      DioIdleHairVectorFrames.push_back("AvoiedDioHairTexture1");
   DioIdleHairAnimation->SetFrames(DioIdleHairVectorFrames);
   SunCore::instance().FrameAnimations.CreateFrameAnimation("DioIdleHairAnimation",std::move(DioIdleHairAnimation));


   auto DioIdleHeadAnimation = std::make_unique<FrameAnimation>();
   DioIdleHeadAnimation->FrameRate = 4;
   std::vector<std::string> DioIdleHeadVectorFrames;
   DioIdleHeadVectorFrames.push_back("AvoiedDioHeadTexture1");
   DioIdleHeadVectorFrames.push_back("AvoiedDioHeadTexture2");
      DioIdleHeadVectorFrames.push_back("AvoiedDioHeadTexture3");
      DioIdleHeadVectorFrames.push_back("AvoiedDioHeadTexture2");
   DioIdleHeadVectorFrames.push_back("AvoiedDioHeadTexture2");
      DioIdleHeadVectorFrames.push_back("AvoiedDioHeadTexture1");
   DioIdleHeadAnimation->SetFrames(DioIdleHeadVectorFrames);
   SunCore::instance().FrameAnimations.CreateFrameAnimation("DioIdleHeadAnimation",std::move(DioIdleHeadAnimation));


   auto DioIdleBootsAnimation = std::make_unique<FrameAnimation>();
   DioIdleBootsAnimation->FrameRate = 4;
   std::vector<std::string> DioIdleBootsVectorFrames;
   DioIdleBootsVectorFrames.push_back("AvoiedDioBootsTexture1");
   DioIdleBootsVectorFrames.push_back("AvoiedDioBootsTexture2");
   DioIdleBootsVectorFrames.push_back("AvoiedDioBootsTexture3");
     DioIdleBootsVectorFrames.push_back("AvoiedDioBootsTexture3");
   DioIdleBootsVectorFrames.push_back("AvoiedDioBootsTexture2");
   DioIdleBootsVectorFrames.push_back("AvoiedDioBootsTexture1");
   DioIdleBootsAnimation->SetFrames(DioIdleBootsVectorFrames);
   SunCore::instance().FrameAnimations.CreateFrameAnimation("DioIdleBootsAnimation",std::move(DioIdleBootsAnimation));

   
   auto DioIdleFallMarkAnimation = std::make_unique<FrameAnimation>();
   DioIdleFallMarkAnimation->FrameRate = 4;
   std::vector<std::string> DioIdleFallMarkVectorFrames;
   DioIdleFallMarkVectorFrames.push_back("AvoiedDioFallMarkTexture1");
   DioIdleFallMarkVectorFrames.push_back("AvoiedDioFallMarkTexture2");
      DioIdleFallMarkVectorFrames.push_back("AvoiedDioFallMarkTexture3");
         DioIdleFallMarkVectorFrames.push_back("AvoiedDioFallMarkTexture3");
   DioIdleFallMarkVectorFrames.push_back("AvoiedDioFallMarkTexture2");
      DioIdleFallMarkVectorFrames.push_back("AvoiedDioFallMarkTexture1");
   DioIdleFallMarkAnimation->SetFrames(DioIdleFallMarkVectorFrames);
   SunCore::instance().FrameAnimations.CreateFrameAnimation("DioIdleFallMarkAnimation",std::move(DioIdleFallMarkAnimation));

   
   
   auto DioIdleFrontBodyAnimation = std::make_unique<FrameAnimation>();
   DioIdleFrontBodyAnimation->FrameRate = 4;
   std::vector<std::string> DioIdleFrontBodyVectorFrames;
   DioIdleFrontBodyVectorFrames.push_back("AvoiedDioBodyFrontTexture1");
   DioIdleFrontBodyVectorFrames.push_back("AvoiedDioBodyFrontTexture2");
      DioIdleFrontBodyVectorFrames.push_back("AvoiedDioBodyFrontTexture3");
         DioIdleFrontBodyVectorFrames.push_back("AvoiedDioBodyFrontTexture3");
   DioIdleFrontBodyVectorFrames.push_back("AvoiedDioBodyFrontTexture2");
      DioIdleFrontBodyVectorFrames.push_back("AvoiedDioBodyFrontTexture1");
   DioIdleFrontBodyAnimation->SetFrames(DioIdleFrontBodyVectorFrames);
   SunCore::instance().FrameAnimations.CreateFrameAnimation("DioIdleFrontBodyAnimation",std::move(DioIdleFrontBodyAnimation));

   
   auto DioIdlePantsAnimation = std::make_unique<FrameAnimation>();
   DioIdlePantsAnimation->FrameRate = 4;
   std::vector<std::string> DioIdlePantsVectorFrames;
   DioIdlePantsVectorFrames.push_back("AvoiedDioPantsTexture1");
   DioIdlePantsVectorFrames.push_back("AvoiedDioPantsTexture2");
      DioIdlePantsVectorFrames.push_back("AvoiedDioPantsTexture3");
       DioIdlePantsVectorFrames.push_back("AvoiedDioPantsTexture3");
   DioIdlePantsVectorFrames.push_back("AvoiedDioPantsTexture2");
      DioIdlePantsVectorFrames.push_back("AvoiedDioPantsTexture1");
   DioIdlePantsAnimation->SetFrames(DioIdlePantsVectorFrames);
   SunCore::instance().FrameAnimations.CreateFrameAnimation("DioIdlePantsAnimation",std::move(DioIdlePantsAnimation));
   
   auto DioIdlePantsBandsAnimation = std::make_unique<FrameAnimation>();
   DioIdlePantsBandsAnimation->FrameRate = 4;
   std::vector<std::string> DioIdlePantsBandsVectorFrames;
   DioIdlePantsBandsVectorFrames.push_back("AvoiedDioPantsBandsTexture1");
   DioIdlePantsBandsVectorFrames.push_back("AvoiedDioPantsBandsTexture2");
      DioIdlePantsBandsVectorFrames.push_back("AvoiedDioPantsBandsTexture3");
         DioIdlePantsBandsVectorFrames.push_back("AvoiedDioPantsBandsTexture3");
   DioIdlePantsBandsVectorFrames.push_back("AvoiedDioPantsBandsTexture2");
      DioIdlePantsBandsVectorFrames.push_back("AvoiedDioPantsBandsTexture1");
   DioIdlePantsBandsAnimation->SetFrames(DioIdlePantsBandsVectorFrames);
   SunCore::instance().FrameAnimations.CreateFrameAnimation("DioIdlePantsBandsAnimation",std::move(DioIdlePantsBandsAnimation));

   

   auto DioIdleNamelessSwordAnimation = std::make_unique<FrameAnimation>();
   DioIdleNamelessSwordAnimation->FrameRate = 4;
   std::vector<std::string> DioIdleNamelessSwordVectorFrames;
   DioIdleNamelessSwordVectorFrames.push_back("AvoiedDioNamelessSwordTexture1");
   DioIdleNamelessSwordVectorFrames.push_back("AvoiedDioNamelessSwordTexture2");
      DioIdleNamelessSwordVectorFrames.push_back("AvoiedDioNamelessSwordTexture3");
      DioIdleNamelessSwordVectorFrames.push_back("AvoiedDioNamelessSwordTexture3");
   DioIdleNamelessSwordVectorFrames.push_back("AvoiedDioNamelessSwordTexture2");
      DioIdleNamelessSwordVectorFrames.push_back("AvoiedDioNamelessSwordTexture1");
   DioIdleNamelessSwordAnimation->SetFrames(DioIdleNamelessSwordVectorFrames);
   SunCore::instance().FrameAnimations.CreateFrameAnimation("DioIdleNamelessSwordAnimation",std::move(DioIdleNamelessSwordAnimation));

   

   auto DioIdleTShirtAnimation = std::make_unique<FrameAnimation>();
   DioIdleTShirtAnimation->FrameRate = 4;
   std::vector<std::string> DioIdleTShirtVectorFrames;
   DioIdleTShirtVectorFrames.push_back("AvoiedDioTShirtTexture1");
   DioIdleTShirtVectorFrames.push_back("AvoiedDioTShirtTexture2");
      DioIdleTShirtVectorFrames.push_back("AvoiedDioTShirtTexture3");
         DioIdleTShirtVectorFrames.push_back("AvoiedDioTShirtTexture3");
   DioIdleTShirtVectorFrames.push_back("AvoiedDioTShirtTexture2");
      DioIdleTShirtVectorFrames.push_back("AvoiedDioTShirtTexture1");
   DioIdleTShirtAnimation->SetFrames(DioIdleTShirtVectorFrames);
   SunCore::instance().FrameAnimations.CreateFrameAnimation("DioIdleTShirtAnimation",std::move(DioIdleTShirtAnimation));


















   DioComponentUnique->SetAnimation("DioIdleAnimation");
     SunRendering.AddSprite(std::move(DioComponentUnique),this);
    auto* DioComponent = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioComponent")->second.get();
 //DioComponent->SetTextureMask("AvoiedDioWindMask1");
 //DioComponent->AddMaterial("GrassMaterial");
// DioComponent->AddMaterialUniforms(DioWindUniforms);


   std::unique_ptr<Component> DioComponentHair = 
    std::make_unique<Component>("DioHair", PlayerW, PlayerH, PlayerX, PlayerY,PlayerOriginX,PlayerOriginY);
     DioComponentHair->SetTexture("AvoiedDioHairTexture1");
     DioComponentHair->SetzIndex(10);
        DioComponentHair->SetAnimation("DioIdleHairAnimation");
     
   std::unique_ptr<Component> DioComponentHead = 
    std::make_unique<Component>("DioHead", PlayerW, PlayerH, PlayerX, PlayerY,PlayerOriginX,PlayerOriginY);
     DioComponentHead->SetTexture("AvoiedDioHeadTexture1");
   DioComponentHead->SetzIndex(9);
   DioComponentHead->SetAnimation("DioIdleHeadAnimation");
     
       std::unique_ptr<Component> DioComponentBoots = 
    std::make_unique<Component>("DioBoots", PlayerW, PlayerH, PlayerX, PlayerY,PlayerOriginX,PlayerOriginY);
     DioComponentBoots->SetTexture("AvoiedDioBootsTexture1");
   DioComponentBoots->SetzIndex(1);
   DioComponentBoots->SetAnimation("DioIdleBootsAnimation");
     
       std::unique_ptr<Component> DioComponentFallMark = 
    std::make_unique<Component>("DioFallMark", PlayerW, PlayerH, PlayerX, PlayerY,PlayerOriginX,PlayerOriginY);
     DioComponentFallMark->SetTexture("AvoiedDioFallMarkTexture1");
DioComponentFallMark->SetzIndex(5);

DioComponentFallMark->SetAnimation("DioIdleFallMarkAnimation");
     
       std::unique_ptr<Component> DioComponentPants = 
    std::make_unique<Component>("DioPants", PlayerW, PlayerH, PlayerX, PlayerY,PlayerOriginX,PlayerOriginY);
     DioComponentPants->SetTexture("AvoiedDioPantsTexture1");
DioComponentPants->SetzIndex(4);
     
      std::unique_ptr<Component> DioComponentPantsBands = 
    std::make_unique<Component>("DioPantsBands", PlayerW, PlayerH, PlayerX, PlayerY,PlayerOriginX,PlayerOriginY);
     DioComponentPantsBands->SetTexture("AvoiedDioPantsBandsTexture1");
DioComponentPantsBands->SetzIndex(5);
DioComponentPantsBands->SetAnimation("DioIdlePantsBandsAnimation");
     
      std::unique_ptr<Component> DioComponentNamelessSword = 
    std::make_unique<Component>("DioNamelessSword", PlayerW, PlayerH, PlayerX, PlayerY,PlayerOriginX,PlayerOriginY);
     DioComponentNamelessSword->SetTexture("AvoiedDioNamelessSwordTexture1");
DioComponentNamelessSword->SetzIndex(1);
DioComponentNamelessSword->SetAnimation("DioIdleNamelessSwordAnimation");
     
  std::unique_ptr<Component> DioComponentFrontBody = 
    std::make_unique<Component>("DioFrontBody", PlayerW, PlayerH, PlayerX, PlayerY,PlayerOriginX,PlayerOriginY);
     DioComponentFrontBody->SetTexture("AvoiedDioBodyFrontTexture1");
DioComponentFrontBody->SetzIndex(7);
DioComponentFrontBody->SetAnimation("DioIdleFrontBodyAnimation");

       std::unique_ptr<Component> DioComponentTShirt = 
    std::make_unique<Component>("DioTShirt", PlayerW, PlayerH, PlayerX, PlayerY,PlayerOriginX,PlayerOriginY);
     DioComponentTShirt->SetTexture("AvoiedDioTShirtTexture1");
DioComponentTShirt->SetzIndex(6);
DioComponentTShirt->SetAnimation("DioIdleTShirtAnimation");

 SunRendering.AddSprite(std::move(DioComponentHair),this,SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioComponent")->second.get());
    auto* DioHair = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioHair")->second.get();
     DioHair->SetTextureMask("AvoiedDioWindMask1"); 
 DioHair->AddMaterial("WindMaterial");
 DioHair->AddMaterialUniforms(DioHairWindUniforms);
  

 SunRendering.AddSprite(std::move(DioComponentHead),this,SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioComponent")->second.get());
    auto* DioHead = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioHead")->second.get();



 SunRendering.AddSprite(std::move(DioComponentBoots),this,SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioComponent")->second.get());
    auto* DioBoots = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioBoots")->second.get();



 SunRendering.AddSprite(std::move(DioComponentTShirt),this,SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioComponent")->second.get());
    auto* DioTShirt = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioTShirt")->second.get();
      DioTShirt->SetTextureMask("AvoiedDioWindMask1"); 
 DioTShirt->AddMaterial("WindMaterial");
 DioTShirt->AddMaterialUniforms(DioTShirtWindUniforms);

 SunRendering.AddSprite(std::move(DioComponentPants),this,SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioComponent")->second.get());
    auto* DioPants = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioPants")->second.get();
  DioPants->SetTextureMask("AvoiedDioWindMask1"); 
 DioPants->AddMaterial("WindMaterial");
 DioPants->AddMaterialUniforms(DioPantsWindUniforms);
 SunRendering.AddSprite(std::move(DioComponentPantsBands),this,SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioComponent")->second.get());
    auto* DioPantsBands = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioPantsBands")->second.get();
DioPantsBands->SetTextureMask("AvoiedDioWindMask1Bands"); 
 DioPantsBands->AddMaterial("WindMaterial");
DioPantsBands->AddMaterialUniforms(DioBandsWindUniforms);
 SunRendering.AddSprite(std::move(DioComponentFallMark),this,SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioComponent")->second.get());
    auto* DioFallMark = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioFallMark")->second.get();
 DioFallMark->AddMaterial("FallMarkMaterial");
     SunRendering.AddSprite(std::move(DioComponentNamelessSword),this,SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioComponent")->second.get());
    auto* DioNamelessSword = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioNamelessSword")->second.get();
       DioNamelessSword->SetTextureMask("AvoiedDioWindMask1NamelessSword"); 
 DioNamelessSword->AddMaterial("WindMaterial");
DioNamelessSword->AddMaterialUniforms(DioNamelessSwordWindUniforms);

    SunRendering.AddSprite(std::move(DioComponentFrontBody),this,SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioComponent")->second.get());
    auto* DioFrontBody = SunCore::instance().SunWorld.GetWorldComponentsMap().find("DioFrontBody")->second.get();










      
     PlayerAttributesClass DioAttributes;
     DioAttributes.WalkSpeedX = 1.0f;
     

   Dio = new Player(DioComponent,DioAttributes);
   auto DioRef = Dio;
     
     struct MoveLeft : Ability{
      public:
    void Activate(Player& Player)override{
     Player.State = PlayerStates::WalkLeft;
    }
    
};
    
Dio->Abilities.push_back(std::make_unique<MoveLeft>());
     
    
     auto DioMoveRightListener = std::make_unique<SunListener>(); 
     DioMoveRightListener->Id = "DioMoveRightListener";

     SunEventTrigger DioMoveRightTrigger;
      DioMoveRightTrigger.SetKeyboardTrigger(KeyboardTriggersType::KeyHeld,KeyCodes::D);
     DioMoveRightListener->Trigger = DioMoveRightTrigger;
     DioMoveRightListener->UseFn = true;
     DioMoveRightListener->Fn = [DioRef](SunEvent& e){
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
     DioMoveLeftTrigger.SetKeyboardTrigger(KeyboardTriggersType::KeyHeld,KeyCodes::A);
     DioMoveLeftListener->Trigger = DioMoveLeftTrigger;
     DioMoveLeftListener->UseFn = true;
     DioMoveLeftListener->Fn = [DioRef](SunEvent& e){
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
      DioMoveDownTrigger.SetKeyboardTrigger(KeyboardTriggersType::KeyHeld,KeyCodes::S);
     DioMoveDownListener->Trigger = DioMoveDownTrigger;
     DioMoveDownListener->UseFn = true;
     DioMoveDownListener->Fn = [DioRef](SunEvent& e){
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
     DioMoveUpTrigger.SetKeyboardTrigger(KeyboardTriggersType::KeyHeld,KeyCodes::W);
     DioMoveUpListener->Trigger = DioMoveUpTrigger;
     DioMoveUpListener->UseFn = true;
     DioMoveUpListener->Fn = [DioRef](SunEvent& e){
     Dio->UseAbility(3);
     };
     SunListenersControl.AddListener(std::move(DioMoveUpListener));

   
     auto DioBody = std::make_unique<SunBodys>();
     auto DioMainBody = std::make_unique<Body>();
     DioMainBody->Height = 128.0f;
     DioMainBody->Width = 128.0f;
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

    SunCore::instance().Camera.StartFollow(DioComponent->GetId());
    SunCore::instance().Camera.SetCamLimits(-SunCore::instance().WindowWidth / 2,-SunCore::instance().WindowHeight / 2,20000,20000);
    SunCore::instance().Camera.SetSmmoth(0.06);




    }

    void OnUpdate() override{

       
      if(!VerifyKeyHeld(KeyCodes::A) && !VerifyKeyHeld(KeyCodes::D)){
        Dio->State = PlayerStates::Idle;
      }

      Dio->Update();
    }
  };



  



























   
   InfinityAbyssConfig.Window.WindowName = "Infinity Abyss";
  auto MenuScenePtr = std::make_unique<MenuScene>();
  SunCore::instance().SunScenes.AddScene("MenuScene",std::move(MenuScenePtr));
  auto* Menu = SunCore::instance().SunScenes.GetScene("MenuScene");
MenuScene* Menu1 = new MenuScene();
  auto GameStartScenePtr = std::make_unique<GameStartScene>();
  SunCore::instance().SunScenes.AddScene("GameStartScene",std::move(GameStartScenePtr));

   InfinityAbyssConfig.SunScenes.Scenes = "MenuScene";
   InfinityAbyssConfig.BodysDebug = true;
   
    
    
    
    
  

    StartEngine(InfinityAbyssConfig);
    return 0;
}