#pragma once

#include <vector>

class Unit;  

class Map {
public:
    Map(int width, int height);
    bool IsCellOccupied(int x, int y) const;
    void SetCellOccupied(int x, int y, bool occupied);
    Unit* GetUnitAt(int x, int y);
    void AddUnit(Unit* unit); 

private:
    int width;
    int height;
    std::vector<std::vector<bool>> cells;
    std::vector<Unit*> unit_map;
};
