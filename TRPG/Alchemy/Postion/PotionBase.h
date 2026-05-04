#pragma once
#include <string>
#include <utility>

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
    
    PotionBase(std::string _name, PotionRecipe _requireItems)
        : Name(std::move(_name)), Recipe(std::move(_requireItems)) 
    {
    }

    virtual std::string GetName() { return Name; }
    virtual PotionRecipe GetRecipe() { return Recipe; }

    virtual void Use() = 0;

    virtual ~PotionBase(){}
};
