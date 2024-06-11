#pragma once

#include "map.h"
#include "unit.h"

class Movement {
public:
    static bool Move(Unit& unit, Map& map, int current_tick);
};
