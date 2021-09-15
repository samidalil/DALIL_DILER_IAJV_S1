#pragma once

#include "../Action.h"

class WalkToTree : public Action
{
public:
    void applyEffect(World& w, PreconditionMap& preconditions) const override;

};
