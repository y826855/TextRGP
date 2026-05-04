#pragma once
#include "../PrintHelper.h"
#include "../Data/PlayerData.h"

class PlayerBase
{

protected:
    PlayerData* Data;
    
public:
    PlayerBase(const string& _name, int _hp, int _mp, int _atk, int _def)
    {
        int* stat = new int[4] { _hp, _mp, _atk, _def };
        Data = new PlayerData(_name, stat);
    }
    
    PlayerBase(const PlayerBase* player, const EPlayerJob job)
    {
        this->Data = player->Data;
        this->Data->playerJob = job;
    }
    
    virtual void Attack() = 0;
    virtual void ShowJobStat() = 0;
    virtual ~PlayerBase() { delete Data; }

// ---- 출력용
    void PrintPlayerStatus()
    {
        PrintHelper::ShowTwoLine();
        cout << Data->PlayerName << "의 현재 능력치" << endl;
        PrintHelper::ShowTwoLine();
        cout << "HP : " << GetHP() << "\t";
        cout << "MP : " << GetMP() << "\t" << endl;
        cout << "ATK : " << GetAtk() << "\t";
        cout << "DEF : " << GetDef() << "\t" << endl;
        PrintHelper::ShowTwoLine();
    }
    void ShowCurrentStat()
    {
        PrintHelper::ShowOneLine();
        cout << "닉네임: " << GetName() << " | ";
        cout << GetJobName() << " | ";
        cout << " Lv.1" << endl;
        
        cout << "HP: " << GetHP() << " | ";
        cout << "MP" << GetMP() << " | ";
        cout << "ATK: " << GetAtk() << " | ";
        cout << "DEF" << GetDef() << endl;
        PrintHelper::ShowOneLine();
    }


    string GetName() { return Data->PlayerName; }
    string GetJobName() const
    {
        switch (Data->playerJob)
        {
        case EPlayerJob::EArcher: return "궁수";
        case EPlayerJob::EThief: return "도적";
        case EPlayerJob::EMage: return "마법사";
        case EPlayerJob::EWarrior: return "전사";
        default: return "직업없음";
        }
    }
    
    int GetHP() const { return Data->StatArray[EStat::HP]; }
    int GetMP() const { return Data->StatArray[EStat::MP]; }
    int GetDef() const { return Data->StatArray[EStat::DEF]; }
    int GetAtk() const { return Data->StatArray[EStat::ATK]; }

    void SetHP(int _hp) const { Data->StatArray[EStat::HP] = _hp; }
    void SetMP(int _mp) const { Data->StatArray[EStat::MP] = _mp; }
    void SetDef(int _def) const { Data->StatArray[EStat::DEF] = _def; }
    void SetAtk(int _atk) const { Data->StatArray[EStat::ATK] = _atk; }
    void SetJob(EPlayerJob _job) const { Data->playerJob = _job; }
    
    //TODO : 최대 최소값 지정 ? 
    void AddHP(int _hp) const { Data->StatArray[EStat::HP] += _hp; }
    void AddMP(int _mp) const { Data->StatArray[EStat::MP] += _mp; }
    void AddDef(int _def) const { Data->StatArray[EStat::DEF] += _def; }
    void AddAtk(int _atk) const { Data->StatArray[EStat::ATK] += _atk; }
};
