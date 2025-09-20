#pragma once
#include "PointWell.h"
#include "StatBlock.h"
#include "types.h"
#include <cstdint>
#include <memory>
#include <string>

class PlayerCharacterDelegate : public StatBlock {
protected:
  level_t currentLevel_;
  exp_t currentEXP_;
  exp_t expToNextLevel_;
  std::unique_ptr<PointWell> HP;
  // std::unique_ptr<PointWell> MP;

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

  virtual void LevelUp() = 0;

public:
  static const exp_t LEVEL_2_AT = 100u;

  PlayerCharacterDelegate() : StatBlock(0u, 0u) {
    currentLevel_ = 1u;
    currentEXP_ = 0u;
    expToNextLevel_ = LEVEL_2_AT;
    HP = std::make_unique<PointWell>();
  }

  virtual ~PlayerCharacterDelegate() = default;

  virtual std::string getClassName() = 0;
  PointWell *getHP() { return HP.get(); }

  void gainEXP(std::uint64_t gainedEXP) {
    currentEXP_ += gainedEXP;
    while (check_if_leveled()) {
    }
  }

  level_t getCurrentLevel() { return currentLevel_; }
  exp_t getCurrentEXP() { return currentEXP_; }
  exp_t getEXPToNextLevel() { return expToNextLevel_; }
};

#define PC_CONSTRUCT  : PlayerCharacterDelegate() {                            \
    HP->setMax(HP_BASE);                                                       \
    HP->increaseCurrent(HP_BASE);                                              \
    increaseStats(STR_BASE, INT_BASE);                                         \
  }

#define LEVEL_UP                                                               \
  void LevelUp() override {                                                    \
    well_t addedHp = HP_BASE / 2.f;                                            \
    HP->setMax(HP->getMax() + addedHp);                                        \
    HP->increaseCurrent(addedHp);                                              \
    increaseStats((well_t)((STR_BASE + 1u) / 2.f),                             \
                  (well_t)((INT_BASE + 1u) / 2.f));                            \
  }

class Cleric : public PlayerCharacterDelegate {
private:
protected:
  LEVEL_UP
public:
  static const well_t HP_BASE = 14u;
  static const stat_t STR_BASE = 2u;
  static const stat_t INT_BASE = 3u;

  std::string getClassName() override { return std::string("Cleric"); }
  Cleric() PC_CONSTRUCT
};

class Rogue : public PlayerCharacterDelegate {
private:
protected:
  LEVEL_UP
public:
  static const well_t HP_BASE = 12u;
  static const stat_t STR_BASE = 3u;
  static const stat_t INT_BASE = 2u;

  std::string getClassName() override { return std::string("Rogue"); }
  Rogue() PC_CONSTRUCT
};

class Warrior : public PlayerCharacterDelegate {
private:
protected:
  LEVEL_UP
public:
  static const well_t HP_BASE = 18u;
  static const stat_t STR_BASE = 4u;
  static const stat_t INT_BASE = 1u;

  std::string getClassName() override { return std::string("Warrior"); }
  Warrior() PC_CONSTRUCT
};

class Wizard : public PlayerCharacterDelegate {
private:
protected:
  LEVEL_UP
public:
  static const well_t HP_BASE = 10u;
  static const stat_t STR_BASE = 1u;
  static const stat_t INT_BASE = 4u;

  std::string getClassName() override { return std::string("Wizard"); }
  Wizard() PC_CONSTRUCT
};

class PlayerCharacter {
private:
  PlayerCharacterDelegate *pclass;

public:
  PlayerCharacter() = delete;
  PlayerCharacter(PlayerCharacterDelegate *pc) : pclass(pc) {}
  ~PlayerCharacter() {
    delete pclass;
    pclass = nullptr;
  }

  std::string getClassName() { return pclass->getClassName(); }
  stat_t getCurrentLevel() { return pclass->getCurrentLevel(); }
  exp_t getCurrentEXP() { return pclass->getCurrentEXP(); }
  exp_t getEXPToNextLevel() { return pclass->getEXPToNextLevel(); }
  well_t getCurrentHp() { return pclass->getHP()->getCurrent(); }
  well_t getMaxHp() { return pclass->getHP()->getMax(); }
  stat_t getStrength() { return pclass->getStrength(); }
  stat_t getIntellect() { return pclass->getIntellect(); }

  void gainEXP(exp_t exp) { pclass->gainEXP(exp); }
  void takeDamage(well_t damage) { pclass->getHP()->reduce(damage); }

  void heal(well_t heal) { pclass->getHP()->increaseCurrent(heal); }
};