#ifndef LEVEL_H
#define LEVEL_H

#include <box2d/box2d.h>

#include <entt/entt.hpp>

namespace level {

class Level {
  b2World world_;
  entt::registry registry_;

 public:
  Level();

  b2World& world();
  entt::registry& registry();

  void makeFrame(int width, int height);
  void spawnPlayer(int x, int y);
  void spawnEnemy(int x, int y);

 private:
  // x and y = center
  // w and h = full width and height
  void makeGroundBody(float x, float y, float w, float h);
};

}  // namespace level

#endif  // LEVEL_H
