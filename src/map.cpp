#include "map.h"
#include "unit.h"

Map::Map(int width, int height) : width(width), height(height), cells(width, std::vector<bool>(height, false)) {}

bool Map::IsCellOccupied(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) return true;
    return cells[x][y];
}

void Map::SetCellOccupied(int x, int y, bool occupied) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        cells[x][y] = occupied;
    }
}

Unit* Map::GetUnitAt(int x, int y) {
    for (auto& unit : unit_map) {
        if (unit->GetX() == x && unit->GetY() == y) {
            return unit;
        }
    }
    return nullptr;
}

void Map::AddUnit(Unit* unit) {
    unit_map.push_back(unit);
}
