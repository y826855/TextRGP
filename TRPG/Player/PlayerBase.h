#pragma once
#include "../Data/PlayerData.h"

class PlayerBase
{
protected:
    PlayerData* playerData;
public:
    PlayerBase(const string& _name, int _hp, int _mp, int _atk, int _def)
    {
        int* stat = new int [ _hp, _mp, _atk, _def ];
        playerData = new PlayerData(_name, stat);
    }
    
    virtual void Attack() = 0;
    virtual ~PlayerBase() { delete playerData; }

    void PrintPlayerStatus(); // TODO 캐릭터 정보 출력
};
