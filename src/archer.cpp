#include "archer.h"

Archer::Archer(int id, int x, int y, int hp, int strength, int range, int agility)
    : Unit(id, x, y, hp, strength), range_(range), agility_(agility) {}

std::string Archer::getType() const {
    return "Archer";
}

int Archer::getRange() const {
    return range_;
}

int Archer::getAgility() const {
    return agility_;
}
