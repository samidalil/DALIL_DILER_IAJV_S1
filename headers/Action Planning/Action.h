#pragma once

#include "Precondition.h"
#include "../World.h"

class Action
{
public:
	PreconditionMap preconditions;
    int cost = 0;
public:
	virtual void applyEffect(World& w, PreconditionMap& preconditions) const = 0;
};
