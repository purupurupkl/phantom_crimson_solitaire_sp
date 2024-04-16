#pragma once
#include "mainCombat.h"
class level2 :
    public mainCombat
{
    level2() : mainCombat::mainCombat() {};
    void loadMedia() override;
};

