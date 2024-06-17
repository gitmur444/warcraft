#pragma once

#include "event.h"

class UnitAttackedEvent : public Event {
public:
    UnitAttackedEvent(int attackerId, int targetId, int damage, int targetHp);
    std::string ToString() const override;

private:
    int attackerId;
    int targetId;
    int damage;
    int targetHp;
};
