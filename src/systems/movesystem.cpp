#include "movesystem.h"

#include "components.h"

MoveSystem::MoveSystem() {}

void MoveSystem::update(entt::registry& registry,
                        const std::chrono::milliseconds& diff) {
  registry.view<components::KeyBoard, components::Velocity>().each(
      [&](components::KeyBoard& kb, components::Velocity& vel) {
        auto direction = kb.getdirection();
        vel.dx_per_sec = direction.first * 100;
        vel.dy_per_sec = direction.second * 100;
      });

  registry.view<components::Position, components::Velocity>().each(
      [&](components::Position& pos, components::Velocity& vel) {
        pos.x += vel.dx_per_sec * diff.count() / 1000;
        pos.y += vel.dy_per_sec * diff.count() / 1000;
      });
}
