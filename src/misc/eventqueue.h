#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <SFML/Window/Event.hpp>
#include <mutex>
#include <queue>

class EventQueue {
 public:
  std::queue<sf::Event> queue;
  std::mutex mutex;
};

#endif  // EVENTQUEUE_H
