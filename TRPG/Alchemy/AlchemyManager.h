#pragma once

#include <unordered_map>
#include "Postion/PotionBase.h"
#include "../Singleton.h"

using namespace std;

class AlchemyManager : public Singleton<AlchemyManager> 
{
    friend class Singleton<AlchemyManager>;
    
    unordered_map<EPotion, PotionBase*> PotionContainer;
    unordered_map<string, PotionBase*> PotionSearchContainer;
    unordered_map<string, vector<PotionBase*>> PotionRequireDataContainer;            

    void InsertData(PotionBase* potion);
    void ShowPotionRecipe(PotionBase* potion);

    int PotionHaveCount = 3;
    int PotionUseCount = 0;
    
public:
    AlchemyManager();

    void ShowAllRecipe();

    //return 포션 3개
    void SearchRecipeByName(string _searchName);
    void SearchRecipeByItemName(string _itemName);
    PotionBase* GetPotionByID(EPotion potionID);

    void RefillPotion();
    void ReturnEmptyPotion();
    void AddUseCount() { PotionUseCount++; }

    void MakePotion()
    {
        //TODO 만들면 데이터 소모 & 플레이어에게 포션 추가
        //인벤토리 매니저 접근 & 사용
        //플레이어 데이터 접근 & 사용
    }

    ~AlchemyManager() override;
};
