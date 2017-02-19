#ifndef EACONTROLLER_H
#define EACONTROLLER_H

#define NUM_NEURAL_NETWORK 100

#include "neuralnetwork/neuralnetwork.h"
#include "wrsim/src/WRSim/interface.h"
#include <vector>

class EAControler{
public:
    EAControler();
    void Run();
private:
    std::vector<NeuralNetwork> neural_network;
    std::vector<NeuralNetwork> tmp_neural_network;
    interface* inter;
};


#endif
