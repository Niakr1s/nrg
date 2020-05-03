#include "level.h"

#include <iostream>

#include "components.h"
#include "constants.h"

namespace level {

b2World &Level::world() { return world_; }

entt::registry &Level::registry() { return registry_; }

int Level::width() const { return width_; }

int Level::height() const { return height_; }

Level::Level(int width, int height)
    : world_(b2Vec2(0.f, 0.f)), width_(width), height_(height) {
  makeFrame(width, height);
}

void Level::makeFrame(int width, int height) {
  makeGroundBody(-constants::BORDERS_WIDTH / 2, height / 2,
                 constants::BORDERS_WIDTH,
                 height + constants::BORDERS_WIDTH * 2);
  makeGroundBody(width + constants::BORDERS_WIDTH / 2, height / 2,
                 constants::BORDERS_WIDTH,
                 height + constants::BORDERS_WIDTH * 2);
  makeGroundBody(width / 2, -constants::BORDERS_WIDTH / 2, width,
                 constants::BORDERS_WIDTH);
  makeGroundBody(width / 2, height + constants::BORDERS_WIDTH / 2, width,
                 constants::BORDERS_WIDTH);
}

void Level::spawnPlayer(int x, int y) {
  auto [entity, player, body] =
      registry_.create<components::Player, components::Body>();

  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(x, y);

  body.body = world_.CreateBody(&bodyDef);

  b2FixtureDef fixture_def;

  b2CircleShape shape;
  shape.m_p.Set(0, 0);
  shape.m_radius = 10.0f;

  fixture_def.shape = &shape;
  fixture_def.density = 1.0f;
  fixture_def.friction = 0.3f;

  body.body->CreateFixture(&fixture_def);
}

void Level::spawnEnemy(int x, int y) {
  // TODO
}

void Level::makeGroundBody(float x, float y, float w, float h) {
  auto [entity, body] = registry_.create<components::Body>();

  std::cout << "makeGroundBody: got " << x << ", " << y << ", " << w << ", "
            << h << std::endl;

  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(x, y);
  body.body = world_.CreateBody(&groundBodyDef);

  b2PolygonShape groundBox;
  groundBox.SetAsBox(w / 2, h / 2);
  body.body->CreateFixture(&groundBox, 0.f);
}

}  // namespace level
