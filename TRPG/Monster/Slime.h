#pragma once
#include "MonsterBase.h"

class Slime : public MonsterBase
{
public:

    Slime();
    void Attack(IBattleObject* target) override;
};
