#pragma once

#include "../Action.h"

class ActionMakeVillager : public Action
{
public:
    void Execute(Agent& a) const override;
};