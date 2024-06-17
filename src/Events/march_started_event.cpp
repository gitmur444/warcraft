#include "march_started_event.h"

MarchStartedEvent::MarchStartedEvent(int id, int x, int y, int targetX, int targetY) : id(id), x(x), y(y), targetX(targetX), targetY(targetY) {}

std::string MarchStartedEvent::ToString() const {
    return "MARCH_STARTED unitId=" + std::to_string(id) + " x=" + std::to_string(x) + " y=" + std::to_string(y) + " targetX=" + std::to_string(targetX) + " targetY=" + std::to_string(targetY);
}
