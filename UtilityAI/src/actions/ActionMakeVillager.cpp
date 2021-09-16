#include "../../headers/actions/ActionMakeVillager.h"

void ActionMakeVillager::Execute(Agent& a) const
{
    a.resources.find(Resources::NB_VILLAGER)->second += 1;
}