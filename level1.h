#pragma once
#include "mainCombat.h"
class level1 :
    public mainCombat
{
public:
    level1() : mainCombat() {};
    void loadMedia() override;
    void eventHandler(SDL_Event e) override;
};

