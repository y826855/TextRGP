#include "AlchemyWorkShop.h"
#include "../Inventroy/ItemManager.h"
#include "Postion/HPPotion.h"
#include "Postion/MPPotion.h"

AlchemyWorkShop::AlchemyWorkShop()
{
    InsertData(new HPPotion());
    InsertData(new MPPotion());

    //scriptable
}

void AlchemyWorkShop::InsertData(PotionBase* potion)
{
    PotionSearchContainer.insert({ potion->GetName(), potion });
    auto requireItems = potion->GetRecipe().GetRequireItems();

    for (auto require : requireItems)
    {
        auto itemName = ItemManager::GetInstance()->GetNameByID(require.ItemID);
        PotionRequireDataContainer[itemName].push_back(potion);
    }
}

void AlchemyWorkShop::SearchPotionRecipe(string _searchName)
{
    //포션 이름으로 찾기
    auto potionIter = PotionSearchContainer.find(_searchName);
    if (potionIter != PotionSearchContainer.end()) 
    {
        cout << " -> ";
        cout << potionIter->second->GetName() << " ";
        potionIter->second->GetRecipe().ShowRequireItem();
        cout << endl;
        return;
    }

    //재료 이름으로 찾기
    auto itemIter = PotionRequireDataContainer.find(_searchName);
    if (itemIter != PotionRequireDataContainer.end())
    {
        for (auto item : itemIter->second)
        {
            cout << " -> ";
            cout << item->GetName() << " "; 
            item->GetRecipe().ShowRequireItem();
            cout << endl;
        }
    }
}

AlchemyWorkShop::~AlchemyWorkShop()
{
    for (auto& pair : PotionSearchContainer)
    {
        if (pair.second != nullptr)
        {
            delete pair.second;
            pair.second = nullptr; // 안전을 위해 nullptr 처리
        }
    }
    PotionSearchContainer.clear();
}
