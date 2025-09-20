#pragma once
#include "Hp.h"
#include "StatBlock.h"
#include "LevelSystem.h"

class Wizard : public Hp, public StatBlock, public LevelSystem {
private:
public:
  static const hp_t HP_BASE = 9u;
  static const stat_t STR_BASE = 1u;
  static const stat_t INT_BASE = 4u;

  static const hp_t HP_GROWTH = 5u;
  static const stat_t STR_GROWTH = 1u;
  static const stat_t INT_GROWTH = 2u;
  
  Wizard() : Hp(HP_BASE, HP_BASE), StatBlock(STR_BASE, INT_BASE) {}
  
  void LevelUp() override {
    setMaxHp(getMaxHp() + HP_GROWTH);
    increaseStats(STR_GROWTH, INT_GROWTH);
  }
};