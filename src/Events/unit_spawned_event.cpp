#include "unit_spawned_event.h"

UnitSpawnedEvent::UnitSpawnedEvent(int id, const std::string& unitType, int x, int y) : id(id), unitType(unitType), x(x), y(y) {}

std::string UnitSpawnedEvent::ToString() const {
    return "UNIT_SPAWNED unitId=" + std::to_string(id) + " unitType=" + unitType + " x=" + std::to_string(x) + " y=" + std::to_string(y);
}
