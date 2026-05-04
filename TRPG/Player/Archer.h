#pragma once
#include "PlayerBase.h"

class Archer : public PlayerBase
{
public:

    Archer(const string& name, int hp, int mp, int atk, int def)
     :PlayerBase(name, hp, mp, atk, def)
    {
        SetJob(EPlayerJob::EArcher);
        AddAtk(30);
    }
    
    Archer(PlayerBase* player)
    : PlayerBase(player, EPlayerJob::EArcher)
    {
        AddAtk(30);
    }

    void Attack() override
    {
        
    }

    void ShowJobStat() override
    {
        cout << " * 궁수로 전직하였습니다. (ATK + 30)" << endl;
        cout << " * 활을 쏜다!" << endl;
    }
};
