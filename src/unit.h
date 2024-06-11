#pragma once

class Map;  // ??????????????? ?????????? ?????? Map

class Unit {
public:
    Unit(int id, int x, int y, int hp);
    virtual ~Unit() = default;

    int GetId() const;
    int GetX() const;
    int GetY() const;
    int GetHp() const;
    void SetTarget(int targetX, int targetY);
    void TakeDamage(int damage);
    virtual bool Act(Map& map, int current_tick) = 0;

protected:
    int id;
    int x, y;
    int targetX, targetY;
    int hp;
};
