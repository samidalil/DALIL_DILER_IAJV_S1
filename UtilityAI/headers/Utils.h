#pragma once

#include "math.h"
#include <vector>

//namespace contenant les calculs mathématique pouvant être accédé de n'importe où.
namespace Utils{
    float normalize (const int min, const int max, const int val)
    {
        return (val - min) / (max - min);
    }

    float linear(const unsigned int val, const unsigned int min, const unsigned int&max)
    {
        return Utils::normalize(min, max, (1.f * val) + 2.f);
    }

    float average(const std::vector<float>& vals)
    {
        float total = 0;
        for (int val : vals)
            total += val;
        return total / vals.size();
    }

    float exponential(const unsigned int &fac, const float max)
    {
        return Utils::normalize(0, exp(max), std::exp(fac));
    }
}