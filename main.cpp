#include <iostream>

#include "PlayerCharacter.h"

int main() {
  PlayerCharacter p(new Rogue());
  std::cout << p.getClassName() << " HP: " << p.getCurrentHp() << "/"
            << p.getMaxHp() << ", strength: " << p.getStrength()
            << ", intellect: " << p.getIntellect()
            << ", agility: " << p.getAgility()
            << ", armor: " << p.getArmor()
            << ", resistance: " << p.getResistance()
            << ", level: " << p.getCurrentLevel()
            << ", EXP: " << p.getCurrentEXP() << "/" << p.getEXPToNextLevel()
            << "\n";
  p.gainEXP(100u);
  std::cout << p.getClassName() << " HP: " << p.getCurrentHp() << "/"
            << p.getMaxHp() << ", strength: " << p.getStrength()
            << ", intellect: " << p.getIntellect()
            << ", agility: " << p.getAgility()
            << ", armor: " << p.getArmor()
            << ", resistance: " << p.getResistance()
            << ", level: " << p.getCurrentLevel()
            << ", EXP: " << p.getCurrentEXP() << "/" << p.getEXPToNextLevel()
            << "\n";
  return 0;
}