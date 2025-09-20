#include "allclasses.h"
#include <iostream>

int main() {
  Cleric c;
  std::cout << "Cleric HP: " << c.getCurrentHp() << ", max hp: " << c.getMaxHp()
            << ", strength: " << c.getStrength()
            << ", level: " << c.getCurrentLevel()
            << ", EXP: " << c.getCurrentEXP() << "/" << c.getEXPToNextLevel()
            << "\n";
  c.gainEXP(100u);
  std::cout << "Cleric HP: " << c.getCurrentHp() << ", max hp: " << c.getMaxHp()
            << ", strength: " << c.getStrength()
            << ", level: " << c.getCurrentLevel()
            << ", EXP: " << c.getCurrentEXP() << "/" << c.getEXPToNextLevel()
            << "\n";

  return 0;
}