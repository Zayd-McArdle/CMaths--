#include "range.hpp"
template <typename T>
inline T calculateRange(const std::vector<T> &dataCollection) {
    T minValue = 0;
    T maxValue = 0;
    for (int i = 0; i < dataCollection.size(); i++) {
        if (dataCollection[i] < minValue) {
            minValue = dataCollection[i];
        }
        else if (dataCollection[i] > maxValue)
        {
            maxValue = dataCollection[i];
        }
        
    }
    return maxValue - minValue;
}