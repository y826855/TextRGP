#pragma once
#include "../Interface/IEnterable.h"

class AlchemyWorkShop : public IEnterable
{
    bool bIsEnter = true;
    
public:
    void ShowMenu();

    void Enter() override;
    void Quit() override;
};
