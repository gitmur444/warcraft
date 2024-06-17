#include "range_attack.h"
#include "Events/unit_attacked_event.h"
#include "Events/unit_died_event.h"
#include "Events/event_handler.h"
#include <iostream>

bool RangeAttack::Attack(Unit& unit, int range, int damage, Map& map, int current_tick) {
    Unit* target = FindTarget(unit, range, map);
    if (target && (abs(unit.GetX() - target->GetX()) >= 2 || abs(unit.GetY() - target->GetY()) >= 2)) {
        target->TakeDamage(damage);
        EventHandler eventHandler;
        eventHandler.HandleEvent(std::make_shared<UnitAttackedEvent>(unit.GetId(), target->GetId(), damage, target->GetHp()));
        if (target->GetHp() <= 0) {
            eventHandler.HandleEvent(std::make_shared<UnitDiedEvent>(target->GetId()));
            map.SetCellOccupied(target->GetX(), target->GetY(), false);
        }
        return true;
    }
    return false;
}
