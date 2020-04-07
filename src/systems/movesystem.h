#ifndef MOVESYSTEM_H
#define MOVESYSTEM_H

#include "systems/system.h"

namespace systems {

class MoveSystem : public System {
 public:
  MoveSystem();

  void update(entt::registry &registry,
              const std::chrono::milliseconds &diff) override;
};

}  // namespace systems

#endif  // MOVESYSTEM_H
