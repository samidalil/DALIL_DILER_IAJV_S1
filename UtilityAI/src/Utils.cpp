#include "../headers/Utils.h"

float Utils::normalize(T min, T max, T val) {
    return (val - min) / (max - min);
}

static float Utils::linear(const unsigned int &val, const int min, const int max) {
    return normalize(0, pMax, (1.f * val) + 2.f);
}

float Utils::exponential(const unsigned int &fac, const float max) {
    return normalize(0, exp(pMax), std::exp(factor));
}