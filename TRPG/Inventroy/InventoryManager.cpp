#include "InventoryManager.h"

#include "ItemManager.h"
#include "../Alchemy/AlchemyManager.h"

InventoryManager::InventoryManager()
{
    Inventory.reserve(CHUNK_SIZE);
}

void InventoryManager::AddItem(ItemData* _item)
{
    if (Inventory.size() == Inventory.capacity()) // 사이즈 부족하면 추가함
        Inventory.reserve(Inventory.capacity() + CHUNK_SIZE);
    
    Inventory.push_back(_item);
}

void InventoryManager::AddItem(EItem _itemID)
{
    auto item = ItemManager::GetInstance()->GetItemByID(_itemID);
    if (item == nullptr) return;
    AddItem(item);
}

void InventoryManager::AddPotion(EPotion _potionID, int _amount)
{
    auto iter = PotionInventory.find(_potionID);
    if (iter != PotionInventory.end())
        iter->second += _amount;
    else    
        PotionInventory.insert({_potionID, _amount});
}

void InventoryManager::UsePotion(EPotion _potionID)
{
    auto potion = GetHavePotionByID(_potionID);
    if (potion == nullptr || PotionInventory[_potionID] <= 0) return;
    potion->Use();
    cout << "남은포션 " << --PotionInventory[_potionID] << "개)" << endl;
}

PotionBase* InventoryManager::GetHavePotionByID(EPotion _potionID)
{
    auto iter = PotionInventory.find(_potionID);
    if (iter != PotionInventory.end())
        return AlchemyManager::GetInstance()->GetPotionByID(_potionID);
    return nullptr;
}

void InventoryManager::RemoveItem(ItemData* _item)
{
    //TODO 아이템 제거
}

void InventoryManager::ShowInventory()
{
    //아이템 표시
    int size = Inventory.size();
    int capacity = Inventory.capacity();
    cout << "[ 인벤토리 ("<< size << "/" << capacity <<") ]" << endl;

    int i = 1;
    for (auto item : Inventory)
    {
        cout << i++ << ". ";
        item->PrintInfo();
    }
}

InventoryManager::~InventoryManager()
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
