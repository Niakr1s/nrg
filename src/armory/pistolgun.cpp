#include "pistolgun.h"

#include <iostream>

#include "components.h"
#include "misc/direction.h"

namespace armory {

void PistolGun::doSpawnBullet(level::Level& level, entt::entity parent) {
  components::Body& parent_body =
      level.registry().get<components::Body>(parent);
  b2Vec2 pos = parent_body.body->GetPosition();

  misc::Direction dir(absoluteAngle());
  b2Vec2 velocity = dir.vectorVelocity(velocity_);

  auto [entity, body, bullet] =
      level.registry().create<components::Body, components::Bullet>();

  if (auto player = level.registry().try_get<components::Player>(parent)) {
    pos.x += dir.dx(player->radius) + radius_ * 1.1f;
    pos.y += dir.dy(player->radius) + radius_ * 1.1f;
  } else if (auto enemy = level.registry().try_get<components::Enemy>(parent)) {
    pos.x += dir.dx(enemy->radius) + radius_ * 1.1f;
    pos.y += dir.dy(enemy->radius) + radius_ * 1.1f;
  }

  body.body = level.makeCircle(pos.x, pos.y, radius_, true);
  body.body->SetLinearVelocity(velocity);
}

}  // namespace armory
