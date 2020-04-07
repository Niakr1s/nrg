#include "game.h"

#include <SFML/Graphics.hpp>
#include <boost/signals2.hpp>
#include <chrono>
#include <functional>
#include <iostream>

#include "components.h"
#include "mainmenu/mainmenu.h"
#include "systems/rendersystem.h"

using namespace std::chrono_literals;

Game::Game(Manager& manager) : State(manager) {
  systems_.push_back(std::make_shared<RenderSystem>(*window_));
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
