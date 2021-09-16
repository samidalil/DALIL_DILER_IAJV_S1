#pragma once

#include "math.h"
#include <vector>


namespace Utils{
    float normalize (const int min, const int max, const int val)
    {
        return (val - min) / (max - min);
    }

    float linear(unsigned int val,  unsigned int min, unsigned &max)
    {
        return Utils::normalize(min, max, (1.f * val) + 2.f);
    }

    float average(std::vector<float>& vals)
    {
        float total = 0;
        for (int val : vals)
            total += val;
        return total / vals.size();
    }

    float exponential(unsigned int &fac, float max)
    {
        return Utils::normalize(0, exp(max), std::exp(fac));
    }

}/*
class Utils
{

public:

    static float normalize(const int min, const int max, const int val);
    static float linear(unsigned int &x,  unsigned int min, unsigned &max);
    static float average(std::vector<float>& vals);
    static float exponential(unsigned int &fac, float max);

};*/