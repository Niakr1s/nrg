#ifndef DIRECTION_H
#define DIRECTION_H

#include <optional>

class Direction {
  std::optional<float> angle_ = std::nullopt;

 public:
  Direction();
  Direction(float angle);
  Direction(float dx, float dy);
  Direction(const std::pair<float, float>& dir);

  float dx(float speed) const;
  float dy(float speed) const;

  void setDirectionVector(float dx, float dy);
  void setDirectionVector(const std::pair<float, float>& dir);
  std::optional<float> angle() const;
};

#endif  // DIRECTION_H
