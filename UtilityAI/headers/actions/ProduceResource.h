#pragma once

#include "../Action.h"

class ProduceVillager : public Action
{
public:
    template <typename T>
    float Evaluate(T& resource, World& w) const override;
    void Execute(Agent& a) const override;
};