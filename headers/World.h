#pragma once

#include "Resource.h"

struct World
{
	std::unordered_map<Resource, unsigned int> resources;
};
