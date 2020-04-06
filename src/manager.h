#ifndef MANAGER_H
#define MANAGER_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include <memory>
#include <thread>

#include "misc/eventqueue.h"

class State;

class Manager {
  std::shared_ptr<sf::RenderWindow> window_;
  std::shared_ptr<State> state_;
  std::thread key_listener_thread_;
  bool active_ = true;
  std::chrono::system_clock::time_point prev_time_;

 public:
  Manager();

  std::shared_ptr<State> state() const;
  std::shared_ptr<sf::RenderWindow> window() const;

  void startKeyListenerThread();

  void startMainLoop();
  void stopMainLoop();
};

#endif  // MANAGER_H
