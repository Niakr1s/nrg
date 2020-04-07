#include "keyboard.h"

namespace components {

KeyBoard::KeyBoard() {}

bool KeyBoard::firePressed() { return pressed_[Key::PlayerFire]; }

void KeyBoard::keyPressed(const Key &key) { pressed_[key] = true; }

void KeyBoard::keyReleased(const Key &key) { pressed_[key] = false; }

std::pair<int, int> KeyBoard::getdirection() {
  std::pair<int, int> res{0, 0};
  if (pressed_[Key::PlayerUp] && !pressed_[Key::PlayerDown]) {
    res.second = -1;
  }
  if (pressed_[Key::PlayerDown] && !pressed_[Key::PlayerUp]) {
    res.second = 1;
  }
  if (pressed_[Key::PlayerLeft] && !pressed_[Key::PlayerRight]) {
    res.first = -1;
  }
  if (pressed_[Key::PlayerRight] && !pressed_[Key::PlayerLeft]) {
    res.first = 1;
  }
  return res;
}

}  // namespace components
