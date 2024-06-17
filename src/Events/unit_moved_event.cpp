#include "unit_moved_event.h"

UnitMovedEvent::UnitMovedEvent(int unitId, int x, int y) : unitId(unitId), x(x), y(y) {}

std::string UnitMovedEvent::ToString() const {
    return "UNIT_MOVED unitId=" + std::to_string(unitId) + " x=" + std::to_string(x) + " y=" + std::to_string(y);
}
