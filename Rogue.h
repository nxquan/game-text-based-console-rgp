#pragma once
#include "Hp.h"
#include "LevelSystem.h"
#include "StatBlock.h"

class Rogue : public Hp, public StatBlock, public LevelSystem {
private:
public:
  static const hp_t HP_BASE = 12u;
  static const stat_t STR_BASE = 3u;
  static const stat_t INT_BASE = 2u;

  static const hp_t HP_GROWTH = 6u;
  static const stat_t STR_GROWTH = 2u;
  static const stat_t INT_GROWTH = 1u;
  
  Rogue() : Hp(HP_BASE, HP_BASE), StatBlock(STR_BASE, INT_BASE) {} 
  
  void LevelUp() override {
    setMaxHp(getMaxHp() + HP_GROWTH);
    increaseStats(STR_GROWTH, INT_GROWTH);
  }
};