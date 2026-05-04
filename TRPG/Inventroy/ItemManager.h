#pragma once
#include <map>

#include "../Singleton.h"
#include "../Data/ItemData.h"


// 잡탬 & 포션재료만
class ItemManager : public Singleton<ItemManager>
{
    friend class Singleton<ItemManager>;
    
    std::map<EItem, ItemData*> ItemContainer;

public:
    
    ItemManager();
    
    ItemData* GetItemByID(EItem _itemID);

    string GetNameByID(EItem _itemID);

    ~ItemManager() override;
};
