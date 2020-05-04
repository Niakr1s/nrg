#include "weapon.h"

namespace components {

float Weapon::angle() const { return angle_; }

void Weapon::setAngleVelocity(float angle_velocity) {
  angle_velocity_ = angle_velocity;
}

void Weapon::updateAngle(const std::chrono::milliseconds &diff) {
  angle_ += angle_velocity_ * diff.count() / 1000.f;
  for (auto &gun : guns) {
    gun->updateAngle(angle_);
  }
}

}  // namespace components
