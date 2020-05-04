#ifndef PISTOLGUN_H
#define PISTOLGUN_H

#include "constants.h"
#include "gun.h"

namespace armory {

class PistolGun : public Gun {
  const float radius_ = 1.f;
  const float velocity_ = constants::DEFAULT_BULLET_VELOCITY;

 public:
  using Gun::Gun;

 protected:
  void doSpawnBullet(level::Level& level, entt::entity parent) override;
};

}  // namespace armory

#endif  // PISTOLGUN_H
