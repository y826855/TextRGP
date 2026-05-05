#pragma once
#include <unordered_map>
#include <vector>

#include "../Singleton.h"
#include "../Alchemy/Postion/PotionBase.h"
#include "../Data/ItemData.h"
#include "../Data/PotionRecipe.h"


// 잡탬 & 포션재료만 
class InventoryManager : public Singleton<InventoryManager>
{
private:
    friend class Singleton<InventoryManager>;
    
    std::vector<ItemData*> Inventory;
    std::unordered_map<EPotion, int> PotionInventory;
    const int CHUNK_SIZE = 10; 
    
public:
    InventoryManager();

    void AddItem(ItemData* _item);
    void AddItem(EItem _itemID);
    
    void AddPotion(EPotion _potionID, int _amount);
    void UsePotion(EPotion _potionID);
    PotionBase* GetHavePotionByID(EPotion _potionID);

    void RemoveItem(ItemData* _item);
    
    void ShowInventory();

    ~InventoryManager() override;
};
