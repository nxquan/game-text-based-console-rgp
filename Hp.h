#pragma once
#include "hitpointtypes.h"
#include <cstdint>
#include <math.h>

class Hp {
private:
  hp_t currentHp_;
  hp_t maxHp_;
  hp_t shieldHp_;

public:
  Hp();
  Hp(hp_t cHP, hp_t mHP);
  bool setMaxHp(hp_t newMaxHp);
  void takeDamage(hp_t damage);
  void heal(hp_t amount);
  hp_t getMaxHp();
  hp_t getCurrentHp();
};