#pragma once

#include "GameField.h"

class GameFieldIterator {
private:
	GameField& field;
	size_t position;

public: 
	GameFieldIterator(GameField& field);

	bool hasNext() const;
	Unit* next();
	void reset();
	void removeCurrent();
	Unit* operator*() const;
	GameFieldIterator& operator++();
};	