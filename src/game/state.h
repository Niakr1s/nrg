#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <chrono>

#include "eventqueue.h"
#include "keybindings.h"
#include "manager.h"

class State {
 protected:
  bool active_ = true;
  Manager &manager_;
  std::shared_ptr<sf::RenderWindow> window_;

  EventQueue event_queue_;

 public:
  State(Manager &manager);
  virtual ~State() {}

  virtual void update(std::chrono::milliseconds) = 0;

  EventQueue &eventQueue();
};

#endif  // STATE_H
