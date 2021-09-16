#pragma once

#include "../Action.h"

class ProduceWood : public Action
{
public:
    void applyEffect(World& w) const override;
};