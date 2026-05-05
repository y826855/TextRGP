#pragma once
#include "../Interface/IEnterable.h"

class Lobby : public IEnterable 
{
    bool bIsGameStart = false;
public:
    void Enter() override;
    void ShowMenu();
    void ShowGameOver();
    void Quit() override;
};
