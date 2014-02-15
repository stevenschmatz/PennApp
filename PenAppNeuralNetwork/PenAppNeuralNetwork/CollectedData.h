#ifndef PenAppNeuralNetwork_CollectedData_h
#define PenAppNeuralNetwork_CollectedData_h
#include <vector>
#include "SampledData.h"

class CollectedData {
private:
    std::vector<int> x_values;
    std::vector<int> y_values;
public:
    CollectedData(std::vector<int> x_values, std::vector<int> y_values);
    SampledData *sample(int n);
    std::vector<int> get_x_values();
    std::vector<int> get_y_values();
};

#endif
