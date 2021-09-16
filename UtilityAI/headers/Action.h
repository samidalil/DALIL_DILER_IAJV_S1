#pragma once

#include "states/AgentState.h"
#include "states/WorldState.h"
#include "Utils.h"


class Action
{

public:
    int factor;
    template <typename T>
    virtual float Evaluate(T& resource, World& w) const;
    virtual void Execute(Agent& a) const;

    template <typename T>
    float Evalutate(std::vector<T&> resources, World& w) const
    {
        std::vector<float> vals;
        for(resource : resources)
        {
            vals.push_back(Utils::linear(0, w.nbGoalPopulation, resource));
        }
        return Utils::average(vals);

    }
};