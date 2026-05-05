#pragma once
#include "MonsterBase.h"

class Hydra : public MonsterBase
{
public:
    Hydra();
    void Attack(IBattleObject* target) override;
};
