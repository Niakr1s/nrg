#ifndef KEYBOARDSYSTEM_H
#define KEYBOARDSYSTEM_H

#include "system.h"

class Game;

class KeyboardSystem : public System {
  Game& game_;

 public:
  KeyboardSystem(Game& game);

  void update(entt::registry& registry,
              const std::chrono::milliseconds& diff) override;
};

#endif  // KEYBOARDSYSTEM_H
