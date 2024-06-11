#include "attack.h"
#include <iostream>

Unit* Attack::FindTarget(Unit& unit, int range, Map& map) {
    int x = unit.GetX();
    int y = unit.GetY();
    Unit* target = nullptr;
    for (int dx = -range; dx <= range; ++dx) {
        for (int dy = -range; dy <= range; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int newX = x + dx;
            int newY = y + dy;
            Unit* potential_target = map.GetUnitAt(newX, newY);
            if (potential_target && potential_target->GetId() != unit.GetId() && potential_target->GetHp() > 0) {
                if (!target || potential_target->GetHp() < target->GetHp() || 
                    (potential_target->GetHp() == target->GetHp() && potential_target->GetId() < target->GetId())) {
                    target = potential_target;
                }
            }
        }
    }
    return target;
}

void Attack::PerformAttack(Unit& attacker, Unit* target, int damage, Map& map, int current_tick) {
    if (target) {
        target->TakeDamage(damage);
        std::cout << "[" << current_tick << "] UNIT_ATTACKED attackerUnitId=" << attacker.GetId() << " targetUnitId=" << target->GetId() 
                  << " damage=" << damage << " targetHp=" << target->GetHp() << std::endl;
        if (target->GetHp() <= 0) {
            std::cout << "[" << current_tick << "] UNIT_DIED unitId=" << target->GetId() << std::endl;
            map.SetCellOccupied(target->GetX(), target->GetY(), false);
        }
    }
}
