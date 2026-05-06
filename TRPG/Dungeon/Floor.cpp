#include "Floor.h"

void Floor::ShowFloorInfo(int _canTryFloor) const
{
    cout << FloorIndex << "번 방 : " << Monster->GetName()
    << "(HP " << Monster->GetHP() << ", "
    << "ATK " << Monster->GetAtk() << ") -> ";

    if (_canTryFloor > FloorIndex)
        cout << "클리어!" << endl;
    else if (_canTryFloor == FloorIndex)
        cout << "도전 가능!"<< endl;
    else
        cout << "도전 불가.."<< endl;
}
