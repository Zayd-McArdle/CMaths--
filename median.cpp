#include "median.hpp"
#include <list>
#include <cmath>
#include <algorithm>
template<typename T>
inline T calculateMedian(const std::vector<T>& dataCollection)
{   
    std::sort(dataCollection.begin(), dataCollection.end());
    return dataCollection[(int)round(dataCollection.size() / 2)];    
}