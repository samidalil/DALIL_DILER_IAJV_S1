#pragma once

#include "math.h"

class Utils
{

public:

    template <typename T>
    static float normalize(T min, T max, T val);
    static float linear(const unsigned int &x,  const int min, const int max);
    static float average(std::vector<int> vals);
    static float exponential(const unsigned int &fac, const float max);

};