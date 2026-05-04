#include "Mage.h"

Mage::Mage(const string& _name, const int* _stat):PlayerBase(_name, _stat)
{
    SetJob(EPlayerJob::EMage);
    AddMP(30);
}

void Mage::Attack(IBattleObject* target)
{
    cout << "마법사의 파이어볼!" << endl;
    target->OnHit(GetAtk());
}

void Mage::ShowJobStat()
{
    cout << " * 마법사로 전직하였습니다. (MP + 30)" << endl;
    cout << " * 파이어볼을 발사한다!" << endl;
}
