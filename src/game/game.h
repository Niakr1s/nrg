#ifndef GAME_H
#define GAME_H

#include <box2d/box2d.h>

#include <entt/entt.hpp>
#include <memory>
#include <vector>

#include "keybindings.h"
#include "level.h"
#include "levelloader.h"
#include "state.h"
#include "systems.h"
#include "widgets/button.h"

namespace states {

class Game : public State {
  std::vector<std::shared_ptr<System>> systems_;
  KeyBindings keybindings_;
  std::shared_ptr<level::LevelLoader> level_loader_;
  std::shared_ptr<level::Level> level_;

 public:
  Game(Manager& manager);

  void update(const std::chrono::milliseconds& diff) override;

  bool loadNextLevel();

  const KeyBindings& keybindings() const;
};

}  // namespace states

#endif  // GAME_H
