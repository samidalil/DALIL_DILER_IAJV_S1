#include <unordered_map>

#include "headers/Action.h"
#include "headers/States/WorldState.h"
#include "iostream"

#include "headers/States/WorldState.h"
void print()
{
    std::cout << "hello world";
}
/*
 * Add world to main
 * Add effects of actions
 * add actions to list
 * */
int main()
{
    WorldState w;

    std::vector<Action*> actions;
    std::unordered_map<Precondition,bool> preconditions;
    std::vector<Precondition> test;
    preconditions.insert(std::pair<Precondition,bool>(Precondition::HAS_ENOUGH_VILLAGERS, true));

    std::vector<Action> actionVec;
    //preconditions.find(Precondition::HAS_ENOUGH_VILLAGERS)->second = true;
    Action goal("Win game", 0,preconditions, actionVec, {
    }); //TODO do temporary function to assign or create namespace with effects



    Action makeVillager("Make Villager", 5,preconditions, actionVec, print);
    Action makeLumberjack("Make Lumberjack", 6,preconditions, actionVec, print);
    Action makeHouse("Make House", 10,preconditions, actionVec, print);
    Action waitForATurn("Wait for a turn", 1,preconditions, actionVec, print);
    //action2.effect();
    return 0;
}