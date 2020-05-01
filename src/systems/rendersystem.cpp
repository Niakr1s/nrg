#include "rendersystem.h"

#include <box2d/box2d.h>

#include <entt/entt.hpp>
#include <iostream>

#include "components.h"

systems::RenderSystem::RenderSystem(sf::RenderWindow &window)
    : window_(window) {}

void systems::RenderSystem::update(entt::registry &registry,
                                   const std::chrono::milliseconds &diff) {
  registry.view<components::Body>().each([&](const entt::entity entity,
                                             components::Body &body) {
    for (auto fixture = body.body->GetFixtureList(); fixture;
         fixture = fixture->GetNext()) {
      b2Shape *shape = fixture->GetShape();
      switch (shape->m_type) {
        case (b2Shape::Type::e_circle): {
          b2CircleShape *circle_shape = dynamic_cast<b2CircleShape *>(shape);
          b2Vec2 pos = body.body->GetWorldPoint(circle_shape->m_p);
          float radius = circle_shape->m_radius;
          sf::CircleShape circle(radius);
          circle.setPosition(pos.x, window_.getSize().y - pos.y);
          if (registry.has<components::Player>(entity)) {
            circle.setFillColor(sf::Color::White);
          }
          window_.draw(circle);
          std::cout << pos.x << ", " << pos.y << std::endl;
        } break;
        default:
          break;
      }
    }
  });
}
