#include "rendersystem.h"

#include "components.h"

RenderSystem::RenderSystem(sf::RenderWindow &window) : window_(window) {}

void RenderSystem::update(entt::registry &registry,
                          const std::chrono::milliseconds &diff) {}
