#include "warrior.h"
#include "map.h"
#include <iostream>

Warrior::Warrior(int id, int x, int y, int hp, int strength) : Unit(id, x, y, hp), strength(strength) {}

bool Warrior::Act(Map& map, int current_tick) {
    // Melee attack logic
    Unit* target = nullptr;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int newX = x + dx;
            int newY = y + dy;
            Unit* potential_target = map.GetUnitAt(newX, newY);
            if (potential_target && potential_target->GetId() != id && potential_target->GetHp() > 0) {
                if (!target || potential_target->GetHp() < target->GetHp() || 
                    (potential_target->GetHp() == target->GetHp() && potential_target->GetId() < target->GetId())) {
                    target = potential_target;
                }
            }
        }
    }

    if (target) {
        target->TakeDamage(strength);
        std::cout << "[" << current_tick << "] UNIT_ATTACKED attackerUnitId=" << id << " targetUnitId=" << target->GetId() 
                  << " damage=" << strength << " targetHp=" << target->GetHp() << std::endl;
        if (target->GetHp() <= 0) {
            std::cout << "[" << current_tick << "] UNIT_DIED unitId=" << target->GetId() << std::endl;
            map.SetCellOccupied(target->GetX(), target->GetY(), false);
        }
        return true;
    }

    // Movement logic
    if (x != targetX || y != targetY) {
        int newX = x + (targetX > x ? 1 : targetX < x ? -1 : 0);
        int newY = y + (targetY > y ? 1 : targetY < y ? -1 : 0);
        if (!map.IsCellOccupied(newX, newY)) {
            map.SetCellOccupied(x, y, false);
            x = newX;
            y = newY;
            map.SetCellOccupied(x, y, true);
            std::cout << "[" << current_tick << "] UNIT_MOVED unitId=" << id << " x=" << x << " y=" << y << std::endl;
            return true;
        }
    }
    return false;
}
