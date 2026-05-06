#pragma once
#include <vector>

#include "PotionBase.h"
#include "../../Data/PotionRecipe.h"


class MPPotion : public PotionBase
{
    int increaseAmount = 20;
public:

    MPPotion() : PotionBase(
    "MP포션",
PotionRecipe(vector<RequireItem>
    {{ EItem::Berry, 2 },
        { EItem::Herb, 1 }}),
        EPotion::EMPPotion)
    {
    }
    
    void Use() override;
};
