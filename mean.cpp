#include "mean.hpp"
template<typename T>
inline T calculateMean(const std::vector<T>& dataCollection) {
    T calculation = 0;
    for (int i = 0; i < dataCollection.size(); i++)
    {
        calculation += dataCollection[i];
    }
    
    return calculation / dataCollection.size();
}