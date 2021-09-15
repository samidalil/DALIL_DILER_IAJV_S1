#include "../../headers/Action Planning/Planner.h"

#include <vector>
#include "../../headers/Action Planning/Action.h"

void Planner::DeInit()
{

}

void Planner::Init()
{

}

void Planner::Planning(const World& w) const
{
	std::vector<Action> openNodes;
	PreconditionMap preconditions;
}