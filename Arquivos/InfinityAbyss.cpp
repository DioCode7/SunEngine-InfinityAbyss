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
         
         auto CinzelFont = std::make_unique<SunFont>();
         CinzelFont->Id = "Cinzel";
         CinzelFont->FontPath = "./Assets/Fonts/CinzelDecorative-Bold.ttf";
         CinzelFont->Height = 31;
    
     
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
     
    // std::cout << "\n"<<SunCore::instance().SunWorld.GetWorldComponentsMap().find("PlayText")->second->GetRenderComponent()->X << "  ,  " << SunCore::instance().SunWorld.GetWorldComponentsMap().find("PlayText")->second->GetRenderComponent()->Y << " \n"  ;
    };
    
       

};
   
   InfinityAbyssConfig.Window.WindowName = "Infinity Abyss";
   MenuScene* Menu = new MenuScene();
   InfinityAbyssConfig.SunScenes.Scenes = {Menu};
   InfinityAbyssConfig.BodysDebug =true;
   
    
    
    
    
  

    StartEngine(InfinityAbyssConfig);
    return 0;
}