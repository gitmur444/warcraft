#include "warrior.h"

Warrior::Warrior(int id, int x, int y, int hp, int strength) : Unit(id, x, y, hp, strength) {}

std::string Warrior::getType() const {
    return "Warrior";
}
