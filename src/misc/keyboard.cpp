#include "keyboard.h"

#include "constants.h"

namespace misc {

KeyBoard::KeyBoard() {}

bool KeyBoard::firePressed() { return pressed_[Key::PlayerFire]; }

void KeyBoard::keyPressed(const Key &key) { pressed_[key] = true; }

void KeyBoard::keyReleased(const Key &key) { pressed_[key] = false; }

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
