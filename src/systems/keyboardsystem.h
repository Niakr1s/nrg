#ifndef KEYBOARDSYSTEM_H
#define KEYBOARDSYSTEM_H

#include "system.h"

namespace states {
class Game;
}

namespace systems {

class KeyboardSystem : public System {
  states::Game& game_;

 public:
  KeyboardSystem(states::Game& game);

  void update(const std::chrono::milliseconds& diff) override;
};

}  // namespace systems

#endif  // KEYBOARDSYSTEM_H
