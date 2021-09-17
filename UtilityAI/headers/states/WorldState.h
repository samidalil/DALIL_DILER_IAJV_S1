#pragma once

#include "AgentState.h"
#include "../Resources.h"
#include <unordered_map>
class World
{
public:
    //map contenant en clé les règles et en valeur la valeur correspondante à chaque règle
    //ex: clé = VILLAGER_FOOD_COST, valeur = 50
    std::unordered_map<Rules,unsigned int> rules;
public:
    //constructeur naturelle lors de l'initiation du monde. Des valeurs sont aléatoire afin d'avoir des parties variés.
    //Pour la robustesse du programme, il faudrait faire qu'il n'y a qu'une seul instance de World sous forme d'un singleton
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
};
