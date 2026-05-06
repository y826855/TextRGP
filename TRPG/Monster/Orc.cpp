#include "Orc.h"

Orc::Orc() : MonsterBase(
    MonsterData(
        "오크",
        100,
        20,
        15,
        8,
        RequireItem(EItem::OrcSkin, 1)))
{
}

void Orc::Attack(IBattleObject* target)
{
    cout << "오크의 휘두르기 공격!" << endl;
    MonsterBase::Attack(target);
}
