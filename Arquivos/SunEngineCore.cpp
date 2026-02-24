#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <string>
#include <variant>
#include <unordered_map>
#include "SunEngineCore.h"

void Scene::SceneConfigs() {}
void Scene::OnLoad() {}
void Scene::OnInit() {}
void Scene::OnUpdate() {}

SDL_Keycode TranslateSDLKey(KeyCodes Key){
 switch(Key){
  case KeyCodes::D:{
    return SDLK_d;
    break;
  }
  case KeyCodes::A:{
    return SDLK_a;
    break;
  }
  case KeyCodes::W:{
    return SDLK_w;
    break;
  }
  case KeyCodes::S:{
    return SDLK_s;
    break;
  }

 };
 return SDLK_UNKNOWN;
};


SDL_Scancode TranslateSDLScan(KeyCodes Key){
 switch(Key){
  case KeyCodes::D:{
    return SDL_SCANCODE_D;
    break;
  }
  case KeyCodes::S:{
    return SDL_SCANCODE_S;
    break;
  }
  case KeyCodes::A:{
    return SDL_SCANCODE_A;
    break;
  }
  case KeyCodes::W:{
    return SDL_SCANCODE_W;
    break;
  }

 };
 return SDL_SCANCODE_UNKNOWN;
};


