#pragma once

#include "../Action.h"

class HarvestWoodAction : public Action
{
public:
	void applyEffect(World& w, PreconditionMap& preconditions) const override;
};
