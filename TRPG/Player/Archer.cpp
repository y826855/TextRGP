#include "Archer.h"

Archer::Archer(const string& _name, const int* _stat):PlayerBase(_name, _stat)
{
    SetJob(EPlayerJob::EArcher);
    AddAtk(30);
}

void Archer::Attack(IBattleObject* target)
{
    cout << "궁수의 사격! x3" << endl;
    target->OnHit(GetAtk(), 3);
}

void Archer::ShowJobStat()
{
    cout << " * 궁수로 전직하였습니다. (ATK + 30)" << endl;
    cout << " * 활로 3번 공격함" << endl;
}
