#include "Attack.h"
#include <cstdlib>

int validateDamage(int damage) {
	if (damage >= 0) {
		return damage;
	}
	return 0;
}

Attack::Attack(int damage) : damage(validateDamage(damage)){}

int Attack::getDamage() const {
	return damage;
}

void Attack::setDamage(int newDamage){
	damage = validateDamage(newDamage);
}

int Attack::calculateDamage(int enemyArmor) const {
	if (enemyArmor < 0) {
		enemyArmor = 0;
	}

	int result = damage - enemyArmor + (rand() % 3 - 1);
	if (result < 0) {
		return 0;
	}
	return result;
	
}