#ifndef GUN_H
#define GUN_H

#include <chrono>
#include <memory>

#include "level.h"

namespace armory {

class Gun {
 protected:
  // in radians, diff between main direction of a weapon and gun
  float angle_ = 0., angle_diff_;

  bool active_ = true, automatic_, spawn_ensured_ = false;

  const long long cooldown_ms_;
  long long cooldodwn_passed_ms = 0;

  bool force_spawn_ = false;

 public:
  Gun(float angle_diff, long long cooldown_ms, bool automatic = true);
  virtual ~Gun();

  void spawnBullet(level::Level& level, entt::entity parent,
                   const std::chrono::milliseconds& diff);
  void setSpawnOnNextCooldown(bool flag);

  void updateAngle(float absoluteAngle);
  float absoluteAngle() const;

  bool isActive() const;
  void setActive(bool isActive);

 protected:
  virtual void doSpawnBullet(level::Level& level, entt::entity parent) = 0;
};

}  // namespace armory

#endif  // GUN_H
