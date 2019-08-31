#ifndef EVOLUTIONCONTROL_H
#define EVOLUTIONCONTROL_H

#include "src/neuralnetwork/neuralnetwork.h"
#include "src/geneticalgorithm/crossover.h"
#include <vector>
#include <algorithm> // sort()

class EvolutionControl{
public:
    EvolutionControl();
    ~EvolutionControl();
    
    void create_random_population();
    void clear_population();
    
private:
    std::vector<NeuralNetwork*> population;

    struct Individual{
        double fitness;
        NeuralNetwork* net;
    };

};

#endif
