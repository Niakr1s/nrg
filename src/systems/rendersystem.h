#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <SFML/Graphics.hpp>

#include "systems/system.h"

class RenderSystem : public System {
  sf::RenderWindow& window_;

 public:
  RenderSystem(sf::RenderWindow& window);

  void update(entt::registry& registry,
              const std::chrono::milliseconds& diff) override;
};

#endif  // RENDERSYSTEM_H
