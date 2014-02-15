#ifndef PenAppNeuralNetwork_SampleVector_h
#define PenAppNeuralNetwork_SampleVector_h

#include <opencv/cv.h>
#include <opencv/ml.h>

class SampleVector {
private:
    int x;
    int y;
public:
    SampleVector(int x, int y);
    OpenCV::Mat toOpenCVMatrix();
};

#endif