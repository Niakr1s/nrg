#include "weaponsystem.h"

#include "components.h"

namespace systems {

WeaponSystem::WeaponSystem() {}

void WeaponSystem::update(const std::chrono::milliseconds& diff) {
  level_->registry().view<components::Weapon>().each(
      [&](entt::entity entity, components::Weapon& weapon) {
        for (auto& gun : weapon.guns) {
          gun->spawnBullet(*level_, entity, diff);
        }
      });
}

}  // namespace systems
