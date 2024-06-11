#pragma once

#include "map.h"
#include "unit.h"

class Attack {
public:
    static Unit* FindTarget(Unit& unit, int range, Map& map);
    static void PerformAttack(Unit& attacker, Unit* target, int damage, Map& map, int current_tick);
};
