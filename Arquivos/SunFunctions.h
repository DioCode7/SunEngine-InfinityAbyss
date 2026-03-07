#pragma once
#include <string>

 class SunRender{
    public:
   void AddRectangle(std::unique_ptr<Component>ComponentClass,Scene* OwnerScene,Component* Parent = nullptr);
    void AddCircle(std::unique_ptr<Component>ComponentClass,Scene* OwnerScene,Component* Parent = nullptr);
void AddSprite(std::unique_ptr<Component> ComponentClass,Scene* OwnerScene,Component* Parent = nullptr);
void AddText(std::unique_ptr<Component> ComponentClass,std::string FontId,std::string Text,Scene* OwnerScene,Component* Parent = nullptr);
};
void WindowManipulate(const std::string ManipulateType);


void RunScene(Scene* RequestScene);
void ScenesLoop();
void SunQuit();