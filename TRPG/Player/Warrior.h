#pragma once
#include "PlayerBase.h"

class Warrior : PlayerBase
{
public:
    Warrior(const string& _name, int _hp, int _mp, int _atk, int _def)
        : PlayerBase(_name, _hp, _mp, _atk, _def)
    {
        playerData->SetJob(EPlayerJob::Warrior);
        //playerData->StatArray[EStat::DEF] += 30;
    }
};
