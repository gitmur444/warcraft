#include "movement.h"
#include "Events/unit_moved_event.h"
#include "Events/event_handler.h"
#include <iostream>

bool Movement::Move(Unit& unit, Map& map, int current_tick) {
    int x = unit.GetX();
    int y = unit.GetY();
    int targetX = unit.GetTargetX();
    int targetY = unit.GetTargetY();

    if (x != targetX || y != targetY) {
        int newX = x + (targetX > x ? 1 : targetX < x ? -1 : 0);
        int newY = y + (targetY > y ? 1 : targetY < y ? -1 : 0);
        if (!map.IsCellOccupied(newX, newY)) {
            map.SetCellOccupied(x, y, false);
            unit.SetPosition(newX, newY);
            map.SetCellOccupied(newX, newY, true);
            EventHandler eventHandler;
            eventHandler.HandleEvent(std::make_shared<UnitMovedEvent>(unit.GetId(), newX, newY));
            return true;
        }
    }
    return false;
}
