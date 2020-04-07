#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "state.h"
#include "widgets/button.h"

class Game : public State {
  void processEventQueue();

  Button time_text_;
  long long time_ = 0;

 public:
  Game(Manager& manager);

  void update(const std::chrono::milliseconds& diff) override;
};

#endif  // GAME_H
