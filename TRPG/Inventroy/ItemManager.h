#pragma once
#include <algorithm>
#include <map>

#include "../Data/ItemData.h"


// 잡탬 & 포션재료만
class ItemManager
{
    std::map<EItem, ItemData*> ItemContainer;
    
public:
    
    ItemManager()
    {
        ItemContainer.insert(make_pair(EItem::SlimeJelly, new ItemData("슬라임 젤리", 30)));
        ItemContainer.insert(make_pair(EItem::Berry, new ItemData("베리", 5)));
        ItemContainer.insert(make_pair(EItem::Herb, new ItemData("허브", 20)));
        ItemContainer.insert(make_pair(EItem::Water, new ItemData("물", 10)));
    }

    ~ItemManager()
    {
        for (auto& pair : ItemContainer)
        {
            if (pair.second != nullptr)
            {
                delete pair.second;
                pair.second = nullptr; // 안전을 위해 nullptr 처리
            }
        }
        ItemContainer.clear();
    }
};
