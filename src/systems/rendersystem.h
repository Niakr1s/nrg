#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <SFML/Graphics.hpp>

#include "systems/system.h"

namespace systems {

class RenderSystem : public System {
  sf::RenderWindow& window_;

 public:
  RenderSystem(sf::RenderWindow& window);

  void update(entt::registry& registry,
              const std::chrono::milliseconds& diff) override;
};

}  // namespace systems

#endif  // RENDERSYSTEM_H
