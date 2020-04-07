#include "keybindings.h"

#include <algorithm>
#include <exception>

KeyBindings::KeyBindings()
    : KeyBindings(std::map<sf::Keyboard::Key, KeyBindings::Key>{{}}) {}

KeyBindings::KeyBindings(
    const std::map<sf::Keyboard::Key, KeyBindings::Key>& bindings)
    : bindings_(bindings) {}

KeyBindings::Key KeyBindings::at(const sf::Keyboard::Key& key) const {
  return bindings_.at(key);
}

KeyBindings KeyBindings::defaultKeyBindings() {
  return KeyBindings({
      {sf::Keyboard::W, Key::PlayerUp},
      {sf::Keyboard::S, Key::PlayerDown},
      {sf::Keyboard::A, Key::PlayerLeft},
      {sf::Keyboard::D, Key::PlayerRight},
      {sf::Keyboard::Space, Key::PlayerFire},
  });
}
