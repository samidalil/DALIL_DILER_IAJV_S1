#pragma once

#include "states/AgentState.h"
#include "states/WorldState.h"
#include <vector>

//Class de base de toute les actions.
//Les classes actions spécifiques hériterons de celle-ci
class Action
{

public:
    int factor;
    std::unordered_map<unsigned int, unsigned int > evaluations;
public:
    void addEvaluation(const std::pair<unsigned int,unsigned int > eval);
    //récupère toute les évaluations présente pour l'action, les évalues avec une fonction quelconque (ex: linéaire, exponoentiel, moyenne)
    float Evaluate() const;
    //Chaque action override cette fonction.
    //Si cette fonction est sélectionné, on applique son effet dans cette méthode dans le state de l'IA en paramètre.
    virtual void Execute(Agent& a) const = 0;
};