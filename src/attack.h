#pragma once

#include "map.h"
#include "unit.h"

class Attack {
public:
    static Unit* FindTarget(Unit& unit, int range, Map& map);
};
