#pragma once
#include <string>

 class SunRender{
    public:
   void AddRectangle(std::string Id,float PosX,float PosY,float Width,float Height,float R,float G,float B,float A,Scene* OwnerScene);
};
void WindowManipulate(const std::string ManipulateType);

void RunScene(Scene* RequestScene);