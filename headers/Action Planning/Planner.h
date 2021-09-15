#pragma once

#include <vector>
#include "../World.h"
#include "../action.h"

class Planner
{
private:

public:
	void DeInit();
	void Init(std::vector<Action*>& actions);
	void Planning(const World& w) const;
};