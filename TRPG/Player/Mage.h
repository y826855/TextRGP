#pragma once
#include "PlayerBase.h"

class Mage : public PlayerBase
{
public:

    Mage(const string& name, int hp, int mp, int atk, int def)
        :PlayerBase(name, hp, mp, atk, def)
    {
        SetJob(EPlayerJob::EMage);
        AddMP(30);
    }
    
    Mage(PlayerBase* player)
        : PlayerBase(player, EPlayerJob::EMage)
    {
        AddMP(30);
    }

    void Attack() override
    {
        
    }

    void ShowJobStat() override
    {
        cout << " * 마법사로 전직하였습니다. (MP + 30)" << endl;
        cout << " * 파이어볼을 발사한다!" << endl;
    }
};
