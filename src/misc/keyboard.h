#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <map>
#include <optional>

#include "game/keybindings.h"

namespace misc {

class KeyBoard {
  using Key = KeyBindings::Key;

  std::map<KeyBindings::Key, bool> pressed_;

 public:
  KeyBoard();

  std::pair<float, float> getDirectionVector();
  float getAngleVelocity();

  void keyPressed(const Key& key);
  void keyReleased(const Key& key);

  bool firePressed();
};

}  // namespace misc

#endif  // KEYBOARD_H
