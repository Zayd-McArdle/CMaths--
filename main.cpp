#include <iostream>
#include <vector>
#include "input_handler.hpp"

// template <typename T>
// static std::vector<T> getDataCollection() {
//     std::vector<T> dataCollection;
//     T input;
//     try {
//         while (true) {
//             std::cout << "Please enter a value (when you no longer want to enter anymore values, please just press enter without entering any values)" << std::endl;
//             cin >> input;
//             dataCollection.push_back(input);
//         }
        
//     }
//     catch(...)
//     {        
//     }
//     if (dataCollection.size() < 1)
//     {
//         std::cout << "You can't have an empty data collection" << std::endl;
//         dataCollection = getDataCollection();
//     }
    
//     return dataCollection;
// }


// static void displayOptions(const char* options[], int size) {
//     std::cout << "Please select from the following options" << std::endl;
//     for (int i = 0; i < size; i++) {
//         std::cout << i+1 << ")" << options[i] << std::endl;
//     }   
// }
// static bool getUserInput(const char* optionTypes[], int maxValue, int* inputtedValue) {
//     displayOptions(optionTypes, maxValue);
//     try {        
//         std::cin >> *inputtedValue;
//         if (*inputtedValue < 1 || *inputtedValue > maxValue)
//         {
//             std::cout << "Invalid input. Please try again." << std::endl;
//             return false;
//         }        
//     }
//     catch (const std::exception err) {
//         std::cout << err.what() << std::endl;
//         return false;
//     }
//     return true;
// }
// template <typename T>
// static void getCalculationType(const std::vector<T>& dataCollection) {
//     const char* calculationType[] = { "Mean", "Mode", "Median", "Range" };
//     void (*doCalculation[4])(std::vector<T>&) = { calculateMean, calculateMode, calculateMedian, calculateRange };
//     int inputtedValue;
//     while (getUserInput(calculationType, 4, &inputtedValue));
//     for (int i = 0; i < 4; i++)
//     {
//         if (inputtedValue == i+1)
//         {
//             doCalculation[i](dataCollection);
//         }
        
//     }
    
// }
// static void getNumericType() {
//     const char* numericTypes[] = { "Whole numbers", "Decimal numbers" };
//     int inputtedValue;
//     while (getUserInput(numericTypes, 2, &inputtedValue));

//     try {
//         int input; 
//         std::cin >> input;
//         if (input == 1) {
//             getDataCollection<int>();
//         }
//         else if (input == 2) {
//             getDataCollection<double>();
//         }
//         else {
//             throw "invalid input";
//         }        
//     }
//     catch(...) {
//         std::cout << "Invalid input. Please try again." << std::endl;
//         getNumericType();
//     }
    
// }
int main(void) {
    std::cout << "CMaths++ Version 1.0" << std::endl;
    getNumericType();
    return 0;
    
}