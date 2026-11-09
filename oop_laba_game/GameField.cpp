#include "GameField.h"
#include <utility>
#include "UnitFactory.h"
#include <iostream>
using namespace std;

GameField::GameField(const GameField& other) : width(other.width), height(other.height), maxUnits(other.maxUnits) {

	for (const auto& unit : other.units) {
		units.push_back(unit->clone());
	}
}

GameField& GameField::operator=(const GameField& other) {
	if (this == &other) {
		return *this;
	}
	width = other.width;
	height = other.height;

	maxUnits = other.maxUnits;

	units.clear();
	for (const auto& unit : other.units) {
		units.push_back(unit->clone());

	}
	return *this;
}
GameField::GameField(GameField&& other) noexcept : width(other.width), height(other.height), maxUnits(other.maxUnits), units(move(other.units)) {
	other.width = 0;
	other.height = 0;
	other.maxUnits = 0;
}

GameField& GameField::operator=(GameField&& other) noexcept {
	if (this != &other) {
		width = other.width;
		height = other.height;

		maxUnits = other.maxUnits;
		units = move(other.units);
		other.width = 0;
		other.height = 0;
		other.maxUnits = 0;
	}
	return *this;
}

GameField::GameField(int width, int height) : width(width), height(height), maxUnits(width * height) {}

int GameField::getWidth() const {
	return width;
}

int GameField::getHeight() const {
	return height;
}

int GameField::getUnitCount() const {
	return static_cast<int>(units.size());
}
int GameField::size() const {
	return static_cast<int>(units.size());
}
bool GameField::empty() const {
	return units.empty();
}
void GameField::clear() {
	units.clear();
}

Unit* GameField::getUnit(int index) const {
	if (index < 0 || index >= units.size()) {
		return nullptr;
	}
	return units[index].get();
}
void GameField::addUnit(unique_ptr<Unit> unit) {
	if (units.size() >= maxUnits || unit == nullptr) {
		return;
	}
	if ((unit->getX() < 0) || (unit->getX() >= width) || (unit->getY() < 0) || (unit->getY() >= height)) {
		return;
	}

	units.push_back(move(unit));
}
void GameField::removeUnit(int index) {
	if (index < 0 || index >= units.size()) {
		return;
	}
	units.erase(units.begin() + index);
}

void GameField::fill(const UnitFactory& factory, const vector<string>& types) {
	for (const string& type : types) {
		if (width <= 0 || size() >= maxUnits) {
			break;
		}
		int x = size() % width;
		int y = size() / width;
		addUnit(factory.createUnit(x, y, type));
	}
}

void GameField::printField() const {
	for (int x = 0; x <= width; x++) {
		cout << "X ";
	}
	cout << "X\n";
	for (int y = 0; y < height; y++) {
		cout << "X ";

		for (int x = 0; x < width; x++) {
			char symbol = ' ';
			
			for (const auto& unit : units) {
				if (unit->getX() == x && unit->getY() == y) {
					string type = unit->getType();

					if (type == "Soldier") {
						symbol = 'S';
					}
					else if (type == "Pyro") {
						symbol = 'P';

					}
					else if (type == "Heavy") {
						symbol = 'H';
					}
					else if (type == "Engineer") {
						symbol = 'E';
					}
					else if (type == "Medic") {
						symbol = 'M';
					}
					else if (type == "Sniper") {
						symbol = 'N';
					}
					break;
				}
			}
			cout << symbol << " ";
		}
		cout << "X\n";
	}
	for (int x = 0; x <= width; x++) {
		cout << "X ";
	}
	cout << "X\n";
}