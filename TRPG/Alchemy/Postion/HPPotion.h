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
        "HP 포션",
    PotionRecipe(vector<RequireItem>{
        { EItem::Water, 2 }, { EItem::Herb, 1 }
    }))
    {
    }
    
    void Use() override
    {
        //TODO : 플레이어 데이터 접근 & HP 회복
        PlayerManager::GetInstance()->GetPlayer()->AddHP(increaseAmount);
    }

};
