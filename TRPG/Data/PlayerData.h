#pragma once
#include <string>

using namespace std;

enum EStat
{
    HP = 0,
    MP = 1,
    ATK = 2,
    DEF = 3,
};

enum EPlayerJob
{
    None = 0,
    Warrior = 1,
    Mage = 2,
    Thief = 3,
    Archer = 4,
};


struct PlayerData
{
    string PlayerName;
    int StatArray[4]; // HP, MP, ATK, DEF
    EPlayerJob playerJob = EPlayerJob::None;

    PlayerData(const string& _name, const int* _statArray)
    {
        PlayerName = _name;
        playerJob = EPlayerJob::None;
        for (int i = 0; i < 4; ++i) StatArray[i] = _statArray[i];
    }


    void SetJob(EPlayerJob _job) { playerJob = _job; }
    
    int GetHP() { return StatArray[EStat::HP]; }
    int GetMP() { return StatArray[EStat::MP]; }
    int GetDef() { return StatArray[EStat::DEF]; }
    int GetAtk() { return StatArray[EStat::ATK]; }
};
