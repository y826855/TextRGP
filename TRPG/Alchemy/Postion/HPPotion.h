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
    PotionRecipe(vector<RequireItem>
        {{ EItem::Water, 1 },
            { EItem::Herb, 1 }}),
        EPotion::EHPPotion)
    {
    }
    
    void Use() override
    {
        auto player = PlayerManager::GetInstance()->GetPlayer();
        cout << "HP가 " << increaseAmount << "증가했습니다. (HP 포션 차감:";
        player->AddHP(increaseAmount);
    }
};
