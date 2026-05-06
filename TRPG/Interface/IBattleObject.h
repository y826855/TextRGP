#pragma once

class IBattleObject
{
public:
    virtual void Attack(IBattleObject* _target) = 0;
    virtual void OnHit(int _damage) = 0;
    virtual void OnHit(int _damage, int _count) = 0;
    virtual bool IsDead() = 0;
};
