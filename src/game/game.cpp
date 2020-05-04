#include "game.h"

#include <SFML/Graphics.hpp>
#include <boost/signals2.hpp>
#include <chrono>
#include <functional>
#include <iostream>

#include "components.h"
#include "mainmenu/mainmenu.h"
#include "systems.h"

using namespace std::chrono_literals;

namespace states {

Game::Game(Manager& manager)
    : State(manager), keybindings_(KeyBindings::defaultKeyBindings()) {
  systems_ = {std::make_shared<systems::MoveSystem>(),
              std::make_shared<systems::KeyboardSystem>(*this),
              std::make_shared<systems::WeaponSystem>(),
              std::make_shared<systems::RenderSystem>(*window_)};

  level_loader_ = std::make_shared<level::TmpLevelLoader>();
}

void Game::update(const std::chrono::milliseconds& diff) {
  if (!level_) return;

  for (auto& system : systems_) {
    system->update(diff);
  }
}

bool Game::loadNextLevel() {
  level_ = level_loader_->loadNextLevel();

  for (auto& s : systems_) {
    s->setLevel(level_);
  }

  return level_ != nullptr;
}

const KeyBindings& Game::keybindings() const { return keybindings_; }

}  // namespace states
