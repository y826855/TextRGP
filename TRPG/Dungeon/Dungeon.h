#pragma once
#include "../Interface/IEnterable.h"
#include "../Monster/Slime.h"
#include "../Player/PlayerBase.h"

class Dungeon : public IEnterable
{
    PlayerBase* player = nullptr;
    MonsterBase* monster = nullptr;

public:
    Dungeon();
    void Initalize();
    void Enter() override;
    void Quit() override{}
    
protected:
    void ShowBattleIntro();
    void AfterBattle();
    void Victory() const;
};
