#include "warrior.h"
#include "map.h"
#include "movement.h"
#include "melee_attack.h"  
#include <iostream>

Warrior::Warrior(int id, int x, int y, int hp, int strength) : Unit(id, x, y, hp), strength(strength) {}

bool Warrior::Act(Map& map, int current_tick) {
    // Melee attack logic
    if (MeleeAttack::Attack(*this, strength, map, current_tick)) {
        return true;
    }

    return Movement::Move(*this, map, current_tick);
}
