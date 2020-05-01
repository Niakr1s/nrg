#ifndef MAINMENU_H
#define MAINMENU_H

#include <memory>
#include <vector>

#include "state.h"
#include "widgets/button.h"

namespace states {

class MainMenu : public State {
  std::vector<std::shared_ptr<widgets::Button>> buttons_;

  void processEventQueue();

 public:
  MainMenu(Manager& manager);

  void update(const std::chrono::milliseconds& diff) override;
};

}  // namespace states

#endif  // MAINMENU_H
