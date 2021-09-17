#include "../headers/Utils.h"

std::unordered_map<Precondition,bool> determinePreconditions(PlayerState& playerState, WorldState& worldState)
{
    std::unordered_map<Precondition,bool> preconditions;

    bool canMakeVillager = Utils::canMakeVillager(playerState,worldState);
    bool canMakeLumberjack = Utils::canMakeLumberjack(playerState,worldState);
    bool canMakeHouse= Utils::canMakeHouse(playerState,worldState);
    bool hasEnoughVillagers = Utils::hasEnoughVillagers(playerState,worldState);
    preconditions.insert(std::pair<Precondition, bool> (Precondition::CAN_MAKE_HOUSE, canMakeHouse));
    preconditions.insert(std::pair<Precondition, bool> (Precondition::CAN_MAKE_VILLAGER, canMakeVillager));
    preconditions.insert(std::pair<Precondition, bool> (Precondition::CAN_MAKE_LUMBERJACK, canMakeLumberjack));
    preconditions.insert(std::pair<Precondition, bool> (Precondition::HAS_ENOUGH_VILLAGERS, hasEnoughVillagers));

    return preconditions;
}

bool Utils::canMakeHouse(const PlayerState &playerState, const WorldState &worldState) {
    int amountPlayerWood = playerState.resources.find(Resource::WOOD)->second;
    int amountWoodRequired = worldState.rules.find(Rules::HOUSE_WOOD_COST)->second;
    return amountPlayerWood >= amountWoodRequired;
}

bool Utils::hasReachedMaximumHouseCapacity(const PlayerState &playerState, const WorldState &worldState) {
    int nbPopulation = playerState.resources.find(Resource::NB_VILLAGER)->second;
    int ruleCapacity = worldState.rules.find(Rules::HOUSE_CAPACITY)->second;
    int populationCapacity = Utils::calculateCapacity(ruleCapacity, nbPopulation);
    return nbPopulation >= populationCapacity;
}

bool Utils::canMakeVillager(const PlayerState &playerState, const WorldState &worldState) {
    int current = playerState.resources.find(Resource::FOOD)->second;
    int required = worldState.rules.find(Rules::VILLAGER_FOOD_COST)->second;
    return (current >= required) && !hasReachedMaximumHouseCapacity(playerState,worldState);
}

bool Utils::canMakeLumberjack(const PlayerState &playerState, const WorldState &worldState) {
    int current = playerState.resources.find(Resource::FOOD)->second;
    int required = worldState.rules.find(Rules::LUMBERJACK_FOOD_COST)->second;
    return (current >= required) && !hasReachedMaximumHouseCapacity(playerState,worldState);
}

bool Utils::hasEnoughVillagers(const PlayerState &playerState, const WorldState &worldState) {
    int current = playerState.resources.find(Resource::FOOD)->second;
    int required = worldState.rules.find(Rules::VILLAGER_FOOD_COST)->second;
    return current >= required;
}

unsigned int Utils::calculateCapacity(const unsigned int &houseCapacity, const unsigned int &nbPopulation) {
    return nbPopulation*houseCapacity;
}