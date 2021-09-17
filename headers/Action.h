#pragma once

#include "States/PlayerState.h"
#include "Enums/Preconditions.h"

#include <unordered_map>
#include <vector>
#include <functional>

//generic Action class which defines all the actions
class Action
{
public:
    std::string name; //name of action to show when applying the action
    unsigned int cost; //action cost for calculation of path in reverse A*
    std::unordered_map<Precondition, bool> preconditions; //preconditions REQUIRED for that action (that are true or false, not all of them)
    unsigned int nbUnmetPreconditions; //quantifies the amount of preconditions for this action
    std::vector<Action> childActions; //during reverse A*, sets all the actions for the next paths for that action
    std::vector<Precondition> impactedPreconditions; //shows a positive feedback to pathfinding for the actions' preconditions
public:
    std::function<void()> effect; //stored function passed in parameter which is the effect applied by that action
    Action(std::string name, unsigned int cost, std::unordered_map<Precondition, bool> preconditions, std::vector<Action> childActions,
           std::function<void()> effect);
    void updateUnmetPreconditions(PlayerState& playerState);

    Action& operator=(const Action& a);

    friend std::ostream& operator<<(std::ostream& os, const Action& a);
};