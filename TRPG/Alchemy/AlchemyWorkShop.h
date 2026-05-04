#pragma once

#include <unordered_map>
#include "Postion/PotionBase.h"
#include "../Singleton.h"

using namespace std;

class AlchemyWorkShop : public Singleton<AlchemyWorkShop> 
{
    friend class Singleton<AlchemyWorkShop>;
    
    //unordered_map<EPotion, PotionBase*> PotionContainer;
    unordered_map<string, PotionBase*> PotionSearchContainer;
    unordered_map<string, vector<PotionBase*>> PotionRequireDataContainer;            
    
public:
    AlchemyWorkShop();

    void InsertData(PotionBase* potion);

    //return 포션 3개
    void SearchPotionRecipe(string _searchName);

    void MakePotion()
    {
        //TODO 만들면 데이터 소모 & 플레이어에게 포션 추가
        //인벤토리 매니저 접근 & 사용
        //플레이어 데이터 접근 & 사용
    }

    ~AlchemyWorkShop() override;
};
