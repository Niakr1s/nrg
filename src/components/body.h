#ifndef BODY_H
#define BODY_H

#include <box2d/box2d.h>

#include <vector>

namespace components {

struct Body {
  b2Body* body;
};

}  // namespace components

#endif  // BODY_H
