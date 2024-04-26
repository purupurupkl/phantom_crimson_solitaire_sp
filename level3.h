#pragma once
#include "mainCombat.h"
class level3 :
    public mainCombat
{
public:
    level3() : mainCombat() {};
    void loadMedia() override;
    void handlePlayer(SDL_Event &e);
    void eventHandler(SDL_Event e) override;
    void clean() override;
};

