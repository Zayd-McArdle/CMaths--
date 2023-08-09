#include <vector>
#include <iostream>
#include <string>
#include "mean.hpp"
#include "mode.hpp"
#include "median.hpp"
#include "range.hpp"

template <typename T>
static const std::vector<T> getDataCollection() {
    std::vector<T> dataCollection;
    T input;
    try {
        while (true) {
            std::cout << "Please enter a value (when you no longer want to enter anymore values, please just press enter without entering any values)" << std::endl;
            //If getting user input fails
            if (!(std::cin >> input)) {
                break;
            }
            dataCollection.push_back(input);
        }
        
    }
    catch(...)
    {        
    }
    if (dataCollection.empty())
    {
        std::cout << "You can't have an empty data collection" << std::endl;
        dataCollection = getDataCollection<T>();
    }
    
    return dataCollection;
}
void displayOptions(const char* options[], size_t size) {
    std::cout << "Please select from the following options" << std::endl;
    for (int i = 0; i <= size; i++) {
        std::cout << i+1 << ")" << options[i] << std::endl;
    }   
}
bool getUserInput(const char* optionTypes[], size_t maxValue, int& inputtedValue) {
    displayOptions(optionTypes, maxValue);
    try {        
        std::cin >> inputtedValue;
        if (inputtedValue < 1 || inputtedValue > maxValue + 1)
        {
            std::cout << "Invalid input. Please try again." << std::endl;
            return false;
        }        
    }
    catch (const std::exception err) {
        std::cout << err.what() << std::endl;
        return false;
    }
    return true;
}
static int getTypeFromInput(const char** (*getTypes)(), void (*doDataCheck)(int)) {
    const char** types = getTypes();
    int inputtedValue;

    try {
        //While the user is inputting bad data
        while (getUserInput(types, (sizeof(types) / sizeof(types[0])), inputtedValue) == false);
        if (doDataCheck == nullptr)
        {
            return inputtedValue;
        }
        
        doDataCheck(inputtedValue);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;

    }
    return inputtedValue;
}

template <typename T>
void getCalculationType(const std::vector<T>& dataCollection) {
    int inputtedValue = getTypeFromInput([]() -> const char** {
        static const char* calculationTypes[] = { "Mean", "Mode", "Median", "Range" };
        return calculationTypes;
    }, nullptr);
    T (*doCalculation[4])(const std::vector<T>&) = { calculateMean, calculateMode, calculateMedian, calculateRange };
        for (int i = 0; i < 4; i++) {
            if (inputtedValue == i+1) {
                T result = doCalculation[i](dataCollection);
                // std::cout << "The result is " << result << std::endl;
                // std::string input;
                // std::cout << "Do you want to do another calculation with the same data collection? Enter y/n" << result << std::endl;
                // std::cin >> input;                
                // if (input != "y" || input != "n") {
                //    //getCalculationType<T>(dataCollection);
                // }                
            }    
        } 
}
void getNumericType() {

    getTypeFromInput([]() -> const char** {
        static const char* numericTypes[] = { "Whole numbers", "Decimal numbers" };
        return numericTypes;
    }, [](int inputtedValue) -> void {
        if (inputtedValue == 1) {
            const std::vector<int> dataCollection = getDataCollection<int>();
            getCalculationType<int>(dataCollection);
        } else if (inputtedValue == 2) {
            const std::vector<double> dataCollection = getDataCollection<double>();
            getCalculationType<double>(dataCollection);
        }  
    });
}
