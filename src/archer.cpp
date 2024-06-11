#include "archer.h"
#include "map.h"
#include "movement.h"
#include "range_attack.h"
#include "melee_attack.h" 
#include <iostream>

Archer::Archer(int id, int x, int y, int hp, int strength, int range, int agility)
    : Unit(id, x, y, hp), strength(strength), range(range), agility(agility) {}

bool Archer::Act(Map& map, int current_tick) {
    // Range attack logic
    if (RangeAttack::Attack(*this, range, agility, map, current_tick)) {
        return true;
    }

    // Melee attack logic
    if (MeleeAttack::Attack(*this, strength, map, current_tick)) {
        return true;
    }

    return Movement::Move(*this, map, current_tick);
}
