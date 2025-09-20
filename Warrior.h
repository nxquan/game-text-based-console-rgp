#pragma once
#include "Hp.h"
#include "StatBlock.h"

class Warrior : public Hp, public StatBlock {
private:
public:
  static const hp_t HP_GROWTH = 19u;
  static const stat_t BASE_STR = 4u;
  static const stat_t BASE_INT = 1u;

  Warrior() : Hp(HP_GROWTH, HP_GROWTH), StatBlock(BASE_STR, BASE_INT) {}
};