#pragma once
#include "MonsterBase.h"

class Dragon : public MonsterBase
{
public:

    Dragon();
    void Attack(IBattleObject* target) override;
};
