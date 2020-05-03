#include "rendersystem.h"

#include <box2d/box2d.h>

#include <entt/entt.hpp>
#include <iostream>

#include "components.h"

systems::RenderSystem::RenderSystem(sf::RenderWindow &window)
    : window_(window) {}

void systems::RenderSystem::update(const std::chrono::milliseconds &diff) {
  level_->registry().view<components::Body>().each(
      [&](const entt::entity entity, components::Body &body) {
        for (auto fixture = body.body->GetFixtureList(); fixture;
             fixture = fixture->GetNext()) {
          b2Shape *shape = fixture->GetShape();
          switch (shape->m_type) {
            case (b2Shape::Type::e_circle): {
              auto circle_shape = dynamic_cast<b2CircleShape *>(shape);

              b2Vec2 pos = body.body->GetWorldPoint(circle_shape->m_p);

              sf::CircleShape circle(circle_shape->m_radius);
              circle.setPosition(toWindowX(pos.x), toWindowY(pos.y));

              std::cout << "Circle: " << pos.x << ", " << pos.y << ", "
                        << circle_shape->m_radius << std::endl;

              window_.draw(circle);
            } break;
            case (b2Shape::Type::e_polygon): {
              auto polygon_shape = dynamic_cast<b2PolygonShape *>(shape);

              sf::ConvexShape sf_shape;
              sf_shape.setPointCount(polygon_shape->m_count);

              std::cout << "Polygon: ";
              for (int i = 0; i != polygon_shape->m_count; ++i) {
                b2Vec2 pos =
                    body.body->GetWorldPoint(polygon_shape->m_vertices[i]);

                std::cout << pos.x << ", " << pos.y << "; ";

                sf_shape.setPoint(
                    i, sf::Vector2f(toWindowX(pos.x), toWindowY(pos.y)));
              }
              std::cout << std::endl;

              window_.draw(sf_shape);
            } break;
            case (b2Shape::Type::e_edge): {
            } break;
            case (b2Shape::Type::e_typeCount): {
            } break;
            default:
              break;
          }
        }
      });
}

float systems::RenderSystem::toWindowY(float y) const {
  return (window_.getSize().y - y);
}

float systems::RenderSystem::toWindowX(float x) const { return x; }
