#include "warrior.h"
#include "map.h"
#include "movement.h"
#include "melee_attack.h"

Warrior::Warrior(int id, int x, int y, int hp, int strength) : Unit(id, x, y, hp), strength(strength) {}

bool Warrior::Act(Map& map, std::vector<std::unique_ptr<Unit>>& units, int current_tick) {
    if (MeleeAttack::Attack(*this, strength, map, units, current_tick)) {
        return true;
    }

    return Movement::Move(*this, map, current_tick);
}
