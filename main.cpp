#include "allclasses.h"
#include <iostream>

int main() {
  Warrior w;
  std::cout << "Warrior HP: " << w.getCurrentHp()
            << ", max hp: " << w.getMaxHp() << ", strength: " << w.getStrength() << "\n";

  return 0;
}