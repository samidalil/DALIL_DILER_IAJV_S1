#include "../headers/Action.h"

Action::Action(std::string name, unsigned int cost, std::unordered_map<Precondition, bool> preconditions,
                      std::vector<Action> childActions, std::function<void()> effect) : name(name), cost(cost), preconditions(preconditions), childActions(childActions), nbPreconditions(0), effect(effect)
{
    for(auto precondition : preconditions)
    {
        if(precondition.second)
            nbPreconditions++;
    }
}
