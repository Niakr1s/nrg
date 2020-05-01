#ifndef GAME_H
#define GAME_H

#include <box2d/box2d.h>

#include <entt/entt.hpp>
#include <memory>
#include <vector>

#include "keybindings.h"
#include "state.h"
#include "systems.h"
#include "widgets/button.h"

namespace states {

class Game : public State {
  entt::registry registry_;
  std::vector<std::shared_ptr<System>> systems_;
  KeyBindings keybindings_;
  b2World world_;

 public:
  Game(Manager& manager);

  void spawnPlayer(float x, float y);

  void update(const std::chrono::milliseconds& diff) override;

  const KeyBindings& keybindings() const;
};

}  // namespace states

#endif  // GAME_H
