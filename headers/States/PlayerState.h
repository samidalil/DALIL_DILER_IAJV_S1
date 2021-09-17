#pragma once

#include <unordered_map>

#include "../Enums/Preconditions.h"
#include "../Enums/Resources.h"

//contains resources and precondition values at a given state in time
class PlayerState{

public:
    std::unordered_map<Resource,unsigned int> resources;
    std::unordered_map<Precondition, bool> preconditions;
public:
public:
    PlayerState(){
        resources.insert({ Resource::NB_HOUSES, std::rand() % 2 + 5});
        resources.insert({Resource::NB_LUMBERJACK, std::rand() % 1 + 2});
        resources.insert({Resource::FOOD, 100});
        resources.insert({Resource::WOOD, 10});
        resources.insert({Resource::NB_HOUSES, 3});
    }
    PlayerState(const std::unordered_map<Resource,unsigned int>& resources, const std::unordered_map<Precondition,unsigned int>& preconditions);
    void updatePreconditions(std::pair<Precondition, unsigned int > condition);
    void updateResources(std::pair<Resource, unsigned int > resource);
};