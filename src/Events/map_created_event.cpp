#include "map_created_event.h"

MapCreatedEvent::MapCreatedEvent(int width, int height) : width(width), height(height) {}

std::string MapCreatedEvent::ToString() const {
    return "MAP_CREATED width=" + std::to_string(width) + " height=" + std::to_string(height);
}
