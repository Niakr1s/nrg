#ifndef PLAYER_H
#define PLAYER_H

#include "components.h"
#include "constants.h"
#include "player/keyboard.h"

namespace components {

struct Player {
  KeyBoard keyboard;
  float velocity = DEFAULT_PLAYER_VELOCITY;
};

}  // namespace components

#endif  // PLAYER_H
