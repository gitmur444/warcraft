#pragma once
#include <string>

class Unit {
public:
    Unit(int id, int x, int y, int hp, int strength);
    virtual ~Unit() = default;
    int getId() const;
    int getX() const;
    int getY() const;
    int getHp() const;
    int getStrength() const;
    void setPosition(int x, int y);
    void takeDamage(int damage);
    virtual std::string getType() const = 0;

protected:
    int id_;
    int x_;
    int y_;
    int hp_;
    int strength_;
};
