#include "../../headers/actions/ProduceCharacter.h"

float ProduceVillager::Evaluate(Agent &a, World &w) const {
    if(a.nbFood < w.villagerFoodProductionCost)
        return Utils::normalize(0,w.nbGoalVillager, a.nbVillager);
}

void ProduceVillager::Execute(Agent &a) const {
    a.nbFood;
    a.nbVillager++;
}

/*
 *
 * monde :
 * goal : population total atteint
 * agent inital (stat de départ)
 * cout de bouffe passif d'un villagoie
 * cout de bois d'une maison
 * taux de production par tick de bois d'un lumberjack
 * taux de production par tick de bouffe d'un villagoie
 * cout de production d'un villagoie
 * cout de production d'un lumberjack
 *
 * agent :
 * nbMaison
 * nbVillagoi
 * nbwood
 * nbfood
 * nblumberjack
 *
 * action:
 * Produire un villagoie
 * Produire un lumberjack
 * construire une maison
 * ne rien faire mais précise l'action suivante souhaité
 *
 *
 * nombre de population max dépendant du nombre maison
 *
 *
 * */