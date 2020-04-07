#include "manager.h"

#include <iostream>
#include <thread>

#include "game/game.h"
#include "mainmenu/mainmenu.h"

using namespace std::chrono_literals;

Manager::Manager() {}

std::shared_ptr<State> Manager::state() const { return state_; }

void Manager::startNewGame() { pending_state_ = std::make_shared<Game>(*this); }

void Manager::pauseGame() {
  paused_game_ = state_;
  pending_state_ = std::make_shared<MainMenu>(*this);
}

void Manager::resumeGame() {
  pending_state_ = paused_game_;
  paused_game_ = nullptr;
}

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
          event.type == sf::Event::KeyPressed ||
          event.type == sf::Event::KeyReleased) {
        std::unique_lock<std::mutex> lk(state_->eventQueue().mutex);
        state_->eventQueue().queue.push(event);
      }
    }
  });
}

void Manager::startMainLoop() {
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

    if (pending_state_) {
      state_ = pending_state_;
      pending_state_ = nullptr;
    }

    std::this_thread::sleep_for(1ms);
  }
}

void Manager::stopMainLoop() {
  active_ = false;
  key_listener_thread_.join();
}
