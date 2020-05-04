#include "gun.h"

#include <iostream>

#include "components.h"
#include "misc/direction.h"

namespace armory {

float Gun::absoluteAngle() const { return angle_ + angle_diff_; }

Gun::Gun(float angle_diff, int cooldown_ms)
    : angle_diff_(angle_diff), cooldown_ms_(cooldown_ms) {}

Gun::~Gun() {}

void Gun::spawnBullet(level::Level &level, entt::entity parent,
                      const std::chrono::milliseconds &diff) {
  cooldodwn_passed_ms += diff.count();
  if (cooldodwn_passed_ms < cooldown_ms_) return;

  cooldodwn_passed_ms = 0;
  return doSpawnBullet(level, parent);
}

void Gun::updateAngle(float angle) { angle_ = angle; }

}  // namespace armory
