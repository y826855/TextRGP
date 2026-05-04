#pragma once
#include "../Interface/IEnterable.h"

class Inventory : public IEnterable
{
public:
    void Enter() override;
    void Quit() override{}
};
