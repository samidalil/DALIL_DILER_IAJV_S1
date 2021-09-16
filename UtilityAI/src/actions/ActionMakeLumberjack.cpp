#include "../../headers/actions/ActionMakeLumberjack.h"

void ActionMakeLumberjack::Execute(Agent& a) const
{
    a.resources.find(Resources::NB_LUMBERJACK)->second += 1;
}