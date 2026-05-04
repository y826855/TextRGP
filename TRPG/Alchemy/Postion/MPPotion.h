#pragma once
#include <vector>

#include "PotionBase.h"
#include "../../Data/PotionRecipe.h"
#include "../../Player/PlayerManager.h"


class MPPotion : public PotionBase
{
    int increaseAmount = 20;
public:

    MPPotion() : PotionBase(
    "MP포션",
PotionRecipe(vector<RequireItem>{
    { EItem::Berry, 2 }, { EItem::Herb, 1 }
        }))
    {
    }
    
    void Use() override
    {
        //TODO : 사용시 소모
        PlayerManager::GetInstance()->GetPlayer()->AddMP(increaseAmount);
    }
};
