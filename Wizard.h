#pragma once
#include "Hp.h"
#include "StatBlock.h"

class Wizard : public Hp, public StatBlock {
private:
public:
  static const hp_t HP_GROWTH = 9u;
  static const stat_t BASE_STR = 1u;
  static const stat_t BASE_INT = 4u;

  Wizard() : Hp(HP_GROWTH, HP_GROWTH), StatBlock(BASE_STR, BASE_INT) {}
};