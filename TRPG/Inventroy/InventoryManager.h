#pragma once
#include <vector>

#include "../Singleton.h"
#include "../Data/ItemData.h"


// 잡탬 & 포션재료만 
class InventoryManager : public Singleton<InventoryManager>
{
private:
    friend class Singleton<InventoryManager>;
    
    std::vector<ItemData*> Inventory;
    const int CHUNK_SIZE = 10; 
    
public:
    InventoryManager();

    void AddItem(ItemData* item);
    void AddItem(EItem itemID);

    void RemoveItem(ItemData* item);
    
    void ShowInventory();

    ~InventoryManager() override;
};
