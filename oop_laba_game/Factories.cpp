#include "Factories.h"
#include "Units.h"
using namespace std;

unique_ptr<Unit> AssaultFactory::createUnit(int x, int y, const string& type) const {
	if (type == "Soldier") {
		return make_unique<Soldier>(x, y);
	}
	if (type == "Pyro") {
		return make_unique<Pyro>(x, y);
	}

	return nullptr;
}

unique_ptr<Unit> SupportFactory::createUnit(int x, int y, const string& type) const {
	if (type == "Medic") {
		return make_unique<Medic>(x, y);
	}
	if (type == "Sniper") {
		return make_unique<Sniper>(x, y);
	}

	return nullptr;
}

unique_ptr<Unit> DefenseFactory::createUnit(int x, int y, const string& type) const {
	if (type == "Heavy") {
		return make_unique<Heavy>(x, y);
	}
	if (type == "Engineer") {
		return make_unique<Engineer>(x, y);
	}

	return nullptr;
}