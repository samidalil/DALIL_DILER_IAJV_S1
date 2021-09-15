#pragma once

#include "Precondition.h"
#include "../World.h"

class Action
{
public:
	PreconditionMap preconditions;
public:
	virtual void applyEffect(World& w, PreconditionMap& preconditions) const = 0;
};
