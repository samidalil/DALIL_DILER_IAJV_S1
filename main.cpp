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

Action createActionTree(const PlayerState& playerState, const Action& action, const std::vector<Action> actions, const unsigned int cost)
{
    PlayerState newPlayerstate = playerState;
    //TODO calculate new state based on effect of action in parameter
    action.updateUnmetPreconditions(newPlayerstate);

    if(action.nbUnmetPreconditions == 0)
        return action;
    else if(cost > newPlayerstate.minCostAction)
    {
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
    PlayerState singlePlayerState;
    /*
    PlayerState initialState;

    std::vector<PlayerState> playerStates;
    for(int i = 0; i < 5; ++i)
    {
        PlayerState playerState = initialState;
        playerStates.push_back(playerState);
    }
    */
    std::vector<Action*> actions;
    std::unordered_map<Precondition,bool> preconditions;
    std::vector<Precondition> test;
    preconditions.insert(std::pair<Precondition,bool>(Precondition::HAS_ENOUGH_VILLAGERS, true));

    std::vector<Action> actionVec;
    //preconditions.find(Precondition::HAS_ENOUGH_VILLAGERS)->second = true;
    Action goal("Win game", 0,preconditions, actionVec, {
    }); //TODO do temporary function to assign or create namespace with effects

    Action action1 = goal;
    std::cout << action1;


    Action makeVillager("Make Villager", 5,preconditions, actionVec, print);
    Action makeLumberjack("Make Lumberjack", 6,preconditions, actionVec, print);
    Action makeHouse("Make House", 10,preconditions, actionVec, print);
    Action waitForATurn("Wait for a turn", 1,preconditions, actionVec, print);
    //action2.effect();

    actions.push_back(&makeVillager);
    actions.push_back(&makeLumberjack);
    actions.push_back(&makeHouse);
    actions.push_back(&waitForATurn);

    singlePlayerState.preconditions = Utils::determinePreconditions(singlePlayerState, worldState);

    return 0;
}