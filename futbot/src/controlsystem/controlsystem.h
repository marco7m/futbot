#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H

#include <vector>
#include "src/neuralnetwork/neuralnetwork.h"

class ControlSystem{
public:
    ControlSystem();
    ~ControlSystem();

private:
    // parametros de configuração
    int ia_number;    

    std::vector<NeuralNetwork*> create_random_population();
    void clear_population();

    std::vector<NeuralNetwork*> population;

};

#endif
