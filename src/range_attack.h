#pragma once

#include "unit.h"
#include "map.h"
#include "attack.h"
#include <vector>
#include <memory>

class RangeAttack : public Attack {
public:
    static bool Attack(Unit& unit, int range, int damage, Map& map, std::vector<std::unique_ptr<Unit>>& units, int current_tick);
};
