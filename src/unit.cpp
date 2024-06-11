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

int Unit::GetTargetX() const {
    return targetX;
}

int Unit::GetTargetY() const {
    return targetY;
}

void Unit::SetTarget(int targetX, int targetY) {
    this->targetX = targetX;
    this->targetY = targetY;
}

void Unit::SetPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Unit::TakeDamage(int damage) {
    hp -= damage;
}
