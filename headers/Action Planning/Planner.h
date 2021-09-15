#pragma once

#include "../World.h"

class Planner
{
private:

public:
	void DeInit();
	void Init();
	void Planning(const World& w) const;
};