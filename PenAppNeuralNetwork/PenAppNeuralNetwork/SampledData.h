//
//  SampledData.h
//  PenAppNeuralNetwork
//
//  Created by Amit Mizrahi on 2/14/14.
//  Copyright (c) 2014 amizrahi. All rights reserved.
//

#ifndef PenAppNeuralNetwork_SampledData_h
#define PenAppNeuralNetwork_SampledData_h
#include <vector>

class CollectedData {
private:
    std::vector<SampleVector> sampleMatrix;
public:
    SampledData(int n, CollectedData cd);
    SampleVector sampleAt(int k);
};



#endif
