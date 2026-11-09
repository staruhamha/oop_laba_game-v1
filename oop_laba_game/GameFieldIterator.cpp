#include "GameFieldIterator.h"

GameFieldIterator::GameFieldIterator(GameField& field) : field(field), position(0) {

}

bool GameFieldIterator::hasNext() const {
	return position < field.units.size();
}

Unit* GameFieldIterator::next() {
	if (!hasNext()) {
		return nullptr;
	}

	return field.units[position++].get();
}

void GameFieldIterator::reset() {
	position = 0;
}

Unit* GameFieldIterator::operator*() const {
	if (position >= field.units.size()) {
		return nullptr;
	}
	return field.units[position].get();
}

GameFieldIterator& GameFieldIterator::operator++() {
	if (position < field.units.size()) {
		position++;
	}
	return *this;
}

void GameFieldIterator::removeCurrent() {
	if (position == 0) {
		return;
	}
	field.removeUnit(static_cast<int>(position - 1));
	position--;
}