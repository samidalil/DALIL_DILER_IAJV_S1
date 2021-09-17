#pragma once

//list rules for the worldState that do not change
enum class Rules : unsigned short int
{
    GOAL,
    VILLAGER_FOOD_COST,
    LUMBERJACK_FOOD_COST,
    //MAX_FOOD,
    //MAX_WOOD, add these 3 if needed for algorithm
    //MAX_HOUSE
    LUMBERJACK_PROD_RATE,
    VILLAGER_PROD_RATE,
    HOUSE_WOOD_COST,
    HOUSE_CAPACITY
};
