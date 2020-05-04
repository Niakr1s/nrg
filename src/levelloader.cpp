#include "levelloader.h"

#include "armory/pistolgun.h"
#include "components.h"
#include "constants.h"

namespace level {

level::LevelLoader::LevelLoader() {}

std::shared_ptr<Level> level::LevelLoader::loadNextLevel() {
  return doLoadNextLevel();
}

std::shared_ptr<level::Level> level::TmpLevelLoader::doLoadNextLevel() {
  auto level = std::make_shared<Level>(250, 200);

  auto player = level->spawnPlayer(125, 20);
  components::Weapon& player_weapon =
      level->registry().assign<components::Weapon>(player);
  player_weapon.guns.push_back(
      std::make_shared<armory::PistolGun>(0.f, 200, false));

  auto enemy = level->spawnEnemy(125, 170);
  components::Weapon& enemy_weapon =
      level->registry().assign<components::Weapon>(enemy);
  enemy_weapon.setAngleVelocity(constants::DEFAULT_WEAPON_ANGLE_VELOCITY);
  enemy_weapon.guns.push_back(
      std::make_shared<armory::PistolGun>(constants::PI * 0.0f, 1000));
  enemy_weapon.guns.push_back(
      std::make_shared<armory::PistolGun>(constants::PI * 0.5f, 1000));
  enemy_weapon.guns.push_back(
      std::make_shared<armory::PistolGun>(constants::PI * 1.0f, 1000));
  enemy_weapon.guns.push_back(
      std::make_shared<armory::PistolGun>(constants::PI * 1.5f, 1000));

  return level;
}

}  // namespace level
