#pragma once
#include "../Interface/IEnterable.h"

class BattleInventory: public IEnterable
{
    bool bIsEnter = false;
public:
    void Enter() override;
    void Quit() override;
};
