#pragma once

#include <unordered_map>
#include "Action Planning/Precondition.h"
#include "Resource.h"

struct World
{
    std::unordered_map<Resource, bool> resources;
    PreconditionMap conditions;
};
