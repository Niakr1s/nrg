#include "keyboard.h"

#include <iostream>

#include "constants.h"

namespace misc {

KeyBoard::KeyBoard() {}

bool KeyBoard::fireWasPressed() const { return fire_was_pressed_; }

void KeyBoard::unpressFire() { fire_was_pressed_ = false; }

void KeyBoard::keyPressed(const Key &key) {
  std::cout << "key pressed: " << (unsigned)key << std::endl;
  pressed_[key] = true;
  if (key == Key::PlayerFire) fire_was_pressed_ = true;
}

void KeyBoard::keyReleased(const Key &key) { pressed_[key] = false; }

bool KeyBoard::isKeyPressed(const KeyBoard::Key &key) const {
  try {
    return pressed_.at(key);
  } catch (...) {
    return false;
  }
}

std::pair<float, float> KeyBoard::getDirectionVector() {
  std::pair<float, float> res{0.f, 0.f};
  if (pressed_[Key::PlayerUp] && !pressed_[Key::PlayerDown]) {
    res.second = 1.f;
  }
  if (pressed_[Key::PlayerDown] && !pressed_[Key::PlayerUp]) {
    res.second = -1.f;
  }
  if (pressed_[Key::PlayerLeft] && !pressed_[Key::PlayerRight]) {
    res.first = -1.f;
  }
  if (pressed_[Key::PlayerRight] && !pressed_[Key::PlayerLeft]) {
    res.first = 1.f;
  }
  return res;
}

float KeyBoard::getAngleVelocity(float angle_velocity) {
  int angle_direction = 0;

  if (pressed_[Key::PlayerClockWise]) ++angle_direction;
  if (pressed_[Key::PlayerCounterClockWise]) --angle_direction;

  return angle_velocity * angle_direction;
}

}  // namespace misc
