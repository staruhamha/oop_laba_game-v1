#include "Unit.h"

Unit::Unit(int x, int y, const Health& health, const Armor& armor, const Attack& attack) : x(x), y(y), health(health), armor(armor), attack(attack) {}

Unit::~Unit() = default;

int Unit::getX() const
{
    return x;
}

int Unit::getY() const
{
    return y;
}

const Health& Unit::getHealth() const
{
    return health;
}

const Armor& Unit::getArmor() const
{
    return armor;
}

const Attack& Unit::getAttack() const
{
    return attack;
}

void Unit::move(int dx, int dy)
{
    x += dx;
    y += dy;
}

void Unit::takeDamage(int damage) {
    int remainDamage = armor.reduceDamage(damage);
    health.decrease(remainDamage);
}

int Unit::calculateDamage() const {
    return attack.calculateDamage(0);
}

void Unit::attackUnit(Unit& target) const {
    int damage = calculateDamage();
    target.takeDamage(damage);
}