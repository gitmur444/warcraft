#include "unit_died_event.h"

UnitDiedEvent::UnitDiedEvent(int unitId) : unitId(unitId) {}

std::string UnitDiedEvent::ToString() const {
    return "UNIT_DIED unitId=" + std::to_string(unitId);
}
