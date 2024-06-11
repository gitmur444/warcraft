#include "range_attack.h"
#include <iostream>

bool RangeAttack::Attack(Unit& unit, int range, int damage, Map& map, int current_tick) {
    Unit* target = FindTarget(unit, range, map);
    if (target && (abs(unit.GetX() - target->GetX()) >= 2 || abs(unit.GetY() - target->GetY()) >= 2)) {
        PerformAttack(unit, target, damage, map, current_tick);
        return true;
    }
    return false;
}
