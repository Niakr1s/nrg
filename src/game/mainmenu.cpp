#include "mainmenu.h"

#include <SFML/Graphics.hpp>
#include <boost/signals2.hpp>
#include <chrono>
#include <functional>
#include <iostream>

using namespace std::chrono_literals;

MainMenu::MainMenu(Manager& manager) : State(manager) {
  auto startGameBtn = std::make_shared<Button>("Start game", manager_);
  startGameBtn->setPosition(300, 200);

  auto continueBtn = std::make_shared<Button>("Continue", manager_);
  continueBtn->setPosition(300, 300);

  auto exitBtn = std::make_shared<Button>("Exit", manager_);
  exitBtn->setPosition(300, 400);
  exitBtn->clicked.connect([&] { manager_.stopMainLoop(); });

  buttons_.push_back(startGameBtn);
  buttons_.push_back(continueBtn);
  buttons_.push_back(exitBtn);
}

void MainMenu::processEventQueue() {
  std::unique_lock<std::mutex>(event_queue_.mutex);
  while (!event_queue_.queue.empty()) {
    auto event = event_queue_.queue.front();

    if (event.type == sf::Event::MouseButtonPressed) {
      for (auto& btn : buttons_) {
        auto rect = btn->text().getGlobalBounds();
        if (rect.contains(event.mouseButton.x, event.mouseButton.y)) {
          btn->clicked();
        }
      }
    } else if (event.type == sf::Event::MouseMoved) {
      for (auto& btn : buttons_) {
        auto rect = btn->text().getGlobalBounds();
        btn->setSelected(rect.contains(event.mouseMove.x, event.mouseMove.y));
      }
    } else if (event.type == sf::Event::KeyPressed) {
    }

    event_queue_.queue.pop();
  }
}

void MainMenu::update(std::chrono::milliseconds) {
  processEventQueue();

  for (auto& btn : buttons_) {
    btn->draw(*window_);
  }
}
