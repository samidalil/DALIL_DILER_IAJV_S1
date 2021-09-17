#include "../../headers/States/PlayerState.h"

PlayerState::PlayerState(const std::unordered_map<Resource, unsigned int> &resources,
                         const std::unordered_map<Precondition, unsigned int> &preconditions) {
    this->resources = resources;
    this->preconditions = preconditions;
}


void PlayerState::updatePreconditions(std::pair<Precondition, unsigned int> condition) {
    preconditions.find(condition.first)->second = condition.second;
}

void PlayerState::updateResources(std::pair<Resource, unsigned int> resource) {
    resources.find(resource.first)->second = resource.second;
}