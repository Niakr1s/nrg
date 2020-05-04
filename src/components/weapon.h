#ifndef WEAPON_H
#define WEAPON_H

#include <chrono>
#include <vector>

#include "armory/gun.h"

namespace components {

struct Weapon {
 private:
  float angle_ = 0.f;
  float angle_velocity_ = 0.f;

 public:
  std::vector<std::shared_ptr<armory::Gun>> guns;

  void setAngleVelocity(float angle_velocity);
  void updateAngle(const std::chrono::milliseconds& diff);
  float angle() const;
};

}  // namespace components

#endif  // WEAPON_H
