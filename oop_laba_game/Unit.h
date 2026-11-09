#pragma once

#include <memory>
#include <string>
#include "Health.h"
#include "Armor.h"
#include "Attack.h"


class Unit {
private:
	int x;
	int y;

	Health health;
	Armor armor;
	Attack attack;
public:
	Unit(int x, int y, const Health& health, const Armor& armor, const Attack& attack);
	virtual ~Unit();

	int getX() const;
	int getY() const;

	const Health& getHealth() const;
	const Armor& getArmor() const;
	const Attack& getAttack() const;

	void move(int dx, int dy);
	virtual std::string getType() const = 0;
	virtual std::unique_ptr<Unit> clone() const = 0;

	void takeDamage(int damage);
	int calculateDamage() const;

	void attackUnit(Unit& target) const;
};