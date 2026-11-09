#pragma once

#include "UnitFactory.h"

class AssaultFactory : public UnitFactory {
public:
	std::unique_ptr<Unit> createUnit(int x, int y, const std::string& type) const override;
};

class SupportFactory : public UnitFactory {
public:
	std::unique_ptr<Unit> createUnit(int x, int y, const std::string& type) const override;
};

class DefenseFactory : public UnitFactory {
public:
	std::unique_ptr<Unit> createUnit(int x, int y, const std::string& type) const override;
};
