#ifndef FIXTUREFACTORY_H
#define FIXTUREFACTORY_H

#include <box2d/box2d.h>

namespace graphics {

class FixtureFactory {
 public:
  static b2FixtureDef createPlayerFixture(float x, float y);
};

}  // namespace graphics

#endif  // FIXTUREFACTORY_H
