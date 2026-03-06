#pragma once
#include <string>
#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>
#include <codecvt>
#include <locale>
#include "SunEngineCore.h"

class SunText{
  public:
  void Init();
  void AddFont(std::unique_ptr<SunFont> Font);
};

