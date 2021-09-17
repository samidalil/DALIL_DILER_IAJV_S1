#pragma once

#include "../Resources.h"
#include <unordered_map>

//Class contenant la data de chacune des IA.
class Agent
{
public:
    std::unordered_map<Resources,unsigned int> resources;

public:
    Agent(){
        resources.insert({ Resources::NB_HOUSES, std::rand() % 2 + 5});
        resources.insert({Resources::NB_LUMBERJACK, std::rand() % 1 + 2});
        resources.insert({Resources::FOOD, 100});
        resources.insert({Resources::WOOD, 10});
        resources.insert({Resources::NB_HOUSES, 3});
    }
    void printState();
    Agent(const unsigned int nbVillager, const unsigned int nbLumberjack, const unsigned int nbFood, const unsigned int nbWood, const unsigned int nbHouse);
};
