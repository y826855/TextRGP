#pragma once
#include <string>
#include <utility>

#include "../../Data/ItemData.h"
#include "../../Data/PotionRecipe.h"

using namespace std;

class PotionBase
{
    
protected:
    string Name;
    PotionRecipe Recipe;
    EPotion PotionID;
    
public:
    
    PotionBase(string _name, PotionRecipe _requireItems, EPotion _potionID)
    : Name(move(_name)),
    Recipe(move(_requireItems)),
    PotionID(move(_potionID))
    {
    }

    virtual string GetName() { return Name; }
    virtual EPotion GetID() { return PotionID; }
    virtual PotionRecipe GetRecipe() { return Recipe; }

    virtual void Use() = 0;

    virtual ~PotionBase() = default;
};
