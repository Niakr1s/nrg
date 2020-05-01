#ifndef BODY_H
#define BODY_H

#include <box2d/box2d.h>

namespace components {

class Body {
  b2Body* body_;
  b2World& world_;

 public:
  Body(b2World& world);

  void createFixture(b2FixtureDef* fixture);
  void destroy();
};

}  // namespace components

#endif  // BODY_H
