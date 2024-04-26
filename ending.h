#pragma once
#include "baseState.h"
class ending :
    public baseState
{
public:
    ending() {};
    ~ending() {};
    void loadMedia() override;
    void eventHandler(SDL_Event e) override;
    void update() override;
    void render() override;
    void clean() override;
    SDL_Texture* bg;
    bool restart;
};

