#pragma once

#include "Enums/Preconditions.h"

#include <unordered_map>
#include <vector>
#include <functional>

class Action
{
public:
    std::string name;
    unsigned int cost;
    std::unordered_map<Precondition, bool> preconditions; //preconditions REQUIRED for that action (that are true or false, not all of them)
    unsigned int nbPreconditions;
    std::vector<Action> childActions;
public:
    std::function<void()> effect;
    Action(std::string name, unsigned int cost, std::unordered_map<Precondition, bool> preconditions, std::vector<Action> childActions,
           std::function<void()> effect);
};