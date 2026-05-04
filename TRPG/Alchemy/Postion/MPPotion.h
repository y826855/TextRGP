#pragma once
#include <vector>

#include "PotionBase.h"
#include "../../Data/PotionRecipe.h"


class MPPotion : public PotionBase
{
public:


    MPPotion() : PotionBase(
    "MP 포션",
PotionRecipe(vector<RequireItem>{
    { EItem::Berry, 2 }, { EItem::Herb, 1 }
        }))
    {
    }
    
    void Use() override
    {
        //TODO : 플레이어 데이터 접근 & 마나 회복   
    }
};
