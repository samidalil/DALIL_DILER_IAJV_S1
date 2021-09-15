#include "../../../headers/ActionPlanning/Actions/HarvestWoodAction.h"
#include "../../../headers/Resource.h"

void HarvestWoodAction::applyEffect(World& w, PreconditionMap& preconditions) const
{
	int addValue = std::rand() % 15 + 1;
	//increase resource value of wood with add value 
	//w.resources<Resource::WOOD, >
}