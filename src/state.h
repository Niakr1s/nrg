#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <chrono>

#include "manager.h"
#include "misc/eventqueue.h"

class State {
 protected:
  bool active_ = true;
  Manager &manager_;
  std::shared_ptr<sf::RenderWindow> window_;

  EventQueue event_queue_;

 public:
  State(Manager &manager);
  virtual ~State() {}

  // you should update your physics, animations and draw it onto window_
  // don't call window_.display()
  virtual void update(const std::chrono::milliseconds &diff) = 0;

  EventQueue &eventQueue();
  Manager &manager();
};

#endif  // STATE_H
