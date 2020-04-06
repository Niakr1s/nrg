#include "manager.h"

#include <iostream>
#include <thread>

using namespace std::chrono_literals;

#include "mainmenu.h"

Manager::Manager() {}

std::shared_ptr<State> Manager::state() const { return state_; }

std::shared_ptr<sf::RenderWindow> Manager::window() const { return window_; }

void Manager::startKeyListenerThread() {
  key_listener_thread_ = std::thread([&] {
    window_ =
        std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "nrg");
    window_->setActive(false);

    state_ = std::make_shared<MainMenu>(*this);

    sf::Event event;
    while (active_ && window_->isOpen() && window_->waitEvent(event)) {
      if (event.type == sf::Event::Closed) break;

      if (event.type == sf::Event::MouseButtonPressed ||
          event.type == sf::Event::MouseMoved ||
          event.type == sf::Event::KeyPressed) {
      }
    }
  });
}

void Manager::mainLoop() {
  prev_time_ = std::chrono::system_clock::now();

  while (active_) {
    if (!state_ || !window_) continue;

    std::chrono::system_clock::time_point now =
        std::chrono::system_clock::now();
    std::chrono::milliseconds diff =
        std::chrono::duration_cast<std::chrono::milliseconds>(now - prev_time_);
    prev_time_ = now;

    window_->clear();
    state_->update(diff);
    window_->display();

    std::this_thread::sleep_for(10ms);
  }
}
