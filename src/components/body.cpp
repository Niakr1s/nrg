#include "body.h"

namespace components {

Body Body::createPlayerBody(float x, float y, b2World &world) {
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(x, y);

  b2Body *body = world.CreateBody(&bodyDef);

  b2FixtureDef fixture_def;

  b2CircleShape shape;
  shape.m_p = b2Vec2(x, y);
  shape.m_radius = 10.0f;

  fixture_def.shape = &shape;
  fixture_def.density = 1.0f;
  fixture_def.friction = 0.3f;

  body->CreateFixture(&fixture_def);

  Body res;
  res.body = body;

  return res;
}

}  // namespace components
