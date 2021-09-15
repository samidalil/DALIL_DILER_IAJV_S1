#pragma once

#include "../Action.h"

class PickUpAxe : public Action
{
public:
    void applyEffect(World& w, PreconditionMap& preconditions) const override;
};
