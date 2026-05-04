#pragma once
#include "PlayerBase.h"

class Archer : public PlayerBase
{
public:
    
    Archer(const string& _name, const int* _stat);

    void Attack(IBattleObject* target) override;

    void ShowJobStat() override;
};
