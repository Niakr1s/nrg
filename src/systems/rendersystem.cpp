#include "rendersystem.h"

#include <entt/entt.hpp>

#include "components.h"

systems::RenderSystem::RenderSystem(sf::RenderWindow &window)
    : window_(window) {}

void systems::RenderSystem::update(entt::registry &registry,
                                   const std::chrono::milliseconds &diff) {
  registry.view<components::Position, components::Radius>().each(
      [&](const entt::entity entity, components::Position &pos,
          components::Radius &radius) {
        sf::CircleShape circle(radius.r);
        circle.setPosition(pos.x, pos.y);

        if (registry.has<components::Player>(entity)) {
          circle.setFillColor(sf::Color::White);
        }

        window_.draw(circle);
      });
}
