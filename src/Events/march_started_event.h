#pragma once

#include "event.h"

class MarchStartedEvent : public Event {
public:
    MarchStartedEvent(int id, int x, int y, int targetX, int targetY);
    std::string ToString() const override;

private:
    int id;
    int x;
    int y;
    int targetX;
    int targetY;
};
