#include "Hydra.h"

Hydra::Hydra() : MonsterBase(
    MonsterData(
        "히드라",
        100,
        30,
        3,
        RequireItem(EItem::Herb, 1)))
{
}

void Hydra::Attack(IBattleObject* target)
{
    cout << "히드라의 산성 공격!" << endl;
    MonsterBase::Attack(target);
}
