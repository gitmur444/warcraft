#pragma once

#include "attack.h"

class MeleeAttack : public Attack {
public:
    static bool Attack(Unit& unit, int damage, Map& map, int current_tick);
};
