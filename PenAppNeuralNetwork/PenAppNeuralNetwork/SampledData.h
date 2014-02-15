#define PenAppNeuralNetwork_SampledData_h
#include <vector>
#include "CollectedData.h"
#include "SampleVector.h"

class SampledData {
private:
    std::vector<SampleVector*> sample_matrix;
public:
    SampledData(int n, CollectedData cd);
    SampleVector sampleAt(int k);
    std::vector<SampleVector*> get_sample_matrix();
};

#endif