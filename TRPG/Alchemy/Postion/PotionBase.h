#pragma once
#include <string>

#include "../../Data/ItemData.h"
#include "../../Data/PotionRecipe.h"

using namespace std;

class PotionBase
{
    
protected:
    std::string Name;
    //PotionRecipe* Recipe;
    PotionRecipe Recipe;
    
public:

    // 생성자에서 자식으로부터 데이터를 직접 받음
    PotionBase(std::string _name, EItem* _requireItems)
        : Name(_name), Recipe(_requireItems) 
    {
    }

    virtual std::string GetName() { return Name; }
    virtual PotionRecipe GetRecipe() { return Recipe; }

    virtual void Use() = 0;

    virtual ~PotionBase(){}
};
