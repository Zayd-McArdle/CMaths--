#pragma once
#include <vector>
void displayOptions(const char* options[], int size);
bool getUserInput(const char* optionTypes[], int maxValue, int* inputtedValue);
template <typename T>
void getCalculationType(const std::vector<T>& dataCollection);
void getNumericType();