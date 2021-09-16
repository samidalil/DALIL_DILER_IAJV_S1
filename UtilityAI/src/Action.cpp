#include "../headers/Action.h"
#include "../headers/Utils.h"
using namespace Utils;
/*
void Action::addEvaluation(std::pair<Resources, Rules> pair) {
    evaluations.insert(pair);
}*/

void Action::addEvaluation(std::pair<unsigned int, unsigned int> pair) {
    evaluations.insert(pair);
}

float Action::Evaluate() const {
    std::vector<float> values;
    for(auto eval : evaluations)
    {
        values.push_back(Utils::linear(eval.first,0, eval.second));
    }
    return Utils::average(values);
}