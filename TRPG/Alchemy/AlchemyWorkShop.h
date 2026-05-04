#pragma once

#include <map>

#include "Postion/HPPotion.h"
#include "Postion/MPPotion.h"
#include "Postion/PotionBase.h"

using namespace std;

class AlchemyWorkShop
{
    map<string, PotionBase*> PotionRecipeContainer;
    
public:
    AlchemyWorkShop()
    {
        InsertData(new HPPotion());
        InsertData(new MPPotion());
    }

    void InsertData(PotionBase* potion)
    {
        PotionRecipeContainer.insert({ potion->GetName(), potion });
    }

    void SearchPotionRecipe(string _potionName)
    {
        auto it = PotionRecipeContainer.find(_potionName);
        if (it != PotionRecipeContainer.end()) 
        {
            //찾음
        }
        else
        {
            //없음
        }
    }

    void MakePotion()
    {
        //TODO 만들면 데이터 소모 & 플레이어에게 포션 추가
        //인벤토리 매니저 접근 & 사용
        //플레이어 데이터 접근 & 사용
    }

    ~AlchemyWorkShop()
    {
        for (auto& pair : PotionRecipeContainer)
        {
            if (pair.second != nullptr)
            {
                delete pair.second;
                pair.second = nullptr; // 안전을 위해 nullptr 처리
            }
        }
        PotionRecipeContainer.clear();
    }
};
