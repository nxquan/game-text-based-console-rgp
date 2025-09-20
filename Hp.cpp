#include "Hp.h"

Hp::Hp() {
  currentHp_ = 1;
  maxHp_ = 1;
}

Hp::Hp(hp_t cHP, hp_t mHP) {
  currentHp_ = cHP;
  maxHp_ = mHP;
  if (currentHp_ > maxHp_) {
    currentHp_ = maxHp_;
  }
}

bool Hp::setMaxHp(hp_t newMaxHp) {
  if (newMaxHp < 1) {
    return false;
  }

  maxHp_ = newMaxHp;

  if (currentHp_ > maxHp_) {
    currentHp_ = maxHp_;
  }

  return true;
}

void Hp::takeDamage(hp_t damage) {
  if (damage > currentHp_) {
    currentHp_ = 0;
    return;
  }

  currentHp_ -= damage;
  return;
}

void Hp::heal(hp_t amount) {
  if (amount + currentHp_ > maxHp_) {
    currentHp_ = maxHp_;
    return;
  }

  currentHp_ += amount;
  return;
}

hp_t Hp::getMaxHp() { return maxHp_; }

hp_t Hp::getCurrentHp() { return currentHp_; }