#pragma once
#include <vector>

class Map {
public:
    Map() = default;  // ???????? ??????????? ?? ?????????
    Map(int width, int height);
    bool isCellEmpty(int x, int y) const;
    void setCell(int x, int y, int unitId);
    void clearCell(int x, int y);
    int getWidth() const;
    int getHeight() const;

private:
    int width_;
    int height_;
    std::vector<std::vector<int>> cells_;
};
