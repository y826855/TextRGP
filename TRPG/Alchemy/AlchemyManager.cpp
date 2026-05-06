#include "AlchemyManager.h"

#include "../Inventroy/InventoryManager.h"
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
    PotionContainer.insert({potion->GetID(), potion});
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

PotionBase* AlchemyManager::GetPotionByID(EPotion potionID)
{
    auto iter = PotionContainer.find(potionID);
    if (iter != PotionContainer.end())
        return iter->second;
    return nullptr;
}

void AlchemyManager::RefillPotion()
{
    if (PotionHaveCount <= 0)
    {
        cout << "HP포션 지급 실패: 재고 없음!" << endl;
        return;
    }

    cout << "HP 포션 재고: " << PotionHaveCount << endl; 
    cout << "HP포션 지급  (재고: " << --PotionHaveCount << ")" << endl;
    InventoryManager::GetInstance()->AddPotion(EPotion::EHPPotion, 1);
}

void AlchemyManager::ReturnEmptyPotion()
{
    if (PotionUseCount <= 0)
    {
        cout << "공병 없음! " << endl;
        return;
    }

    cout << "공병 " << PotionUseCount << "개 반환    (재고: " << PotionUseCount + PotionHaveCount << ")" << endl;
    PotionHaveCount += PotionUseCount;
    PotionUseCount = 0;
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
