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
    void clean() override;
    void handlePlayer(SDL_Event &e);
    entity* current;
    SDL_Texture* board;
    bool myturn;
    int allyturn;
    int enemyturn;
};
