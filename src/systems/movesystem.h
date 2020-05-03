#ifndef MOVESYSTEM_H
#define MOVESYSTEM_H

#include <box2d/box2d.h>

#include "level.h"
#include "systems/system.h"

namespace systems {

class MoveSystem : public System {
 public:
  MoveSystem();

  void update(const std::chrono::milliseconds &diff) override;
};

}  // namespace systems

#endif  // MOVESYSTEM_H
