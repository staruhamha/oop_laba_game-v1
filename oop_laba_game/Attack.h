#pragma once

class Attack {
private:
	int damage;

public:
	Attack(int damage);

	int getDamage() const;
	void setDamage(int damage);
	
	int calculateDamage(int enemyArmor) const;
};