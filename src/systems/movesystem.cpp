#include "movesystem.h"

#include <iostream>

#include "components.h"

MoveSystem::MoveSystem() {}

void MoveSystem::update(entt::registry& registry,
                        const std::chrono::milliseconds& diff) {
  registry
      .view<components::KeyBoard, components::Velocity, components::Direction>()
      .each([&](components::KeyBoard& kb, components::Velocity& vel,
                components::Direction& direction) {
        direction.setDirection(kb.getdirection().first,
                               kb.getdirection().second);
      });

  registry
      .view<components::Position, components::Velocity, components::Direction>()
      .each([&](components::Position& pos, components::Velocity& vel,
                components::Direction& dir) {
        pos.x += dir.dx(vel.speed) * diff.count() / 1000;
        pos.y += dir.dy(vel.speed) * diff.count() / 1000;
      });
}
