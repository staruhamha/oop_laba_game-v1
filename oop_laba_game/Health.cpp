#include "Health.h"

int validateHealth(int health) {
	if (health > 0) {
		return health;
	}

	return 1;
}

Health::Health(int maxHealth) : currentHealth(validateHealth(maxHealth)), maxHealth(validateHealth(maxHealth)) {}

int Health::getCurrentHealth() const{
	return currentHealth;
}

int Health::getMaxHealth() const {
	return maxHealth;
}

void Health::setCurrentHealth(int health) {
	if (health < 0) {
		currentHealth = 0;
	}
	else if (health > maxHealth) {
		currentHealth = maxHealth;
	}
	else {
		currentHealth = health;
	}
	
}


bool Health::isZero() const {
	return currentHealth == 0;
}

void Health::increase(int amount) {
	if (amount <= 0) return;
	currentHealth += amount;

	if (currentHealth > maxHealth) {
		currentHealth = maxHealth;
	}
}

void Health::decrease(int amount) {
	if (amount <= 0) return;
	currentHealth -= amount;

	if (currentHealth < 0) {
		currentHealth = 0;
	}
}