#pragma once
#include <vector>

#include "PotionBase.h"
#include "../../Data/PotionRecipe.h"
#include "../../Player/PlayerManager.h"

class HPPotion : public PotionBase
{
    int increaseAmount = 20;
public:

    HPPotion() : PotionBase(
        "HP포션",
    PotionRecipe(vector<RequireItem>{
        { EItem::Water, 1 }, { EItem::Herb, 1 }
    }))
    {
    }
    
    void Use() override
    {
        //TODO : 갯수 감소
        PlayerManager::GetInstance()->GetPlayer()->AddHP(increaseAmount);
    }

};
