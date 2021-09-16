#pragma once

#include "AgentState.h"
#include "../Resources.h"
#include <unordered_map>
class World
{
public:
    std::unordered_map<Rules,unsigned int> rules;
public:
    World()
    {
        rules.insert({ Rules::GOAL, std::rand() % 500 + 1000});
        rules.insert({ Rules::VILLAGER_FOOD_COST, 50});
        rules.insert({ Rules::LUMBERJACK_COST, std::rand() % 50+ 20});
        rules.insert({ Rules::LUMBERJACK_PROD_RATE, std::rand() % 5 + 10});
        rules.insert({ Rules::VILLAGER_PROD_RATE, std::rand() % 3+ 5});
        rules.insert({ Rules::MAX_FOOD, 1000});
        rules.insert({ Rules::MAX_WOOD, 1000});
    }
    /*World(const int nbGoalVillager, const int woodCost, const int villagerCost, const int lumberjackCost, const int nbInitialVillager);
    World(const World& w);
    World& operator=(const World& w);
    void copy(const World& w);*/
};
