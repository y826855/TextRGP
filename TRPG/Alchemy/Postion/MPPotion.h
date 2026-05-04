#pragma once
#include "PotionBase.h"
#include "../../Data/PotionRecipe.h"


class MPPotion : public PotionBase
{
public:

    MPPotion() : PotionBase("MP포션",
        new EItem [ EItem::Berry, EItem::Herb ])
    {
        
    }
    
    void Use() override
    {
        //TODO : 플레이어 데이터 접근 & 마나 회복   
    }
};
