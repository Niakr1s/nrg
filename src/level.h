#ifndef LEVEL_H
#define LEVEL_H

#include <box2d/box2d.h>

#include <entt/entt.hpp>

namespace level {

class Level {
  b2World world_;
  entt::registry registry_;
  int width_, height_;

 public:
  Level(int width, int height);

  b2World& world();
  entt::registry& registry();

  void spawnPlayer(int x, int y);
  void spawnEnemy(int x, int y);

  int width() const;
  int height() const;

 private:
  // x and y = center
  // w and h = full width and height
  void makeGroundBody(float x, float y, float w, float h);

  b2Body* makeCircle(int x, int y, int radius, bool dynamic);

  void makeFrame(int width, int height);
};

}  // namespace level

#endif  // LEVEL_H
