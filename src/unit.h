#pragma once

#include <vector>
#include <memory>
class Map;

class Unit {
public:
    Unit(int id, int x, int y, int hp);
    virtual ~Unit() = default;

    int GetId() const;
    int GetX() const;
    int GetY() const;
    int GetHp() const;
    int GetTargetX() const;  
    int GetTargetY() const;  
    void SetTarget(int targetX, int targetY);
    void SetPosition(int x, int y);  
    void TakeDamage(int damage);
    virtual bool Act(Map& map, std::vector<std::unique_ptr<Unit>>& units, int current_tick) = 0;

protected:
    int id;
    int x, y;
    int targetX, targetY;
    int hp;
};
