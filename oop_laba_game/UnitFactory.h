#pragma once

#include <memory>
#include "Unit.h"
#include <string>

class UnitFactory {
public:
	virtual ~UnitFactory();
	virtual std::unique_ptr<Unit> createUnit(int x, int y, const std::string& type) const = 0;
};