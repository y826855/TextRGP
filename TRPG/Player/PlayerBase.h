#pragma once
#include "../Interface/IBattleObject.h"
#include "../PrintHelper.h"
#include "../Data/PlayerData.h"

class PlayerBase : public IBattleObject
{

protected:
    PlayerData* Data;
    
public:
    
    PlayerBase(const string& _name, const int* _stat)
    {
        Data = new PlayerData(_name, _stat);
    }

    virtual void ShowJobStat() = 0;

    void OnHit(int _damage) override;
    bool IsDead() override;

    // ---- 출력용
    void PrintPlayerStatus();
    void ShowCurrentStat();


    string GetJobName() const;
    string GetName() { return Data->PlayerName; }

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

    ~PlayerBase() { delete Data; }
};
