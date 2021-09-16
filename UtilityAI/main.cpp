#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "headers/Action.h"
#include "headers/states/WorldState.h"
#include "headers/states/AgentState.h"
#include <time.h>


int main()
{
    srand (time(NULL));

    int nbAgents = 2;
    std::vector<Agent> agents[nbAgents];
    World w;

    std::cout << "goal: " << w.nbGoalVillager << std::endl;

    std::cout << std::rand() % 15+1 << std::endl;
    return 0;
}
