#pragma once
#include "Hp.h"
#include "StatBlock.h"

class Cleric : public Hp, public StatBlock {
private:
public:
  static const hp_t HP_GROWTH = 14u;
  static const stat_t BASE_STR = 2u;
  static const stat_t BASE_INT = 3u;

  Cleric() : Hp(HP_GROWTH, HP_GROWTH), StatBlock(BASE_STR, BASE_INT) {}
};