#pragma once
#include "types.h"

class StatBlock {
private:
  stat_t strength_;
  stat_t intellect_;
  stat_t agility_;
  stat_t armor_;
  stat_t resistance_;

public:
  StatBlock() {
    strength_ = 1u;
    intellect_ = 1u;
    agility_ = 1u;
    armor_ = 0u;
    resistance_ = 0u;
  }

  explicit StatBlock(stat_t s = 1u, stat_t t = 1u, stat_t a = 1u,
                     stat_t ar = 0u, stat_t r = 0u) {
    strength_ = s;
    intellect_ = t;
    agility_ = a;
    armor_ = ar;
    resistance_ = r;
  }

  stat_t getStrength() { return strength_; }
  stat_t getIntellect() { return intellect_; }
  stat_t getAgility() { return agility_; }
  stat_t getArmor() { return armor_; }
  stat_t getResistance() { return resistance_; }

protected:
  void increaseStats(stat_t strGrowth, stat_t intGrowth, stat_t agiGrowth,
                     stat_t armorGrowth = 0u, stat_t resGrowth = 0u) {
    strength_ += strGrowth;
    intellect_ += intGrowth;
    agility_ += agiGrowth;
    armor_ += armorGrowth;
    resistance_ += resGrowth;
  }
};