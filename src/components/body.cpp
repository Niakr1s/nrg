#include "body.h"

namespace components {

Body::Body(b2World &world) : world_(world) {
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  body_ = world_.CreateBody(&bodyDef);
}

void Body::createFixture(b2FixtureDef *fixture) {
  body_->CreateFixture(fixture);
}

void Body::destroy() { world_.DestroyBody(body_); }

}  // namespace components
