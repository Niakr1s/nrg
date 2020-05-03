#include "levelloader.h"

#include "components.h"
#include "constants.h"

namespace level {

level::LevelLoader::LevelLoader() {}

std::shared_ptr<Level> level::LevelLoader::loadNextLevel() {
  return doLoadNextLevel();
}

std::shared_ptr<level::Level> level::TmpLevelLoader::doLoadNextLevel() {
  auto level = std::make_shared<Level>(250, 200);

  level->spawnPlayer(125, 20);
  level->spawnEnemy(125, 170);

  return level;
}

}  // namespace level
