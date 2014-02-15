//
//  CollectedData.h
//  PenAppNeuralNetwork
//
//  Created by Amit Mizrahi on 2/14/14.
//  Copyright (c) 2014 amizrahi. All rights reserved.
//

#ifndef PenAppNeuralNetwork_CollectedData_h
#define PenAppNeuralNetwork_CollectedData_h
#include <vector>

class CollectedData {
private:
    std::vector<int> x_values;
    std::vector<int> y_values;
public:
    CollectedData(std::vector<int> x_values, std::vector<int> y_values);
    SampledData sample(int n) {
        
    }
};

#endif
