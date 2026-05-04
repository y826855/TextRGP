#include "Warrior.h"

Warrior::Warrior(const string& _name, const int* _stat):PlayerBase(_name, _stat)
{
    SetJob(EPlayerJob::EWarrior); 
    AddDef(30);
}

void Warrior::Attack(IBattleObject* target)
{
    cout << "전사의 우렁찬 공격!" << endl;
    target->OnHit(GetAtk());
}

void Warrior::ShowJobStat()
{
    cout << " * 전사로 전직하였습니다. (DEF + 30)" << endl;
    cout << " * 공격에 잘 버틴다!" << endl;
}
