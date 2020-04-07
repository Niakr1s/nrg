#ifndef MAINMENU_H
#define MAINMENU_H

#include <memory>
#include <vector>

#include "state.h"
#include "widgets/button.h"

class MainMenu : public State {
  std::vector<std::shared_ptr<Button>> buttons_;

  void processEventQueue();

 public:
  MainMenu(Manager& manager);

  void update(const std::chrono::milliseconds& diff) override;
};

#endif  // MAINMENU_H
