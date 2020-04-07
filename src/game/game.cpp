#include "game.h"

#include <SFML/Graphics.hpp>
#include <boost/signals2.hpp>
#include <chrono>
#include <functional>
#include <iostream>

#include "mainmenu/mainmenu.h"

using namespace std::chrono_literals;

Game::Game(Manager& manager) : State(manager) {}

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
  time_ += diff.count();
  time_text_.setText(std::to_string(time_ / 1000) + "s");
  time_text_.draw(*window_);

  processEventQueue();
}
