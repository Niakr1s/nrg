#include "keyboardsystem.h"

#include <iostream>

#include "components.h"
#include "game/game.h"

KeyboardSystem::KeyboardSystem(Game &game) : game_(game) {}

void KeyboardSystem::update(entt::registry &registry,
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
        registry.view<components::KeyBoard>().each(
            [&](components::KeyBoard &keyboard) {
              keyboard.keyPressed(action);
            });
      } catch (...) {
      }
    } else if (event.type == sf::Event::KeyReleased) {
      try {
        auto action = game_.keybindings().at(event.key.code);
        registry.view<components::KeyBoard>().each(
            [&](components::KeyBoard &keyboard) {
              keyboard.keyReleased(action);
            });
      } catch (...) {
      }
    }

    game_.eventQueue().queue.pop();
  }
}
