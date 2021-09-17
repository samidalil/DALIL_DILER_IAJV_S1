#include <unordered_map>

#include "headers/Action.h"
#include "headers/States/WorldState.h"
#include "headers/States/PlayerState.h"
#include "iostream"
#include "headers/Utils.h"
using namespace Utils;
#include "headers/States/WorldState.h"
void print()
{
    std::cout << "hello world";
}
//finds the child with the least amount of preconditions
Action findBestRoute(Action currentAction, std::vector<Action> childs)
{
    int minPreconditions = INT32_MAX;
    Action selectedAction;
    for(auto child : childs)
    {
        if(child.nbUnmetPreconditions < minPreconditions)
        {
            minPreconditions = child.nbUnmetPreconditions;
            selectedAction = child;
        }
    }

    return selectedAction;
}

//finds the actinos that will affect the precondition of the current action
std::vector<Action> findActionChilds(Action& action, std::vector<Action> newListAction)
{
    std::vector<Action> childs;

    for(auto newAct : newListAction)
    {
        for(auto impact : newAct.impactedPreconditions)
        {

            //TODO if impact is in new act
            //{
                Action addedAct = newAct; // <-- new instance of same action
                childs.push_back(addedAct);
                break;
            //
           // if(newAct.preconditions.find(impact))
        }
    }
    return childs;
}
/*Determines the action chosen by the recursive pathfinder*/
Action createActionTree(const PlayerState& playerState, const Action& action, const std::vector<Action> actions, const unsigned int cost)
{
    PlayerState newPlayerstate = playerState;
    //TODO calculate new state based on effect of action in parameter
    action.updateUnmetPreconditions(newPlayerstate);

    //this is the final action for this path
    if(action.nbUnmetPreconditions == 0)
        return action;
    else if(cost > newPlayerstate.minCostAction)
    {
        //if this is the case, we ignore this path
        return Action.empty();//TODO make empty action equivalent to NULL for action
    }
    else
    {
        //TODO create a function RemoveCurrentActionFromList new list "newlistaction" without the current action from actions list
        //TODO faire une fonction findactionchilds  (all except the one) parameters action, newlistaction
        // vérifie si parmis la liste d'action
        action.childActions = findActionChilds(action, newlistaction);
        std::vector<Action> newChildActions = action.childActions;
        while(!newChildActions.empty())
        {
            Action newAction = findBestRoute(action, action.childActions);
            //RemoveCurrentActionFromList(newAction, newChildaction);

            createActionTree(newPlayerstate, newAction,actions, cost+action.cost);
        }
        return action;
    }


}

Action determineAction(PlayerState& playerState, Action initialAction, const std::vector<Action*> actions)
{
    for(auto action : actions)
    {
        action.UpdateNbUnmetPreconditions(PlayerState& playerState);
    }
}
/*
 * Add world to main
 * Add effects of actions
 * add actions to list
 * */
int main()
{
    WorldState worldState;

    PlayerState initialState;

    std::vector<PlayerState> playerStates;
    for(int i = 0; i < 5; ++i)
    {
        PlayerState playerState = initialState;
        playerStates.push_back(playerState);
    }

    std::vector<Action*> actions;
    std::unordered_map<Precondition,bool> preconditions;
    std::vector<Precondition> test;
    preconditions.insert(std::pair<Precondition,bool>(Precondition::HAS_ENOUGH_VILLAGERS, true));

    std::vector<Action> actionVec;

    //create each action. thsi should be done in some sort of init and not in the main.
    Action makeVillager("Make Villager", 5,preconditions, actionVec, print);
    Action makeLumberjack("Make Lumberjack", 6,preconditions, actionVec, print);
    Action makeHouse("Make House", 10,preconditions, actionVec, print);
    Action waitForATurn("Wait for a turn", 1,preconditions, actionVec, print);

    actions.push_back(&makeVillager);
    actions.push_back(&makeLumberjack);
    actions.push_back(&makeHouse);
    actions.push_back(&waitForATurn);

    bool aPlayerHaswon;
    PlayerState wonPlayer;
    while(!aPlayerHaswon)
    {
        for(PlayerState player : playerStates)
        {
            player.preconditions = Utils::determinePreconditions(player, worldState);
            //TODO call create action
            // Action selecetdAction = createActionTree(player, Make_villager_action , actions, 0);
            //selecetdAction.effect(); and print action done with effect applied
            //if(gameState.villagers >= worldState.rules.goal)
            //{
            //  wonPlayer = player
            // aPlayerHasWon = true;
            //}
            //print state of each player, would be an operator in Playerstate showing each resource

        }
    }
    //std::cout << "Player "<< wonPlayer.name << " has won" << std::endl;

    return 0;
}