#ifndef GAME_H
#define GAME_H

#include <entt/entt.hpp>
#include <memory>
#include <vector>

#include "state.h"
#include "systems.h"
#include "widgets/button.h"

class Game : public State {
  entt::registry registry_;
  std::vector<std::shared_ptr<System>> systems_;

  void processEventQueue();

  Button time_text_;
  long long time_ = 0;

 public:
  Game(Manager& manager);

  void spawnPlayer(float x, float y);

  void update(const std::chrono::milliseconds& diff) override;
};

#endif  // GAME_H
