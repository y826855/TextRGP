#pragma once
#include "Floor.h"
#include "../Interface/IEnterable.h"
#include "../Player/PlayerBase.h"

class Dungeon : public IEnterable
{
    PlayerBase* player = nullptr;
    Floor* selectedFloor = nullptr;

    Floor* SlimeFloor;
    Floor* HydraFloor;
    Floor* OrcFloor;
    Floor* DragonFloor;
    
    bool bIsBattleEnd = false;
    int UnlockedFloor = 0;

protected:
    void SelectFloor();
    
    void FloorInitialize();
    void BattleLoop();
    void PlayerTurn();
    void MonsterTurn();
public:
    Dungeon();
    
    void Enter() override;
    void Quit() override{}
    bool IsClear() { return UnlockedFloor >= 4; }
    
protected:
    void ShowBattleIntro();
    void AfterBattle();
    void Victory();
};
