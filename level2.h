#pragma once
#include "mainCombat.h"
class level2 :
    public mainCombat
{
public:
    level2() : mainCombat() {};
    void loadMedia() override;
    void eventHandler(SDL_Event e) override;
    void update() override;
    void render() override;
};
