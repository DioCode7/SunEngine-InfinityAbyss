#pragma once
#include <string>

 class SunRender{
    public:
   void AddRectangle(Component* ComponentClass,Scene* OwnerScene,Component* Parent = nullptr);
    void AddCircle(Component* ComponentClass,Scene* OwnerScene,Component* Parent = nullptr);
void AddSprite(std::unique_ptr<Component> ComponentClass,Scene* OwnerScene,Component* Parent = nullptr);
};
void WindowManipulate(const std::string ManipulateType);

void RunScene(Scene* RequestScene);
void ScenesLoop();