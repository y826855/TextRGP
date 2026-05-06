#pragma once

class IBattleObject
{
public:
    virtual void Attack(IBattleObject* target) = 0;
    virtual void OnHit(int damage) = 0;
    virtual bool IsDead() = 0;
    };
