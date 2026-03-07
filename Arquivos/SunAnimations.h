#pragma once
#include "SunEngineCore.h"


class SunAnimationsRender{
    private:
    void ResolveTarget(Animations& a,Component* c);
        void ResolveInitTarget(Animations& a,Component* c);
public:
void PlayAnimation(std::string ComponentId,SunAnimation Animation);
};

