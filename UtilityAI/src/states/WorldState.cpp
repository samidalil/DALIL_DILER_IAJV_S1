#include "../../headers/states/WorldState.h"
#include <stdlib.h>

World::World() : initialAgent(Agent()),nbGoalPopulation(std::rand() % 500 + 1000), houseWoodCost(std::rand() % 20 + 20),
villagerFoodProductionCost(std::rand() % 5 + 10),woodProductionRate(std::rand() % 5 +10), lumberjackFoodProductionCost(std::rand() % 5 + 10),
foodProductionRate(std::rand() % 10 + 5)
{}

World::World(const World &w)
{
    this->copy(w);
}

World::World(const int nbGoalVillager, const int woodCost, const int villagerCost, const int lumberjackCost,
             const int nbInitialVillager)
{
}


void World::copy(const World &w) {
}

World& World::operator=(const World& w) {
    this->copy(w);
    return (*this);
}