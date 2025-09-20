#pragma once
#include "Hp.h"
#include "StatBlock.h"

class Rogue : public Hp, public StatBlock {
private:
public:
  static const hp_t HP_GROWTH = 13u;
  static const stat_t BASE_STR = 3u;
  static const stat_t BASE_INT = 2u;

  Rogue() : Hp(HP_GROWTH, HP_GROWTH), StatBlock(BASE_STR, BASE_INT) {}
};