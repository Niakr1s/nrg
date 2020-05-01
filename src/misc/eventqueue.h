#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <SFML/Window/Event.hpp>
#include <mutex>
#include <queue>

namespace misc {

class EventQueue {
 public:
  std::queue<sf::Event> queue;
  std::mutex mutex;
};

}  // namespace misc

#endif  // EVENTQUEUE_H
