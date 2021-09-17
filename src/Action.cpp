#include "../headers/Action.h"

Action::Action(std::string name, unsigned int cost, std::unordered_map<Precondition, bool> preconditions,
                      std::vector<Action> childActions, std::function<void()> effect) : name(name), cost(cost), preconditions(preconditions), childActions(childActions), nbUnmetPreconditions(0), effect(effect)
{}

Action& Action::operator=(const Action &a) {
    this->name = a.name;
    this->cost = a.cost;
    this->preconditions = a.preconditions;
    this->nbUnmetPreconditions = a.nbUnmetPreconditions;
    this->childActions = a.childActions;
    this->effect = a.effect;

    return *this;

}

void Action::updateUnmetPreconditions(PlayerState &playerState) {

    this->nbUnmetPreconditions = this->preconditions.size();
    for(auto precondition : this->preconditions)
    {
        bool playerConditionState = playerState.preconditions.find(precondition.first)->second;
        if(precondition.second == playerConditionState)
        {
            this->nbUnmetPreconditions--;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Action& a) {
    os << a.name;
    return os;

}
