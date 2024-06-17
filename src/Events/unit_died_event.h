#pragma once

#include "event.h"

class UnitDiedEvent : public Event {
public:
    UnitDiedEvent(int unitId);
    std::string ToString() const override;

private:
    int unitId;
};
