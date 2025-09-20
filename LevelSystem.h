#pragma once
#include "types.h"
#include <cstdint>

class LevelSystem {
protected:
  level_t currentLevel_;
  exp_t currentEXP_;
  exp_t expToNextLevel_;

  bool check_if_leveled() {
    static const level_t LEVEL_SCALAR = 2u;
    if (currentEXP_ >= expToNextLevel_) {
      currentLevel_++;
      LevelUp();
      expToNextLevel_ += LEVEL_2_AT * LEVEL_SCALAR;
      return true;
    }

    return false;
  }

public:
  static const exp_t LEVEL_2_AT = 100u;

  LevelSystem() {
    currentLevel_ = 1u;
    currentEXP_ = 0u;
    expToNextLevel_ = LEVEL_2_AT;
  }

  virtual void LevelUp() = 0;

  void gainEXP(std::uint64_t gainedEXP) {
    currentEXP_ += gainedEXP;
    while (check_if_leveled()) {
    }
  }

  level_t getCurrentLevel() { return currentLevel_; }

  exp_t getCurrentEXP() { return currentEXP_; }

  exp_t getEXPToNextLevel() { return expToNextLevel_; }
};