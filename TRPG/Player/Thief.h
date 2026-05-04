#pragma once
#include "PlayerBase.h"

class Thief : public PlayerBase
{
public:
    
    Thief(const string& _name, const int* _stat);

    void Attack(IBattleObject* target) override;

    void ShowJobStat() override;
};
