#pragma once
#include "unit.h"

class Archer : public Unit {
public:
    Archer(int id, int x, int y, int hp, int strength, int range, int agility);
    std::string getType() const override;
    int getRange() const;
    int getAgility() const;

private:
    int range_;
    int agility_;
};
