#include "weaponsystem.h"

#include <iostream>

#include "components.h"

namespace systems {

WeaponSystem::WeaponSystem() {}

void WeaponSystem::update(const std::chrono::milliseconds& diff) {
  level_->registry().view<components::Player, components::Weapon>().each(
      [&](entt::entity entity, components::Player& player,
          components::Weapon& weapon) {
        if (player.keyboard.fireWasPressed()) {
          player.keyboard.unpressFire();

          for (auto& gun : weapon.guns) {
            if (gun->isActive()) {
              gun->setSpawnOnNextCooldown(true);
            }
          }
        }
      });

  level_->registry().view<components::Weapon>().each(
      [&](entt::entity entity, components::Weapon& weapon) {
        for (auto& gun : weapon.guns) {
          if (gun->isActive()) {
            gun->spawnBullet(*level_, entity, diff);
          }
        }
      });
}

}  // namespace systems
