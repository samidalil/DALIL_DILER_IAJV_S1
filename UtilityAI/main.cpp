#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "headers/Action.h"
#include "headers/actions/AllActions.h"
#include "headers/states/WorldState.h"
#include "headers/states/AgentState.h"
#include <time.h>
int main()
{
    srand (time(NULL));

    //le jeu peut être jouer avec autant d'IA que souhaité
    int nbAgents = 5;
    std::vector<Agent> agents;
    std::vector<Action*> actions;
    World w;

    bool gameFinished;
    actions.push_back(new ActionMakeVillager());
    actions.push_back(new ActionMakeLumberjack());

    while(!gameFinished)
    {
        for(auto agent : agents)
        {
            for(auto action : actions)
            {
                action->addEvaluation(agent.resources.find(Resources::));
            }
            if(agent.resources.find(Resources::NB_VILLAGER)->second >= w.rules.find(Rules::GOAL)->second)
            {
                gameFinished = true;
                //operateur de flux dans agent, shared pointer pour nb d'agents
                //std::cout << "game won by AI " << agent;
            }
            agent.printState();
        }
    }


    //action->addEvaluation(std::make_pair(agents->at(0).resources.find(Resources::NB_HOUSES)->second,
      //                                   w.rules.find(Rules::GOAL)->second));


    std::cout << std::rand() % 15+1 << std::endl;
    return 0;
}
