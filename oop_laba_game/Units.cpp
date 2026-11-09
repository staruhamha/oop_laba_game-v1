#include "Units.h"
using namespace std;

Soldier::Soldier(int x, int y) : Assault(x, y, Health(200), Armor(50), Attack(20)) {

}

string Soldier::getType() const {
	return "Soldier";
}

unique_ptr<Unit> Soldier::clone() const {
	return make_unique<Soldier>(*this);
}



Pyro::Pyro(int x, int y) : Assault(x, y, Health(150), Armor(30), Attack(35)) {

}

string Pyro::getType() const {
	return "Pyro";
}

unique_ptr<Unit> Pyro::clone() const {
	return make_unique<Pyro>(*this);
}



Heavy::Heavy(int x, int y) : Defense(x, y, Health(300), Armor(100), Attack(25)) {

}

string Heavy::getType() const {
	return "Heavy";
}

unique_ptr<Unit> Heavy::clone() const {
	return make_unique<Heavy>(*this);
}





Engineer::Engineer(int x, int y) : Defense(x, y, Health(180), Armor(120), Attack(15)) {

}

string Engineer::getType() const {
	return "Engineer";
}

unique_ptr<Unit> Engineer::clone() const {
	return make_unique<Engineer>(*this);
}



Sniper::Sniper(int x, int y) : Support(x, y, Health(120), Armor(15), Attack(60)) {

}

string Sniper::getType() const {
	return "Sniper";
}

unique_ptr<Unit> Sniper::clone() const {
	return make_unique<Sniper>(*this);
}


Medic::Medic(int x, int y) : Support(x, y, Health(150), Armor(20), Attack(10)) {

}

string Medic::getType() const {
	return "Medic";
}

unique_ptr<Unit> Medic::clone() const {
	return make_unique<Medic>(*this);
}


