#ifndef PLAYER_H
#define PLAYER_H

#include "components.h"
#include "constants.h"
#include "misc/keyboard.h"

namespace components {

struct Player {
  misc::KeyBoard keyboard;
  float velocity = constants::DEFAULT_PLAYER_VELOCITY;
  float radius = constants::DEFAULT_PLAYER_RADIUS;
};

}  // namespace components

#endif  // PLAYER_H
