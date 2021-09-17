#pragma once

#include <vector>
#include "States/PlayerState.h"
#include "States/WorldState.h"
//namespace contenant les calculs mathématique pouvant être accédé de n'importe où.
namespace Utils{
    //il faudrait faire une map de map afin de povuoir stocker valeur de resource pour chaque resource ainsi que la règle corresopndante et la valeur de la règle dans le world state
    std::unordered_map<Precondition,bool> determinePreconditions(const PlayerState& playerState, WorldState& worldState);

    //preconditions Evaluation, it would be better to do a generic function which takes a pair rather than specific values for each precondition
    bool hasEnoughVillagers(const PlayerState& playerState, const WorldState& worldState);
    bool canMakeHouse(const PlayerState& playerState, const WorldState& worldState);
    bool canMakeVillager(const PlayerState& playerState, const WorldState& worldState);
    bool canMakeLumberjack(const PlayerState& playerState, const WorldState& worldState);
    bool hasReachedMaximumHouseCapacity(const PlayerState& playerState, const WorldState& worldState);
    unsigned int calculateCapacity(const unsigned int& nbHouse, const unsigned int& nbPopulation);

}