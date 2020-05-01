#ifndef MOVESYSTEM_H
#define MOVESYSTEM_H

#include <box2d/box2d.h>

#include "systems/system.h"

namespace systems {

class MoveSystem : public System {
  b2World &world_;

 public:
  MoveSystem(b2World &world);

  void update(entt::registry &registry,
              const std::chrono::milliseconds &diff) override;
};

}  // namespace systems

#endif  // MOVESYSTEM_H
