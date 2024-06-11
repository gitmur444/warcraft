#include "archer.h"
#include "map.h"
#include <iostream>

Archer::Archer(int id, int x, int y, int hp, int strength, int range, int agility)
    : Unit(id, x, y, hp), strength(strength), range(range), agility(agility) {}

bool Archer::Act(Map& map, int current_tick) {
    // Range attack logic
    Unit* target = nullptr;
    for (int dx = -range; dx <= range; ++dx) {
        for (int dy = -range; dy <= range; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int newX = x + dx;
            int newY = y + dy;
            Unit* potential_target = map.GetUnitAt(newX, newY);
            if (potential_target && potential_target->GetId() != id && potential_target->GetHp() > 0 &&
                (abs(dx) >= 2 || abs(dy) >= 2)) {
                if (!target || potential_target->GetHp() < target->GetHp() || 
                    (potential_target->GetHp() == target->GetHp() && potential_target->GetId() < target->GetId())) {
                    target = potential_target;
                }
            }
        }
    }

    if (target) {
        target->TakeDamage(agility);
        std::cout << "[" << current_tick << "] UNIT_ATTACKED attackerUnitId=" << id << " targetUnitId=" << target->GetId() 
                  << " damage=" << agility << " targetHp=" << target->GetHp() << std::endl;
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
