#pragma once
#include "ItemData.h"

struct MonsterData
{
public:
    string Name;
    
    int HP;
    int Atk;
    int Def;
    
    RequireItem DropItem; // string 으로 처리하지 않음

    MonsterData(const string& _name, int _hp, int _atk, int _def, const RequireItem _dropItem)
        : Name(_name), HP(_hp), Atk(_atk), Def(_def), DropItem(_dropItem)
    {
        
    }
};
