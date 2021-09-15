#include "../headers/Utils.h"

template <typename T,typename T2>
std::unordered_map<T,T2> Utils::appendMaps(std::unordered_map<T,T2> map1, std::unordered_map<T,T2> map2)
{
    std::unordered_map<T,T2> res;
    for(auto& it : map1)
    {
        res[it->first] = it->second;
    }
    for(auto& it : map2)
    {
        res[it->first] = it->second;
    }
    return res;
}

bool Utils::isValid(bool a, bool b) {
    if(a == b)
        return true;
    return false;
}
