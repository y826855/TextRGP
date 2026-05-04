#pragma once
#include "PotionBase.h"
#include "../../Data/PotionRecipe.h"

class HPPotion : public PotionBase
{
public:

    HPPotion() : PotionBase("MP포션",
        new EItem [ EItem::Water, EItem::Berry ])
    {
        
    }
    
    void Use() override
    {
        //TODO : 플레이어 데이터 접근 & HP 회복   
    }

};
