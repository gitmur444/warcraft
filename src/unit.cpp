#include "unit.h"

Unit::Unit(int id, int x, int y, int hp) : id(id), x(x), y(y), targetX(x), targetY(y), hp(hp) {}

int Unit::GetId() const {
    return id;
}

int Unit::GetX() const {
    return x;
}

int Unit::GetY() const {
    return y;
}

int Unit::GetHp() const {
    return hp;
}

void Unit::SetTarget(int targetX, int targetY) {
    this->targetX = targetX;
    this->targetY = targetY;
}

void Unit::TakeDamage(int damage) {
    hp -= damage;
}
