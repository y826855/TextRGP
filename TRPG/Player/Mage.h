#pragma once
#include "PlayerBase.h"

class Mage : public PlayerBase
{
public:
    
    Mage(const string& _name, const int* _stat);

    void Attack(IBattleObject* target) override;

    void ShowJobStat() override;
};
