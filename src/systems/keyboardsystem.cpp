#include "keyboardsystem.h"

#include <iostream>

#include "components.h"
#include "game/game.h"

systems::KeyboardSystem::KeyboardSystem(states::Game &game) : game_(game) {}

void systems::KeyboardSystem::update(entt::registry &registry,
                                     const std::chrono::milliseconds &diff) {
  std::unique_lock<std::mutex>(game_.eventQueue().mutex);
  while (!game_.eventQueue().queue.empty()) {
    auto event = game_.eventQueue().queue.front();

    if (event.type == sf::Event::MouseButtonPressed) {
    } else if (event.type == sf::Event::MouseMoved) {
    } else if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Escape) {
        game_.manager().pauseGame();
      }

      try {
        auto action = game_.keybindings().at(event.key.code);
        registry.view<components::Player>().each(
            [&](components::Player &player) {
              player.keyboard.keyPressed(action);
            });
      } catch (...) {
      }
    } else if (event.type == sf::Event::KeyReleased) {
      try {
        auto action = game_.keybindings().at(event.key.code);
        registry.view<components::Player>().each(
            [&](components::Player &player) {
              player.keyboard.keyReleased(action);
            });
      } catch (...) {
      }
    }

    game_.eventQueue().queue.pop();
  }
}
