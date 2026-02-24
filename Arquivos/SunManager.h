#pragma once

void SunDispatchs();
void SunUpdateInput();

class SunListeners{
    public:
 void AddListener(std::unique_ptr<SunListener> Listener);
};