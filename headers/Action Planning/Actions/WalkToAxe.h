#pragma once

#include "../Action.h"

class WalkToAxe : public Action
{
public:
	void applyEffect(World& w) const override;
};
