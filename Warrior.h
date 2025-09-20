#pragma once
#include "Hp.h"
#include "LevelSystem.h"
#include "StatBlock.h"

class Warrior : public Hp, public StatBlock, public LevelSystem {
private:
public:
  static const hp_t HP_GROWTH = 18u;
  static const stat_t BASE_STR = 4u;
  static const stat_t BASE_INT = 1u;

  static const hp_t HP_GROWTH = 9u;
  static const stat_t STR_GROWTH = 2u;
  static const stat_t INT_GROWTH = 1u;

  Warrior() : Hp(HP_GROWTH, HP_GROWTH), StatBlock(BASE_STR, BASE_INT) {}

  void LevelUp() override {
    setMaxHp(getMaxHp() + HP_GROWTH);
    increaseStats(STR_GROWTH, INT_GROWTH);
  }
};