#include "gun.h"

#include <iostream>

#include "components.h"
#include "misc/direction.h"

namespace armory {

float Gun::absoluteAngle() const { return angle_ + angle_diff_; }

bool Gun::isActive() const { return active_; }

void Gun::setActive(bool active) { active_ = active; }

Gun::Gun(float angle_diff, long long cooldown_ms, bool automatic)
    : angle_diff_(angle_diff),
      automatic_(automatic),
      cooldown_ms_(cooldown_ms) {}

Gun::~Gun() {}

void Gun::spawnBullet(level::Level &level, entt::entity parent,
                      const std::chrono::milliseconds &diff) {
  cooldodwn_passed_ms += diff.count();
  if (cooldodwn_passed_ms < cooldown_ms_) return;

  if (!(automatic_ || spawn_ensured_)) return;

  cooldodwn_passed_ms = 0;
  spawn_ensured_ = false;

  return doSpawnBullet(level, parent);
}

void Gun::setSpawnOnNextCooldown(bool flag) { spawn_ensured_ = flag; }

void Gun::updateAngle(float angle) { angle_ = angle; }

}  // namespace armory
