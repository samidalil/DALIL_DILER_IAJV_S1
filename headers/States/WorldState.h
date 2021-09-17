#pragma once

#include <unordered_map>
#include "../Enums/Rules.h"
class WorldState
{
public:
    std::unordered_map<Rules,unsigned int > rules;
public:
    WorldState()
    {
        rules.insert({ Rules::GOAL, std::rand() % 500 + 1000});
        rules.insert({ Rules::VILLAGER_FOOD_COST, 50});
        rules.insert({ Rules::LUMBERJACK_FOOD_COST, std::rand() % 50+ 20});
        rules.insert({ Rules::LUMBERJACK_PROD_RATE, std::rand() % 5 + 10});
        rules.insert({ Rules::VILLAGER_PROD_RATE, std::rand() % 3+ 5});
        //rules.insert({ Rules::MAX_FOOD, 1000}); add if needed in algorithm
        //rules.insert({ Rules::MAX_WOOD, 1000});
    }

};