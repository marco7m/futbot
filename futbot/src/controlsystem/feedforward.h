#ifndef FEEDFORWARD_H
#define FEEDFORWARD_H

#include "src/neuralnetwork/neuralnetwork.h"
#include "src/wrsim/src/WRSim/interface.h"

class FeedForward{
public:
    FeedForward(NeuralNetwork* iaa, NeuralNetwork* iab, Interface inter);

    // IAs = 2
    // Inputs = 
    // Outputs = 
//    static void ia_match();
    void ia_match();

private:
    NeuralNetwork* ia_a = nullptr;
    NeuralNetwork* ia_b = nullptr;
    Interface interface;

};

#endif
