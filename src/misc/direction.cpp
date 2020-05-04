#include "direction.h"

#include <cmath>

#include "constants.h"

namespace misc {

std::optional<float> Direction::angle() const { return angle_; }

Direction::Direction() {}

Direction::Direction(float angle) : angle_(angle) {}

Direction::Direction(float dx, float dy) { setDirectionVector(dx, dy); }

Direction::Direction(const std::pair<float, float> &dir) {
  setDirectionVector(dir.first, dir.second);
}

float Direction::dx(float speed) const {
  return angle_.has_value() ? (speed * std::cos(angle_.value())) : 0;
}

float Direction::dy(float speed) const {
  return angle_.has_value() ? (-speed * std::sin(angle_.value())) : 0;
}

b2Vec2 Direction::vectorVelocity(float speed) const {
  return {dx(speed), dy(speed)};
}

void Direction::setDirectionVector(float dx, float dy) {
  if (dx == 0.f && dy == 0.f) {
    angle_ = std::nullopt;
    return;
  }

  angle_ = std::atan(std::fabs(dy) / std::fabs(dx));

  if (dx < 0 && dy <= 0) {  // II
    angle_ = constants::PI - angle_.value();
  } else if (dx <= 0 && dy > 0) {  // III
    angle_ = -constants::PI + angle_.value();
  } else if (dx > 0 && dy >= 0) {  // IV
    angle_ = -angle_.value();
  }
}

void Direction::setDirectionVector(const std::pair<float, float> &dir) {
  setDirectionVector(dir.first, dir.second);
}

}  // namespace misc
