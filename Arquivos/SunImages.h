#pragma once
#include <string>
#include <GL/glew.h>
#include "SunEngineCore.h"

class SunTexturesControl{
public:
void NewTexture(const std::string& TextureId,const char* TexturePath);
void DeleteTexture(const std::string& TextureId);
};
