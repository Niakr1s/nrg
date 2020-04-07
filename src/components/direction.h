#ifndef DIRECTION_H
#define DIRECTION_H

#include <optional>

namespace components {

class Direction {
  std::optional<double> angle_ = 0.;

 public:
  static double PI;

  Direction();
  Direction(double angle);
  Direction(double dx, double dy);

  double dx(double speed) const;
  double dy(double speed) const;

  void setDirection(double dx, double dy);
  std::optional<double> angle() const;
};

}  // namespace components

#endif  // DIRECTION_H
