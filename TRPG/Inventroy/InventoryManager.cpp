#include "InventoryManager.h"

#include "ItemManager.h"

InventoryManager::InventoryManager()
{
    Inventory.reserve(CHUNK_SIZE);
}

void InventoryManager::AddItem(ItemData* item)
{
    if (Inventory.size() == Inventory.capacity()) // 사이즈 부족하면 추가함
        Inventory.reserve(Inventory.capacity() + CHUNK_SIZE);
    
    Inventory.push_back(item);
}

void InventoryManager::AddItem(EItem itemID)
{
    auto item = ItemManager::GetInstance()->GetItemByID(itemID);
    if (item == nullptr) return;
    AddItem(item);
}

void InventoryManager::RemoveItem(ItemData* item)
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
