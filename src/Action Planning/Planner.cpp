#include "../../headers/Action Planning/Planner.h"

#include <vector>
#include "../../headers/Action Planning/Action.h"
#include "../../headers/Utils.h"
#include "../../headers/Action Planning/Actions/AllActions.h"

void Planner::DeInit()
{
    //TODO
}

void Planner::Init(std::vector<Action*>& actions)
{
    Action* harvestWoodAction = new HarvestWoodAction;
    Action* buildHouseAction = new BuildHouse;
    Action* pickUpAxeAction = new PickUpAxe;
    Action* walkToTreeAction = new WalkToTree;

    actions.push_back(harvestWoodAction);
    actions.push_back(buildHouseAction);
    actions.push_back(pickUpAxeAction);
    actions.push_back(walkToTreeAction);
}

void Planner::Planning(const World& w) const
{
	std::vector<Action*> openNodes;
	PreconditionMap preconditions;

    int minCost;
    /*for(auto& act : openNodes)
    {
        for(auto& it : act->preconditions)
        {
            if(w.conditions.at(it.first) != it.first)
                preconditions.insert(it);
            //if(it.first == w.resources[it.first])
        }
        if(act->cost != 0)
        {
            bool hasPreconditions = act->preconditions.empty();

            preconditions = Utils::appendMaps(act->preconditions, preconditions);
        }
        if(act->cost < minCost)
            minCost = act->cost;
    }*/
}