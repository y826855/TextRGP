#include "AlchemyManager.h"
#include "../Inventroy/ItemManager.h"
#include "Postion/HPPotion.h"
#include "Postion/MPPotion.h"

AlchemyManager::AlchemyManager()
{
    InsertData(new HPPotion());
    InsertData(new MPPotion());

    //scriptable
}

void AlchemyManager::InsertData(PotionBase* potion)
{
    PotionSearchContainer.insert({ potion->GetName(), potion });
    auto requireItems = potion->GetRecipe().GetRequireItems();

    for (auto require : requireItems)
    {
        auto itemName = ItemManager::GetInstance()->GetNameByID(require.ItemID);
        PotionRequireDataContainer[itemName].push_back(potion);
    }
}

void AlchemyManager::ShowAllRecipe()
{
    if (PotionSearchContainer.empty())
    {
        cout << "레시피를 찾지 못했습니다" << endl;
        return;
    }
        
    for (auto it : PotionSearchContainer)
        ShowPotionRecipe(it.second);
}

void AlchemyManager::SearchRecipeByName(string _searchName)
{
    auto it = PotionSearchContainer.find(_searchName);
    if (it != PotionSearchContainer.end()) 
    {
        ShowPotionRecipe(it->second);
        return;
    }
    cout << "레시피를 찾지 못했습니다" << endl;
}

void AlchemyManager::SearchRecipeByItemName(string _itemName)
{
    auto itemIter = PotionRequireDataContainer.find(_itemName);
    if (itemIter != PotionRequireDataContainer.end())
    {
        for (auto item : itemIter->second)
            ShowPotionRecipe(item);
        
        cout << "총" << itemIter->second.size() << "개의 레시피를 찾았습니다." << endl;
        return;
    }
    cout << "레시피를 찾지 못했습니다" << endl;
}

void AlchemyManager::ShowPotionRecipe(PotionBase* potion)
{
    cout << " -> ";
    cout << potion->GetName() << " "; 
    potion->GetRecipe().ShowRequireItem();
    cout << endl;
}

AlchemyManager::~AlchemyManager()
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
