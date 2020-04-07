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

Game::Game(Manager& manager) : State(manager) {
  systems_.push_back(std::make_shared<MoveSystem>());
  systems_.push_back(std::make_shared<RenderSystem>(*window_));

  spawnPlayer(400, 400);
}

void Game::spawnPlayer(float x, float y) {
  auto [entity, player, pos, radius, velocity] =
      registry_.create<components::Player, components::Position,
                       components::Radius, components::Velocity>();
  pos.x = x;
  pos.y = y;
  radius.r = 10.;
  velocity.dx_per_sec = 10;
  velocity.dy_per_sec = 10;
}

void Game::processEventQueue() {
  std::unique_lock<std::mutex>(event_queue_.mutex);
  while (!event_queue_.queue.empty()) {
    auto event = event_queue_.queue.front();

    if (event.type == sf::Event::MouseButtonPressed) {
    } else if (event.type == sf::Event::MouseMoved) {
    } else if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Escape) {
        manager_.pauseGame();
      }
    }

    event_queue_.queue.pop();
  }
}

void Game::update(const std::chrono::milliseconds& diff) {
  for (auto& system : systems_) {
    system->update(registry_, diff);
  }

  processEventQueue();
}
