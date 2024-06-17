#pragma once

#include "event.h"
#include <string>

class UnitSpawnedEvent : public Event {
public:
    UnitSpawnedEvent(int id, const std::string& unitType, int x, int y);
    std::string ToString() const override;

private:
    int id;
    std::string unitType;
    int x;
    int y;
};
