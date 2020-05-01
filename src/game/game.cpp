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

Game::Game(Manager& manager)
    : State(manager),
      keybindings_(KeyBindings::defaultKeyBindings()),
      world_(b2Vec2(0.0f, 0.0f)) {
  systems_ = {std::make_shared<systems::MoveSystem>(world_),
              std::make_shared<systems::KeyboardSystem>(*this),
              std::make_shared<systems::RenderSystem>(*window_)};

  spawnPlayer(100, 100);
}

void Game::spawnPlayer(float x, float y) {
  auto [entity, player, body] =
      registry_.create<components::Player, components::Body>();
  body = components::Body::createPlayerBody(x, y, world_);
}

void Game::update(const std::chrono::milliseconds& diff) {
  for (auto& system : systems_) {
    system->update(registry_, diff);
  }
}

const KeyBindings& Game::keybindings() const { return keybindings_; }
