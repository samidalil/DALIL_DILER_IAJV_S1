#include <cstdint>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

/* State Definition and Values */

using State = uint32_t;

constexpr State NONE = 0;
constexpr State HAS_WEAPON = 1 << 0;
constexpr State HAS_AMMO = 1 << 1;
constexpr State PLAYER_IN_RANGE = 1 << 2;

/* Action Definition and Values */

enum class Action : unsigned short int
{
    GET_WEAPON,
    RELOAD,
    MOVE_TO_PLAYER,
    ATTACK_PLAYER
};

/* World State Definition and Initialization */

using AgentState = struct AgentState_s {
    State values = 0;
    State ignoreMask = -1;
};

AgentState createState(const std::vector<State>& conditions, const std::vector<bool>& values)
{
    AgentState ws;

    for (uint32_t i = 0; i < conditions.size(); ++i)
    {
        ws.values |= (1 & values[i]) << conditions[i];
        ws.ignoreMask |= ~(1 & values[i]) << conditions[i];
    }

    return ws;
}

/* GOAP Definition and Methods */

using GOAP = struct GOAPStruct {
    std::unordered_map<Action, AgentState> actionPreconditions;
    std::unordered_map<Action, AgentState> actionEffects;
    std::unordered_map<Action, unsigned int> actionCosts;

    Action goal;
};

GOAP initGOAP()
{
    GOAP goap;

    goap.actionPreconditions.insert({ Action::GET_WEAPON, createState({ HAS_WEAPON }, { false }) });
    goap.actionPreconditions.insert({ Action::RELOAD, createState({ HAS_WEAPON, HAS_AMMO }, { true, false }) });
    goap.actionPreconditions.insert({ Action::MOVE_TO_PLAYER, createState({ PLAYER_IN_RANGE }, { false }) });
    goap.actionPreconditions.insert({ Action::ATTACK_PLAYER, createState({ HAS_WEAPON, HAS_AMMO, PLAYER_IN_RANGE }, { true, true, true }) });

    goap.actionEffects.insert({ Action::GET_WEAPON, createState({ HAS_WEAPON }, { true }) });
    goap.actionEffects.insert({ Action::RELOAD, createState({ HAS_AMMO }, { true }) });
    goap.actionEffects.insert({ Action::MOVE_TO_PLAYER, createState({ PLAYER_IN_RANGE }, { true }) });
    goap.actionEffects.insert({ Action::ATTACK_PLAYER, createState({}, {}) });

    goap.actionCosts.insert({ Action::GET_WEAPON, 3 });
    goap.actionCosts.insert({ Action::RELOAD, 1 });
    goap.actionCosts.insert({ Action::MOVE_TO_PLAYER, 2 });
    goap.actionCosts.insert({ Action::ATTACK_PLAYER, 1 });


    goap.goal = Action::ATTACK_PLAYER;

    return goap;
}

std::vector<Action> reverseAstar(const std::vector<Action>& openNodes, std::vector<Action> actions)
{

    Action lowestCostAction;
    unsigned int lowestCost = 1000;

    for (auto action : openNodes)
    {
        if (false/* ws.values & goap.actionPreconditions.at(action).values > 0 */)
        {
            actions.push_back(action);
            return actions;
        }
        unsigned int cost = 0/* goap.actionCosts.at(action) */;

        if (lowestCost > cost)
        {

        }
        else
        {

        }
    }

    actions.push_back(lowestCostAction);
    return reverseAstar(openNodes, actions);
}

std::vector<Action> plan(const GOAP& goap, const AgentState& ws)
{
    std::vector<Action> possibleActions = { Action::GET_WEAPON, Action::RELOAD, Action::MOVE_TO_PLAYER, Action::ATTACK_PLAYER };
    std::vector<Action> openNodes = { goap.goal };

    int shortestPathCostSum;
    std::unordered_map<Action, AgentState> selectedActionPreconditions;

    for(auto act : openNodes) {
        int costSum = 0;

        //adding new possible actions
        for (auto action: possibleActions) {
            if (act != action)
                openNodes.push_back(action);
        }
        if(possibleActions.empty())
        {
            std::cout << "Game design error in actions" << std::endl;
        }

        std::remove(openNodes.begin(), openNodes.end(), act);

        Action selectedAction;
        //evaluating each actions preconditions
        for (auto action: openNodes) {
            //check amount of preconditions
            //selectedAction = action
        }
        //costSum += selectedAction.cost;

        //Check if this path is longer
        /*
         * if(shortestPathCost < costSum)
         * {
         *      std::remove(openNodes.begin(), openNodes.end(), selectedAction);
         *      continue;
         * }
        */


        //add selected actions' preconditions to the current one

        //check if any preconditions are left that are unmet by world/agent state
        /*
         * if(selectedActionPreconditions == 0)
         * {
         *
         *      the path is complete
         *      if(shortestPathCost > costSum)
         *          shortestPathCost = costSum;
         *      if(openNodes.empty()) //finished?
         *          break;
         *
         *      //remove the selected action from openNodes?
         * }
         * */
        //selectedActionPreconditions += selectedActions preconditions



    }
    AgentState preconditions = goap.actionPreconditions.at(goap.goal);

    preconditions.values = (!(ws.values & preconditions.values) & preconditions.ignoreMask);

    return reverseAstar(openNodes, {});
}

/* Main */

int main()
{
    GOAP goap = initGOAP();

    AgentState ws = createState(
        { HAS_WEAPON, HAS_AMMO, PLAYER_IN_RANGE },
        { true, false, false }
    );

    std::vector<Action> actions = plan(goap, ws);

    std::cout << "Test" << std::endl;
    std::cout << "COUCOU MON REUF";

    for (Action action : actions)
        std::cout << (int)action << std::endl;

    return 0;
}
