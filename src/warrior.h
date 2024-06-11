#pragma once

#include "unit.h"

class Warrior : public Unit {
public:
    Warrior(int id, int x, int y, int hp, int strength);
    bool Act(Map& map, int current_tick) override;

private:
    int strength;
};
