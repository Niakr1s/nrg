#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <map>

#include "game/keybindings.h"

namespace components {

class KeyBoard {
  using Key = KeyBindings::Key;

  std::map<KeyBindings::Key, bool> pressed_;

 public:
  KeyBoard();

  void keyPressed(const Key& key);
  void keyReleased(const Key& key);

  std::pair<int, int> getdirection();

  bool firePressed();
};

}  // namespace components

#endif  // KEYBOARD_H
