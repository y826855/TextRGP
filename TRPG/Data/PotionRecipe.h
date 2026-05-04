#pragma once
#include <vector>

#include "ItemData.h"


enum class EPotion
{
    EHPPotion,
    EMPPotion,
};


struct PotionRecipe
{
private:
    vector<RequireItem> RequireItems;
    
public:
    
    PotionRecipe(vector<RequireItem> _requireItems)
    {
        RequireItems = _requireItems; // 포션 재료 초기화
    }

    vector<RequireItem> GetRequireItems() { return RequireItems; }

    void ShowRequireItem()
    {
        cout << " ( ";
        bool isFirst = true;
        for (auto& item : RequireItems)
        {
            if (!isFirst) cout << ", "; 
            item.ShowInfo();
            isFirst = false;
        }
        cout << " ) ";
    }
};
