#include "unit.h"

Unit::Unit(int id, int x, int y, int hp, int strength) : id_(id), x_(x), y_(y), hp_(hp), strength_(strength) {}

int Unit::getId() const {
    return id_;
}

int Unit::getX() const {
    return x_;
}

int Unit::getY() const {
    return y_;
}

int Unit::getHp() const {
    return hp_;
}

int Unit::getStrength() const {
    return strength_;
}

void Unit::setPosition(int x, int y) {
    x_ = x;
    y_ = y;
}

void Unit::takeDamage(int damage) {
    hp_ -= damage;
}
