#pragma once
#include "PlayerBase.h"

class Archer : PlayerBase
{
public:
    Archer(const string& _name, int _hp, int _mp, int _atk, int _def)
     : PlayerBase(_name, _hp, _mp, _atk, _def)
    {
        playerData->SetJob(EPlayerJob::Archer);
    }
};
