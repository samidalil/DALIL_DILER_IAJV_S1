#include "../headers/Action.h"

Action::Action(std::string name, unsigned int cost, std::unordered_map<Precondition, bool> preconditions,
                      std::vector<Action> childActions) : name(name), cost(cost), preconditions(preconditions), nbPreconditions(0)
{
    for(auto precondition : preconditions)
    {
        if(precondition.second)
            nbPreconditions++;
    }
}
