#include "unit_attacked_event.h"

UnitAttackedEvent::UnitAttackedEvent(int attackerId, int targetId, int damage, int targetHp) : attackerId(attackerId), targetId(targetId), damage(damage), targetHp(targetHp) {}

std::string UnitAttackedEvent::ToString() const {
    return "UNIT_ATTACKED attackerUnitId=" + std::to_string(attackerId) + " targetUnitId=" + std::to_string(targetId) + " damage=" + std::to_string(damage) + " targetHp=" + std::to_string(targetHp);
}
