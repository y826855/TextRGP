#pragma once
#include "MonsterBase.h"

class Orc : public MonsterBase
{
public:
    Orc();
    void Attack(IBattleObject* target) override;
};
