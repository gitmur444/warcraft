#include "melee_attack.h"
#include <iostream>

bool MeleeAttack::Attack(Unit& unit, int damage, Map& map, int current_tick) {
    Unit* target = FindTarget(unit, 1, map);
    if (target) {
        PerformAttack(unit, target, damage, map, current_tick);
        return true;
    }
    return false;
}
