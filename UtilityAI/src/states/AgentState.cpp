#include "../../headers/states/AgentState.h"


Agent::Agent() {
    this->nbVillager = std::rand() % 2 + 5;
    this->nbLumberjack = std::rand() % 1 + 2;
    this->nbFood = 100;
    this->nbWood = 10;
    this->nbHouse = 3
}
Agent::Agent(const unsigned int nbVillager, const unsigned int nbLumberjack, const unsigned int nbFood,
             const unsigned int nbWood, const unsigned int nbHouse){
    this->nbVillager = nbVillager;
    this->nbLumberjack = nbLumberjack;
    this->nbFood = nbFood;
    this->nbWood = nbWood;
    this->nbHouse =nbHouse
}