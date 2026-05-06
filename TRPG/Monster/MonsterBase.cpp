#include "MonsterBase.h"

void MonsterBase::OnHit(int _damage)
{
    auto beforHP = Data.HP; 
    auto damage = max(1, _damage - Data.Def);
    Data.HP -= damage;

    cout << Data.Name << " 에게 " << damage << " 데미지!" << endl;
    cout << Data.Name << " HP : " << beforHP << " -> " << Data.HP;
    if (IsDead()) cout << " (사망)" << endl;
    else cout << endl;
}

void MonsterBase::OnHit(int _damage, int _count)
{
    auto beforHP = Data.HP; 
    auto damage = max(1, _damage - Data.Def);

    for (int i = 0; i < _count; i++)
    {
        Data.HP -= damage;
        cout << Data.Name << " 에게 " << damage << " 데미지!" << endl;
    }

    
    cout << Data.Name << " HP : " << beforHP << " -> " << Data.HP;
    if (IsDead()) cout << " (사망)" << endl;
    else cout << endl;
}

void MonsterBase::Attack(IBattleObject* target)
{
    target->OnHit(Data.Atk);
}

bool MonsterBase::IsDead()
{
    return Data.HP <= 0;
}

string MonsterBase::GetName()
{
    return Data.Name;
}

RequireItem MonsterBase::GetDropItem() const
{
    return Data.DropItem;
}

int MonsterBase::GetExp() const
{
    return Data.Exp;
}