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

  const int cooldown_ms_;
  int cooldodwn_passed_ms = 0;

 public:
  Gun(float angle_diff, int cooldown_ms);
  virtual ~Gun();

  void spawnBullet(level::Level& level, entt::entity parent,
                   const std::chrono::milliseconds& diff);

  void updateAngle(float absoluteAngle);
  float absoluteAngle() const;

 protected:
  virtual void doSpawnBullet(level::Level& level, entt::entity parent) = 0;
};

}  // namespace armory

#endif  // GUN_H
