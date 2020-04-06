#ifndef MAINMENU_H
#define MAINMENU_H

#include <memory>
#include <vector>

#include "button.h"
#include "state.h"

class MainMenu : public State {
  std::vector<std::shared_ptr<Button>> buttons_;

  void processEventQueue();

 public:
  MainMenu(Manager &manager);

  void update(std::chrono::milliseconds) override;
};

#endif  // MAINMENU_H
