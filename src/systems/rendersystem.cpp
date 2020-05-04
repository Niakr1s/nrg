#include "rendersystem.h"

#include <box2d/box2d.h>

#include <entt/entt.hpp>
#include <iostream>

#include "components.h"

systems::RenderSystem::RenderSystem(sf::RenderWindow &window)
    : window_(window),
      center_point_((float)window.getSize().x / 2,
                    (float)window.getSize().y / 2) {}

void systems::RenderSystem::update(const std::chrono::milliseconds &) {
  updateViewPoint();

  level_->registry().view<components::Body>().each(
      [&](const entt::entity entity, components::Body &body) {
        for (auto fixture = body.body->GetFixtureList(); fixture;
             fixture = fixture->GetNext()) {
          b2Shape *shape = fixture->GetShape();
          switch (shape->m_type) {
            case (b2Shape::Type::e_circle): {
              auto circle_shape = dynamic_cast<b2CircleShape *>(shape);

              float radius = circle_shape->m_radius;
              b2Vec2 pos = body.body->GetWorldPoint(circle_shape->m_p);
              b2Vec2 center_pos_zoomed(toWindowX(pos.x), toWindowY(pos.y));

              float radius_zoomed = zoom(radius);

              sf::CircleShape circle(radius_zoomed);
              circle.setPosition(center_pos_zoomed.x - radius_zoomed,
                                 center_pos_zoomed.y - radius_zoomed);

              if (level_->registry().has<components::Enemy>(entity)) {
                circle.setFillColor(sf::Color::Red);
              }

              window_.draw(circle);

              if (level_->registry().has<components::Player>(entity)) {
                sf::RectangleShape arrow;
                arrow.setPosition(center_pos_zoomed.x, center_pos_zoomed.y);
                arrow.setSize({1.f, radius_zoomed});

                arrow.setFillColor(sf::Color::Black);

                arrow.rotate(toWindowRadians(body.body->GetAngle()));

                window_.draw(arrow);
              }

            } break;
            case (b2Shape::Type::e_polygon): {
              auto polygon_shape = dynamic_cast<b2PolygonShape *>(shape);

              sf::ConvexShape sf_shape;
              sf_shape.setPointCount(polygon_shape->m_count);

              for (int i = 0; i != polygon_shape->m_count; ++i) {
                b2Vec2 pos =
                    body.body->GetWorldPoint(polygon_shape->m_vertices[i]);

                sf_shape.setPoint(
                    i, sf::Vector2f(toWindowX(pos.x), toWindowY(pos.y)));
              }

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
  float diff = y - view_point_.y;
  auto res = center_point_.y - zoom(diff);
  return res;
}

float systems::RenderSystem::toWindowX(float x) const {
  float diff = x - view_point_.x;
  auto res = center_point_.x + zoom(diff);
  return res;
}

float systems::RenderSystem::toWindowRadians(float angle) const {
  float n = angle / constants::PI;
  float res = -90.f + 180.f * n;
  return res;
}

float systems::RenderSystem::zoom(float a) const { return zoom_ * a; }

void systems::RenderSystem::onNewLevel() { updateZoom(); }

void systems::RenderSystem::updateZoom() {
  float vertical = (float)window_.getSize().y / level_->height();
  float horizontal = (float)window_.getSize().x / level_->width();

  zoom_ = std::min(vertical, horizontal) * 0.8f;
}

void systems::RenderSystem::updateViewPoint() {
  view_point_.x = level_->width() / 2;
  view_point_.y = level_->height() / 2;
}
