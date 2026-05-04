#pragma once
#include "../Interface/IBattleObject.h"
#include "../Data/MonsterData.h"

class MonsterBase : public IBattleObject
{
protected:
    MonsterData Data;

public:

    MonsterBase(MonsterData _data) : Data(_data)
    {
        
    }

    void OnHit(int _damage) override;
    void Attack(IBattleObject* target) override;
    bool IsDead() override;
    string GetName();
    RequireItem GetDropItem() const;
};
