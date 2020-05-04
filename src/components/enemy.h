#ifndef ENEMY_H
#define ENEMY_H

#include "constants.h"

namespace components {

struct Enemy {
  float radius = constants::DEFAULT_ENEMY_RADIUS;
};

}  // namespace components

#endif  // ENEMY_H
