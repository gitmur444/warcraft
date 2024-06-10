#include "map.h"

Map::Map(int width, int height) : width_(width), height_(height), cells_(height, std::vector<int>(width, -1)) {}

bool Map::isCellEmpty(int x, int y) const {
    return cells_[y][x] == -1;
}

void Map::setCell(int x, int y, int unitId) {
    cells_[y][x] = unitId;
}

void Map::clearCell(int x, int y) {
    cells_[y][x] = -1;
}

int Map::getWidth() const {
    return width_;
}

int Map::getHeight() const {
    return height_;
}
