#pragma once

#include "../Action.h"

class BuildHouse : public Action
{
public:
    void applyEffect(World& w, PreconditionMap& preconditions) const override;

};
