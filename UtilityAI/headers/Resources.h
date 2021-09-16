#pragma once

enum class Resources : unsigned short int
{
    FOOD,
    WOOD,
    NB_VILLAGER,
    NB_LUMBERJACK,
    NB_HOUSES
};

enum class Rules : unsigned short int
{
    GOAL,
    VILLAGER_FOOD_COST,
    LUMBERJACK_COST,
    MAX_FOOD,
    MAX_WOOD,
    LUMBERJACK_PROD_RATE,
    VILLAGER_PROD_RATE,
};
