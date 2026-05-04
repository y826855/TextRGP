#pragma once
#include <vector>
#include "../Data/ItemData.h"


// 잡탬 & 포션재료만 
class InventoryManager
{
private:
    std::vector<ItemData*> Inventory;
    const int CHUNK_SIZE = 10; 
    
public:
    InventoryManager()
    {
        Inventory.reserve(CHUNK_SIZE);
    }
    
    void AddItem(ItemData* item)
    {
        if (Inventory.size() == Inventory.capacity()) // 사이즈 부족하면 추가함
            Inventory.reserve(Inventory.capacity() + CHUNK_SIZE);

        Inventory.push_back(item);
    }
    
    void RemoveItem(ItemData* item);
    
    void ShowInventory();

    ~InventoryManager()
    {
        for (auto& item : Inventory)
        {
            if (item != nullptr)
            {
                delete item;
                item = nullptr; // 안전을 위해 nullptr 처리
            }
        }
        Inventory.clear();
    }
};
