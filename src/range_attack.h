#pragma once

#include "attack.h"

class RangeAttack : public Attack {
public:
    static bool Attack(Unit& unit, int range, int damage, Map& map, int current_tick);
};
