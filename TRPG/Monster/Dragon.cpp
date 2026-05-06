#include "Dragon.h"

Dragon::Dragon() : MonsterBase(
    MonsterData(
        "드래곤",
        200,
        25,
        20,
        15,
        RequireItem(EItem::DragonBone, 1)))
{
}

void Dragon::Attack(IBattleObject* target)
{
    cout << "드래곤의 날카로운 공격!" << endl;
    MonsterBase::Attack(target);
}
