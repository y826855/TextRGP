#pragma once
#include "PlayerBase.h"
#include "../Singleton.h"

class PlayerManager : public Singleton<PlayerManager>
{
    friend class Singleton<PlayerManager>;

private:
    PlayerBase* Player;

    
    PlayerManager() : Player(nullptr) {} // 생성자를 private으로 숨김
    ~PlayerManager() override
    {
        delete Player;
    }

public:

    void SetPlayer(PlayerBase* newPlayer)
    {
        if (Player) delete Player;
        Player = newPlayer;
    }
    PlayerBase* GetPlayer() const { return Player; }
};