#include "BattleInventory.h"

#include "InventoryManager.h"
#include "ItemManager.h"
#include "../InputHelper.h"
#include "../Alchemy/AlchemyManager.h"

void BattleInventory::Enter()
{
    bIsEnter = true;
    //find consumable

    auto alchemyMgr = AlchemyManager::GetInstance();
    auto invMgr = InventoryManager::GetInstance();
    
    while (bIsEnter)
    {
        auto potions = invMgr->GetHavePotions();
        if (potions.empty()) {
            cout << "사용할 수 있는 포션이 없습니다!" << endl;
            break;
        }
        //사용 가능 포션 표기
        for (int i = 0; i < potions.size(); ++i)
        {
            auto potionName = alchemyMgr->GetPotionByID(potions[i])->GetName() ;
            cout << i + 1 << ". " << potionName << endl;
        }
        cout << "0. 뒤로가기" << endl;

        
        int selection = InputHelper::GetValidInput<int>("선택: ", 0, potions.size());
        if (selection == 0)
            Quit();
        else 
            invMgr->UsePotion(potions[selection - 1]);
    }
}

void BattleInventory::Quit()
{
    bIsEnter = false;
}
