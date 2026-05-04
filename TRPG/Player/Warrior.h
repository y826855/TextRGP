#pragma once
#include "PlayerBase.h"

class Warrior : public PlayerBase
{
public:

    Warrior(const string& _name, const int* _stat);

    void Attack(IBattleObject* target) override;
    
    void ShowJobStat() override;
};
