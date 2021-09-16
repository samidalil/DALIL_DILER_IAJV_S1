#pragma once

#include "../Action.h"

class ActionMakeLumberjack : public Action
{
public:
    void Execute(Agent& a) const override;
};