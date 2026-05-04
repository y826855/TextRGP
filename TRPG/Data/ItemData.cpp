#include "ItemData.h"

#include "../Inventroy/ItemManager.h"

RequireItem::RequireItem(EItem _id, int _amount)
{
    ItemID = _id;
    Amount = _amount;
}

void RequireItem::ShowInfo()
{
    auto name = ItemManager::GetInstance()->GetNameByID(ItemID);
    cout << name << " * " << Amount;
}

ItemData::ItemData(string _name, int _price)
{
    Name = _name;
    Price = _price;
}

ItemData& ItemData::operator=(const ItemData& other)
{
    if (this == &other) return *this;
    
    this->Name = other.Name;
    this->Price = other.Price;

    return *this;
}

void ItemData::PrintInfo() const
{
    cout << Name << " (" << Price << "G)" << endl;
}
