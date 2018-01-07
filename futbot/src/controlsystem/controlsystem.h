#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H

#include <vector>
#include "neuralnetwork/neuralnetwork.h"

class ControlSystem{
public:
    ControlSystem();

private:
    int ia_number;    
    std::vector<NeuralNetwork> create_random_population();


};

#endif
