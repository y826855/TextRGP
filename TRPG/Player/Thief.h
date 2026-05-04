#pragma once
#include "PlayerBase.h"

class Thief : public PlayerBase
{
public:

    Thief(const string& name, int hp, int mp, int atk, int def)
    :PlayerBase(name, hp, mp, atk, def)
    {
        SetJob(EPlayerJob::EThief);
        AddAtk(30);
    }
    
    Thief(PlayerBase* player)
    : PlayerBase(player, EPlayerJob::EThief)
    {
        AddAtk(30);
    }

    void Attack() override
    {
        
    }

    void ShowJobStat() override
    {
        cout << " * 도적으로 전직하였습니다. (ATK + 30)" << endl;
        cout << " * 빠르게 공격한다!" << endl;
    }
};
