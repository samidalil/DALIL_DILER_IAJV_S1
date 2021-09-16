#pragma once

#include <unordered_map>

#include "../Enums/Preconditions.h"
#include "../Enums/Resources.h"

class PlayerState{

public:
    std::unordered_map<Resource,unsigned int> resources;
    std::unordered_map<Precondition, unsigned int> preconditions;
public:
    PlayerState(const std::unordered_map<Resource,unsigned int>& resources, const std::unordered_map<Precondition,unsigned int>& preconditions);
    void updatePreconditions(); //TODO implement
    void updateResources(); //TODO implement
};