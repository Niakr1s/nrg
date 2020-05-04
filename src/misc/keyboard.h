#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <map>
#include <optional>

#include "game/keybindings.h"

namespace misc {

class KeyBoard {
 public:
  using Key = KeyBindings::Key;

 private:
  std::map<KeyBindings::Key, bool> pressed_;

  bool fire_was_pressed_ = false;

 public:
  KeyBoard();

  std::pair<float, float> getDirectionVector();
  float getAngleVelocity(float angle_velocity);

  void keyPressed(const Key& key);
  void keyReleased(const Key& key);

  bool isKeyPressed(const Key& key) const;

  bool fireWasPressed() const;
  void unpressFire();
};

}  // namespace misc

#endif  // KEYBOARD_H
