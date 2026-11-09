#pragma once

class Armor {
private:
	int currentArmor;
	int maxArmor;

public:
	Armor(int maxArmor);

	int getCurrentArmor() const;
	int getMaxArmor() const;

	void setCurrentArmor(int armor);

	void increase(int amount);
	void decrease(int amount);
	bool isZero() const;

	int reduceDamage(int damage);
};