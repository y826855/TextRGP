#include "AlchemyWorkShop.h"

#include "AlchemyManager.h"
#include "../InputHelper.h"

void AlchemyWorkShop::ShowMenu()
{
    cout << "=== 포션 제작소 ===" << endl
    << "1. 전체 레시피 보기" << endl
    << "2. 포션 이름으로 검색" << endl
    << "3. 재료로 검색" << endl
    << "0. 돌아가기" << endl << endl;
}

void AlchemyWorkShop::Enter()
{
    bIsEnter = true;
    string inputName;

    ShowMenu();
    
    while (bIsEnter)
    {
        int selection = InputHelper::GetValidInput<int>("선택: ", 0, 4);
        switch (selection)
        {
        case 1:
            AlchemyManager::GetInstance()->ShowAllRecipe();
            break;
        case 2:
            inputName = InputHelper::GetValidName("검색할 포션 이름: ", 1, 50);
            AlchemyManager::GetInstance()->SearchRecipeByName(inputName);
            break;
        case 3:
            inputName = InputHelper::GetValidName("검색할 재료: ", 1, 50);
            AlchemyManager::GetInstance()->SearchRecipeByItemName(inputName);
            break;
        case 0: Quit();
        }
    }
}

void AlchemyWorkShop::Quit()
{
    bIsEnter = false;
}
