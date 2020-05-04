#ifndef WEAPONSYSTEM_H
#define WEAPONSYSTEM_H

#include "systems/system.h"

namespace systems {

class WeaponSystem : public System {
 public:
  WeaponSystem();

  void update(const std::chrono::milliseconds &diff) override;
};

}  // namespace systems

#endif  // WEAPONSYSTEM_H
