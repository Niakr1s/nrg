#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include <box2d/box2d.h>

#include <entt/entt.hpp>

#include "level.h"

namespace level {

class LevelLoader {
 public:
  LevelLoader();
  virtual ~LevelLoader() {}

  std::shared_ptr<Level> loadNextLevel();

 protected:
  virtual std::shared_ptr<Level> doLoadNextLevel() = 0;
};

class TmpLevelLoader : public LevelLoader {
 public:
  using LevelLoader::LevelLoader;

  std::shared_ptr<Level> doLoadNextLevel() override;
};

}  // namespace level

#endif  // LEVELLOADER_H
