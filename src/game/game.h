#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "state.h"
#include "widgets/button.h"

class Game : public State {
  void processEventQueue();

  long long time_ = 0;

  std::vector<std::shared_ptr<Button>> buttons_;

 public:
  Game(Manager &manager);

  void update(std::chrono::milliseconds ms) override;
};

#endif  // GAME_H
