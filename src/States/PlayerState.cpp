#include "../../headers/States/PlayerState.h"

PlayerState::PlayerState(const std::unordered_map<Resource, unsigned int> &resources,
                         const std::unordered_map<Precondition, unsigned int> &preconditions) {
    this->resources = resources;
    this->preconditions = preconditions;
}