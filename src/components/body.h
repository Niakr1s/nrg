#ifndef BODY_H
#define BODY_H

#include <box2d/box2d.h>

namespace components {

struct Body {
  b2Body* body;

  static Body createPlayerBody(float x, float y, b2World& world);
};

}  // namespace components

#endif  // BODY_H
