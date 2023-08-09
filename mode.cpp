#include "mode.hpp"
template <typename T>
struct Mode
{
    T value = 0;
    int frequency;
};
template <typename T>
static int findOccurrence(const std::vector<T>& dataCollection, T value) {
    int occurrence = 0;
    for (int i = 0; i < dataCollection.size(); i++)
    {
        if (dataCollection[i] == value)
        {
            occurrence++;
        }        
    }
    return occurrence;
    
}
template <typename T>
static inline void setMode(Mode<T>& mode, T value, int frequency) {
    mode.value = value;
    mode.frequency = frequency;
}
template <typename T>
inline T calculateMode(const std::vector<T>& dataCollection)
{
    Mode<T> mode;
    //Sets the initial index of the mode
    setMode(mode, dataCollection[0], findOccurrence(dataCollection, dataCollection[0]));
    for (int i = 0; i < dataCollection.size(); ++i)
    {
        Mode<T> tempMode;
        //Initialises the tempMode to contain the values in the loop
        setMode(tempMode, dataCollection[i], findOccurrence(dataCollection, dataCollection[i]));
        if (tempMode.value != mode.value && tempMode.frequency > mode.frequency)
        {
            //Modifies the values of the original mode
            setMode(mode, tempMode.value, tempMode.frequency);            
        }
        
    }
    return mode.value;
    
}
