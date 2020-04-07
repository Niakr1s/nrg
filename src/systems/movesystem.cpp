#include "movesystem.h"

#include "components.h"

MoveSystem::MoveSystem() {}

void MoveSystem::update(entt::registry& registry,
                        const std::chrono::milliseconds& diff) {
  registry.view<components::Position, components::Velocity>().each(
      [&](components::Position& pos, components::Velocity& vel) {
        pos.x += vel.dx_per_sec * diff.count() / 1000;
        pos.y += vel.dy_per_sec * diff.count() / 1000;
      });
}
