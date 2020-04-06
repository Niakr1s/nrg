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

bool KeyBindings::exists(const sf::Keyboard::Key& key) const {
  try {
    auto tmp = bindings_.at(key);
    return true;
  } catch (std::invalid_argument) {
    return false;
  }
}
