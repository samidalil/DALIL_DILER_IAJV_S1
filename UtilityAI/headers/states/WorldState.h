#pragma once

#include "AgentState.h"

class World
{
public:
    unsigned int nbGoalPopulation;
    unsigned int houseWoodCost;
    unsigned int villagerFoodProductionCost;
    unsigned int lumberjackFoodProductionCost;
    unsigned int woodProductionRate;
    unsigned int foodProductionRate;
    Agent initialAgent;
public:
    World();
    World(const int nbGoalVillager, const int woodCost, const int villagerCost, const int lumberjackCost, const int nbInitialVillager);
    World(const World& w);
    World& operator=(const World& w);
    void copy(const World& w);
};
