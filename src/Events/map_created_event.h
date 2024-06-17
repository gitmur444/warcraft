#pragma once

#include "event.h"

class MapCreatedEvent : public Event {
public:
    MapCreatedEvent(int width, int height);
    std::string ToString() const override;

private:
    int width;
    int height;
};
