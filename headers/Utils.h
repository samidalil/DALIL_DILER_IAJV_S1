#pragma once
#include <unordered_map>


class Utils
{

public:
    template <typename T,typename T2>
    static std::unordered_map<T,T2> appendMaps(std::unordered_map<T,T2> map1, std::unordered_map<T,T2> map2);
    static bool isValid(bool a, bool b);
};