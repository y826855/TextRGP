#include "Slime.h"

Slime::Slime() : MonsterBase(
    MonsterData(
        "슬라임",
        30,
        10,
        1,
        RequireItem(EItem::SlimeJelly, 1)))
{
}

void Slime::Attack(IBattleObject* target)
{
    cout << "슬라임의 끈적이는 공격!" << endl;
    MonsterBase::Attack(target);
}
