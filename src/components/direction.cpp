#include "direction.h"

#include <cmath>

std::optional<double> components::Direction::angle() const { return angle_; }

components::Direction::Direction() {}

components::Direction::Direction(double angle) : angle_(angle) {}

components::Direction::Direction(double dx, double dy) { setDirection(dx, dy); }

double components::Direction::dx(double speed) const {
  return angle_.has_value() ? (speed * std::cos(angle_.value())) : 0;
}

double components::Direction::dy(double speed) const {
  return angle_.has_value() ? (-speed * std::sin(angle_.value())) : 0;
}

void components::Direction::setDirection(double dx, double dy) {
  if (dx == 0. && dy == 0.) {
    angle_ = std::nullopt;
    return;
  }

  angle_ = std::atan(std::fabs(dy) / std::fabs(dx));

  if (dx < 0 && dy <= 0) {  // II
    angle_ = PI - angle_.value();
  } else if (dx <= 0 && dy > 0) {  // III
    angle_ = -PI + angle_.value();
  } else if (dx > 0 && dy >= 0) {  // IV
    angle_ = -angle_.value();
  }
}

double components::Direction::PI = 3.1415926535897932385;
