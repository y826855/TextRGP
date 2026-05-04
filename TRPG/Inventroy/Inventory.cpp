#include "Inventory.h"

#include "InventoryManager.h"

void Inventory::Enter()
{
    InventoryManager::GetInstance()->ShowInventory();
}
