#pragma once

#include "event.h"

class UnitMovedEvent : public Event {
public:
    UnitMovedEvent(int unitId, int x, int y);
    std::string ToString() const override;

private:
    int unitId;
    int x;
    int y;
};
