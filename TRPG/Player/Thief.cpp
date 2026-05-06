#include "Thief.h"

Thief::Thief(const string& _name, const int* _stat):PlayerBase(_name, _stat)
{
    SetJob(EPlayerJob::EThief);
    AddAtk(30);
}

void Thief::Attack(IBattleObject* target)
{
    cout << "도적의 비열한 공격! x5" << endl;
    target->OnHit(GetAtk(), 5);
}

void Thief::ShowJobStat()
{
    cout << " * 도적으로 전직하였습니다. (ATK + 30)" << endl;
    cout << " * 빠르게 5번 공격한다!" << endl;
}
