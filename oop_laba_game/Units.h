#pragma once

#include "UnitTypes.h"

class Soldier : public Assault {
public:
	Soldier(int x, int y);

	std::string getType() const override;
	std::unique_ptr<Unit> clone() const override;
};

class Pyro : public Assault {
public:
	Pyro(int x, int y);

	std::string getType() const override;
	std::unique_ptr<Unit> clone() const override;
};



class Heavy : public Defense {
public:
	Heavy(int x, int y);

	std::string getType() const override;
	std::unique_ptr<Unit> clone() const override;
};

class Engineer : public Defense {
public:
	Engineer(int x, int y);

	std::string getType() const override;
	std::unique_ptr<Unit> clone() const override;
};



class Medic : public Support {
public:
	Medic(int x, int y);

	std::string getType() const override;
	std::unique_ptr<Unit> clone() const override;
};

class Sniper : public Support {
public:
	Sniper(int x, int y);

	std::string getType() const override;
	std::unique_ptr<Unit> clone() const override;
};



