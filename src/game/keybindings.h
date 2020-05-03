#ifndef KEYBINDINGS_H
#define KEYBINDINGS_H

#include <SFML/Window/Event.hpp>
#include <map>

class KeyBindings {
 public:
  enum struct Key {
    PlayerUp,
    PlayerDown,
    PlayerLeft,
    PlayerRight,
    PlayerFire,
    PlayerClockWise,
    PlayerCounterClockWise,
  };

  KeyBindings();
  KeyBindings(const std::map<sf::Keyboard::Key, Key>& bindings);

  Key at(const sf::Keyboard::Key& key) const;

  static KeyBindings defaultKeyBindings();

 private:
  std::map<sf::Keyboard::Key, Key> bindings_;
};

#endif  // KEYBINDINGS_H
