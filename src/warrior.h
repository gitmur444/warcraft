#pragma once

#include "unit.h"
#include "map.h"
#include <vector>
#include <memory>

class Warrior : public Unit {
public:
    Warrior(int id, int x, int y, int hp, int strength);
    bool Act(Map& map, std::vector<std::unique_ptr<Unit>>& units, int current_tick) override;

private:
    int strength;
};
