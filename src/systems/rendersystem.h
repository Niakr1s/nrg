#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <SFML/Graphics.hpp>

#include "systems/system.h"

namespace systems {

class RenderSystem : public System {
  sf::RenderWindow& window_;

 public:
  RenderSystem(sf::RenderWindow& window);

  void update(const std::chrono::milliseconds& diff) override;

 private:
  float toWindowY(float y) const;
  float toWindowX(float x) const;
};

}  // namespace systems

#endif  // RENDERSYSTEM_H
