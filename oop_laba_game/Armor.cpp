#include "Armor.h"

int validateArmor(int armor) {
	if (armor > 0) {
		return armor;
	}

	return 1;
}
Armor::Armor(int maxArmor) : currentArmor(validateArmor(maxArmor)), maxArmor(validateArmor(maxArmor)) {}

int Armor::getCurrentArmor() const {
	return currentArmor;
}

int Armor::getMaxArmor() const {
	return maxArmor;
}

void Armor::setCurrentArmor(int armor) {
	if (armor < 0) {
		currentArmor = 0;
	}
	else if (armor > maxArmor) {
		currentArmor = maxArmor;
	}
	else {
		currentArmor = armor;
	}
	
}

bool Armor::isZero() const {
	return currentArmor == 0;
}

void Armor::increase(int amount) {
	if (amount <= 0) return;
	currentArmor += amount;

	if (currentArmor > maxArmor) {
		currentArmor = maxArmor;
	}
}

void Armor::decrease(int amount) {
	if (amount <= 0) return;
	currentArmor -= amount;

	if (currentArmor < 0) {
		currentArmor = 0;
	}
}

int Armor::reduceDamage(int damage) {
	if (damage <= 0 || currentArmor == 0) {
		return damage;
	}
	int reduceDamage = damage / 2;
	int armorUsed = damage - reduceDamage;

	if (armorUsed > currentArmor) {
		armorUsed = currentArmor;
		reduceDamage = damage - armorUsed;

	}
	currentArmor -= armorUsed;
	return reduceDamage;
}