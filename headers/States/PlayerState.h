#pragma once

#include <unordered_map>

#include "../Precondition.h"

class PlayerState{

public:
    std::unordered_map<Resource,unsigned int> resources;
    std::unordered_map<Precondition, unsigned int> preconditions;
public:
    PlayerState(const std::unordered_map<Resource,unsigned int>& resources, const std::unordered_map<Precondition,unsigned int>& preconditions);
};