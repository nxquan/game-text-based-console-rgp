#pragma once
#include "types.h"

class StatBlock {
private:
  stat_t strength_;
  stat_t intellect_;

public:
  StatBlock() {
    strength_ = 1u;
    intellect_ = 1u;
  }

  explicit StatBlock(stat_t s, stat_t t) {
    strength_ = s;
    intellect_ = t;
  }

  stat_t getStrength() { return strength_; }

  stat_t getIntellect() { return intellect_; }

protected:
  void increaseStats(stat_t strGrowth, stat_t intGrowth) {
    strength_ += strGrowth;
    intellect_ += intGrowth;
  }
};