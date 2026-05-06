#pragma once
#include "../Monster/MonsterBase.h"

//데이터와 객체 분리
//몬스터 데이터만 따로 분리해서, 표시할때는 데이터만, 전투할때는 실제로 생성하는 형태로 하면 더 좋을듯.
class Floor
{
    MonsterBase* Monster;
    int FloorIndex;
public:

    Floor(MonsterBase* _monster, int _floorIndex)
        : Monster(_monster), FloorIndex(_floorIndex){}

    void ShowFloorInfo(int _canTryFloor) const;
    
    int GetFloorIndex() const { return FloorIndex; }
    MonsterBase* GetMonster() const { return Monster; }
    
    ~Floor() { delete Monster; };
};
