#pragma once
#include "unit.h"

class Warrior : public Unit {
public:
    Warrior(int id, int x, int y, int hp, int strength);
    std::string getType() const override;
};
