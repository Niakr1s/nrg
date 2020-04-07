#ifndef SYSTEM_H
#define SYSTEM_H

#include <chrono>
#include <entt/entt.hpp>

using namespace std::chrono_literals;

class System {
 public:
  virtual ~System() = default;

  virtual void update(entt::registry& registry,
                      const std::chrono::milliseconds& diff) = 0;

  void update(entt::registry& registry) { return update(registry, 0ms); }
};

#endif  // SYSTEM_H
