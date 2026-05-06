#include "MPPotion.h"
#include "../../Player/PlayerManager.h"

void MPPotion::Use()
{
    auto player = PlayerManager::GetInstance()->GetPlayer();
    cout << "MP회복 " << player->GetMP() << " -> "<< player->GetMP() + increaseAmount << " (MP 포션 차감:";
        
    player->AddMP(increaseAmount);
}
