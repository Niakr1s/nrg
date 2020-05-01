#include "fixturefactory.h"

namespace graphics {

b2FixtureDef FixtureFactory::createPlayerFixture(float x, float y) {
  b2FixtureDef res;

  b2CircleShape shape;
  shape.m_p = b2Vec2(x, y);
  shape.m_radius = 1.0f;

  res.shape = &shape;
  res.density = 1.0f;
  res.friction = 0.3f;

  return res;
}

}  // namespace graphics
