#pragma once
#include "ItemData.h"

struct PotionRecipe
{
private:
    EItem* RequireItems;
public:
    PotionRecipe(EItem* _itemData)
    {
        RequireItems = _itemData; // 포션 재료 초기화
    }

    ~PotionRecipe()
    {
        delete[] RequireItems;
    }
};
