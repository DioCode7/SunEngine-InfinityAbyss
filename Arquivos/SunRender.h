#pragma once
#include "SunEngineCore.h"
 GLuint CreateShaderProgram(const char* Vs,const char* Fs);
 void CreateComponentVAO(SunShader* sh);
  GLuint CreateFullShaderProgram(const char* Vs,const char* Fs);
void CreateMainWindow(SunEngineConfig& Config);
void EngineRender(float dt,float t);
class Renderer{
 public:
 void LoadShaders(SunEngineConfig& Config);
 void InitSDLContext(SunEngineConfig& Config);

};