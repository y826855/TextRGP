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

enum class EPlayerJob
{
    None = 0,
    EWarrior = 1,
    EMage = 2,
    EThief = 3,
    EArcher = 4,
};


struct PlayerData
{
    string PlayerName;
    int StatArray[4]; // HP, MP, ATK, DEF
    int Exp = 0;
    int Level = 1;
    EPlayerJob playerJob = EPlayerJob::None;

    PlayerData(const string& _name, const int* _statArray)
    {
        PlayerName = _name;
        for (int i = 0; i < 4; ++i) StatArray[i] = _statArray[i];
    }
};
