#pragma once
#include "mainCombat.h"
class level2 :
    public mainCombat
{
public:
    level2() : mainCombat() {};
    void loadMedia() override;
};

