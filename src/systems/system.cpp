#include "system.h"

void System::setLevel(std::shared_ptr<level::Level> level) {
  level_ = level;
  onNewLevel();
}

void System::onNewLevel() {}
