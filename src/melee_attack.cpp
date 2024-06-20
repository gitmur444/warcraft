#include "melee_attack.h"
#include "Events/unit_attacked_event.h"
#include "Events/unit_died_event.h"
#include "Events/event_handler.h"
#include <algorithm>
#include <iostream>

bool MeleeAttack::Attack(Unit& unit, int damage, Map& map, std::vector<std::unique_ptr<Unit>>& units, int current_tick) {
    Unit* target = FindTarget(unit, 1, map);
    if (target) {
        target->TakeDamage(damage);
        EventHandler eventHandler;
        eventHandler.HandleEvent(std::make_shared<UnitAttackedEvent>(unit.GetId(), target->GetId(), damage, target->GetHp()));
        if (target->GetHp() <= 0) {
            eventHandler.HandleEvent(std::make_shared<UnitDiedEvent>(target->GetId()));
            map.SetCellOccupied(target->GetX(), target->GetY(), false);

            auto it = std::remove_if(units.begin(), units.end(), [id = target->GetId()](const std::unique_ptr<Unit>& u) {
                return u->GetId() == id;
            });
            if (it != units.end()) {
                units.erase(it, units.end());
            }
        }
        return true;
    }
    return false;
}
