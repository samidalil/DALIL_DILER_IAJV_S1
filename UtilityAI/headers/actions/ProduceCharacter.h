#pragma once

#include "../Action.h"

class ProduceVillager : public Action
{
public:
    float Evaluate(Agent& a, World& w) const override;
    void Execute(Agent& a) const override;
};