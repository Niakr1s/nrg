#include "movesystem.h"

#include <iostream>

#include "components.h"
#include "constants.h"
#include "misc/direction.h"

systems::MoveSystem::MoveSystem(b2World& world) : world_(world) {}

void systems::MoveSystem::update(entt::registry& registry,
                                 const std::chrono::milliseconds& diff) {
  registry.view<components::Player, components::Body>().each(
      [&](components::Player& player, components::Body& body) {
        misc::Direction direction(player.keyboard.getDirectionVector());
        if (direction.angle() == std::nullopt) {
          body.body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
        } else {
          body.body->SetLinearVelocity(b2Vec2(direction.dx(player.velocity),
                                              direction.dy(player.velocity)));
        }
      });

  world_.Step(static_cast<float>(diff.count()) / 1000, 6, 2);
}
