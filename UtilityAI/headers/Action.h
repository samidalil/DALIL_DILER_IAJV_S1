#pragma once

#include "states/AgentState.h"
#include "states/WorldState.h"
#include <vector>

class Action
{

public:
    int factor;
    std::unordered_map<unsigned int, unsigned int > evaluations;
    void addEvaluation(std::pair<unsigned int,unsigned int > eval);

    float Evaluate() const;
    virtual void Execute(Agent& a) const = 0;
    //virtual float Evaluate(T& resource, World& w) const;
    //virtual void Execute(Agent& a) const;
};