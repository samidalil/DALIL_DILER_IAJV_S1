#pragma once

#include <unordered_map>

enum PreconditionType
{
	HAS_AXE,
	IN_RANGE,
	HAS_500_WOOD,
	HAS_1000_WOOD
};

using PreconditionMap = std::unordered_map<PreconditionType, bool>;
