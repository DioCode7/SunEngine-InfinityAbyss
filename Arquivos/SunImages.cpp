#define STB_IMAGE_IMPLEMENTATION
#include "Libs/stb_image.h"
#include <string>
#include <GL/glew.h>
#include <iostream>
#include "SunImages.h"



GLuint TextureGPULoad(std::string Id,Texture* Texture,unsigned char* Data){
    GLuint texture;
glGenTextures(1,&texture);
   glBindTexture(GL_TEXTURE_2D, texture);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);

glTexImage2D(
    GL_TEXTURE_2D,
    0,
    GL_RGBA,
    Texture->Width,
    Texture->Height,
    0,
    GL_RGBA,
    GL_UNSIGNED_BYTE,
    Data

);
glGenerateMipmap(GL_TEXTURE_2D);
stbi_image_free(Data);
return texture;
};

void LoadImage(std::string Id,const char* ImagePath){

int Width,Height,Channels;
Texture NewTexture;
NewTexture.Id = Id;
unsigned char* Data = stbi_load(ImagePath,&NewTexture.Width,&NewTexture.Height,&Channels,4);
if(!Data){
    std::cout << "Erro Ao Carregar Imagem";
}
if(Data){
GLuint TextureId = TextureGPULoad(Id,&NewTexture,Data);
NewTexture.GPUID = TextureId;
SunCore::instance().SunRenderCore.AddTexture(Id,NewTexture);
 std::cout << "Imagem Carregada";
 std::cout << Id;
}




};

 
void SunTexturesControl::NewTexture(const std::string& TextureId,const char* TexturePath){
  LoadImage(TextureId,TexturePath);
};



