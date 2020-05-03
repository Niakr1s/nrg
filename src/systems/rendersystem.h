#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <SFML/Graphics.hpp>

#include "systems/system.h"

namespace systems {

class RenderSystem : public System {
  sf::RenderWindow& window_;
  float zoom_;
  sf::Vector2f view_point_;    // in level coordinates
  sf::Vector2f center_point_;  // in window coordinates

 public:
  RenderSystem(sf::RenderWindow& window);

  void update(const std::chrono::milliseconds&) override;

 private:
  float toWindowY(float y) const;
  float toWindowX(float x) const;
  float toWindowRadians(float angle) const;
  float zoom(float a) const;

  void onNewLevel() override;

  void updateZoom();
  void updateViewPoint();
};

}  // namespace systems

#endif  // RENDERSYSTEM_H
