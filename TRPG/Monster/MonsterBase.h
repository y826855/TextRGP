#pragma once
#include "../IHitable.h"
#include "../Data/MonsterData.h"

class MonsterBase : IHitable
{
    MonsterData* Data;
public:
    MonsterBase(MonsterData* _data) : Data(_data){}
    
    void OnHit(int damage)
    {
        //TODO 계산식 적용
    }
    
    virtual ~MonsterBase() { delete Data; }
};
