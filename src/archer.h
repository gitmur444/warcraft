#pragma once

#include "unit.h"
#include "map.h"

class Archer : public Unit {
public:
    Archer(int id, int x, int y, int hp, int strength, int range, int agility);
    bool Act(Map& map, int current_tick) override;

private:
    int strength;
    int range;
    int agility;
};
