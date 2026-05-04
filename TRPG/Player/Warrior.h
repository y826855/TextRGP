#pragma once
#include "PlayerBase.h"

class Warrior : public PlayerBase
{
public:
    Warrior(const string& name, int hp, int mp, int atk, int def)
        :PlayerBase(name, hp, mp, atk, def)
    {
        SetJob(EPlayerJob::EWarrior); 
        AddDef(30);
    }
    
    Warrior(PlayerBase* player)
        : PlayerBase(player, EPlayerJob::EWarrior)
    {
        AddDef(30);
    }
    
    void Attack() override{}
    
    void ShowJobStat() override
    {
        cout << " * 전사로 전직하였습니다. (DEF + 30)" << endl;
        cout << " * 공격에 잘 버틴다!" << endl;
    }
};
