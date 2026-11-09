#pragma once

class Health {
private:
	int currentHealth;
	int maxHealth;

public:
	Health(int maxHealth);

	int getCurrentHealth() const;
	int getMaxHealth() const;

	void setCurrentHealth(int health);

	void increase(int amount);
	void decrease(int amount);
	bool isZero() const;
};