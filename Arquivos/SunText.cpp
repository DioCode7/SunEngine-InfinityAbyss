#include <ft2build.h>
#include FT_FREETYPE_H
#include "SunText.h"
#include <GL/glew.h>
FT_Library ft;

void SunText::Init(){
FT_Init_FreeType(&ft);
};



void LoadFont(SunFont* Sf,FT_Face& Face){
  if(FT_New_Face(ft,Sf->FontPath,0,&Face)){
     std::cout << "Erro ao carregar fonte\n";
  }
  Sf->Face = Face;
  FT_Set_Pixel_Sizes(Face, 0, Sf->Height);

int AtlasWidth = 0;
int AtlasHeight = 0;
for(unsigned char c = 0;c<128;c++){

    if (FT_Load_Char(Face, c, FT_LOAD_RENDER))
    {
        std::cout << "Erro ao carregar glyph\n";
        continue;
    }
    AtlasWidth += Sf->Face->glyph->bitmap.width;
    AtlasHeight = std::max(AtlasHeight, (int)Face->glyph->bitmap.rows);


};
    GLuint texture;
glGenTextures(1, &texture);
glBindTexture(GL_TEXTURE_2D, texture);
    
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexImage2D(
    GL_TEXTURE_2D,
    0,
    GL_RED,
    AtlasWidth,
    AtlasHeight,
    0,
    GL_RED,
    GL_UNSIGNED_BYTE,
    nullptr
);
Sf->AtlasTexture = texture;
int currentX = 0;
std::cout << "Atlas: " << AtlasWidth << " x " << AtlasHeight << "\n";
for (unsigned char c = 0; c < 128; c++)
{
    if (FT_Load_Char(Face, c, FT_LOAD_RENDER))
        continue;
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexSubImage2D(
        GL_TEXTURE_2D,
        0,
        currentX,
        0,
        Face->glyph->bitmap.width,
        Face->glyph->bitmap.rows,
        GL_RED,
        GL_UNSIGNED_BYTE,
        Face->glyph->bitmap.buffer
    );

    Character ch;

    ch.UvMin.x = (float)currentX / AtlasWidth;
    ch.UvMin.y = 0.0f;

    ch.UvMax.x = (float)(currentX + Face->glyph->bitmap.width) / AtlasWidth;
    ch.UvMax.y = (float)Face->glyph->bitmap.rows / AtlasHeight;

    ch.Size.x = Face->glyph->bitmap.width;
    ch.Size.y = Face->glyph->bitmap.rows;

    ch.Bearing.x = Face->glyph->bitmap_left;
    ch.Bearing.y = Face->glyph->bitmap_top;

    ch.Advance = Face->glyph->advance.x;

    Sf->AddToCaracters(c, ch);

    currentX += Face->glyph->bitmap.width;
}


};


void SunText::AddFont(std::unique_ptr<SunFont> Font){
  LoadFont(Font.get(),Font->Face);
  
  SunCore::instance().SunFontsControl.AddFontToWorld("Cinzel",std::move(Font));


  
};
