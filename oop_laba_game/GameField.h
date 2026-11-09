#pragma once

#include <memory>
#include <vector>
#include "Unit.h"
#include <string>

class UnitFactory;
class GameFieldIterator;

class GameField {
	friend class GameFieldIterator;
private:
	int width;
	int height;
	int maxUnits;
	std::vector<std::unique_ptr<Unit>> units;

public:
	GameField(int width, int height);
	~GameField() = default;

	GameField(const GameField& other);
	GameField& operator=(const GameField& other);

	GameField(GameField&& other) noexcept;
	GameField& operator=(GameField&& other) noexcept;


	int getWidth() const;
	int getHeight() const;
	int getUnitCount() const;
	int size() const;
	bool empty() const;
	void clear();
	Unit* getUnit(int index) const;

	void addUnit(std::unique_ptr<Unit> unit);
	void removeUnit(int index);
	void fill(const UnitFactory& factory, const std::vector<std::string> & types);
		
	void printField() const;
};