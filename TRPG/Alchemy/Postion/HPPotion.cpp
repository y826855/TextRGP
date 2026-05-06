#include "HPPotion.h"

#include "../AlchemyManager.h"
#include "../../Player/PlayerManager.h"

void HPPotion::Use()
{
    AlchemyManager::GetInstance()->AddUseCount();

    auto player = PlayerManager::GetInstance()->GetPlayer();
    cout << "HP회복 " << player->GetHP() << " -> "<< player->GetHP() + increaseAmount << " (HP 포션 차감:";
    player->AddHP(increaseAmount);
}
