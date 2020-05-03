#ifndef SYSTEM_H
#define SYSTEM_H

#include <chrono>
#include <entt/entt.hpp>

#include "level.h"

using namespace std::chrono_literals;

class System {
 protected:
  std::shared_ptr<level::Level> level_;

 public:
  virtual ~System() = default;

  virtual void update(const std::chrono::milliseconds& diff) = 0;

  virtual void setLevel(std::shared_ptr<level::Level> level);

  void update() { return update(0ms); }
};

#endif  // SYSTEM_H
