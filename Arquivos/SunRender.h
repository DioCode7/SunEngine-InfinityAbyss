#pragma once
#include "SunEngineCore.h"

void CreateMainWindow(SunEngineConfig& Config);
void EngineRender();
class Renderer{
 public:
 void LoadShaders(SunEngineConfig& Config);
 void InitSDLContext(SunEngineConfig& Config);
};