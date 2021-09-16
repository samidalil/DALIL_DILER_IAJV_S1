#pragma once

enum class Precondition : unsigned short int
{
    CAN_MAKE_VILLAGER,
    CAN_MAKE_LUMBERJACK
};

enum class Resource : unsigned short int{
    FOOD,
    WOOD,
    NB_VILLAGER,
    NB_LUMBERJACK,
    NB_HOUSES
};