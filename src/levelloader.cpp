#include "levelloader.h"

#include "components.h"
#include "constants.h"

namespace level {

level::LevelLoader::LevelLoader() {}

std::shared_ptr<Level> level::LevelLoader::loadNextLevel() {
  return doLoadNextLevel();
}

std::shared_ptr<level::Level> level::TmpLevelLoader::doLoadNextLevel() {
  auto level = std::make_shared<Level>();

  level->makeFrame(40, 40);
  level->spawnPlayer(20, 20);

  return level;
}

}  // namespace level
