#include <iostream>
#include "headers/Action Planning/Planner.h"
int main()
{
    Planner planner;
    World w;

    planner.Init();
    planner.Planning(w);
	std::cout << "test" << std::endl;
	return 0;
}

/*
files :
- action (precondition, cost, effect)
- planner (path finding)
- world(state?)
- goal? 
*/
