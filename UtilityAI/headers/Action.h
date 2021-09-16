#pragma once

#include "states/AgentState.h"
#include "states/WorldState.h"
#include "Utils.h"

class Action
{

public:
    int factor;
    virtual float Evaluate(Agent& a, World& w) const;
    virtual void Execute(Agent& a) const;
};