#include "ItemManager.h"

#include "InventoryManager.h"

ItemManager::ItemManager()
{
    ItemContainer.insert(make_pair(EItem::SlimeJelly, new ItemData("슬라임 젤리", 30)));
    ItemContainer.insert(make_pair(EItem::Berry, new ItemData("베리", 5)));
    ItemContainer.insert(make_pair(EItem::Herb, new ItemData("허브", 20)));
    ItemContainer.insert(make_pair(EItem::Water, new ItemData("물", 10)));
    ItemContainer.insert(make_pair(EItem::OrcSkin, new ItemData("오크가죽", 100)));
    ItemContainer.insert(make_pair(EItem::DragonBone, new ItemData("드래곤의뼈", 300)));
}

ItemData* ItemManager::GetItemByID(EItem _itemID)
{
    auto it = ItemContainer.find(_itemID);
    if (it != ItemContainer.end())
        return it->second;
    return nullptr;
}

string ItemManager::GetNameByID(EItem _itemID)
{
    auto it = ItemContainer.find(_itemID);
    if (it != ItemContainer.end())
        return ItemContainer[_itemID]->GetName();
    return "";
}

ItemManager::~ItemManager()
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
