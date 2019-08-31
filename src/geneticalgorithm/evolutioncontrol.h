#ifndef EVOLUTIONCONTROL_H
#define EVOLUTIONCONTROL_H

#include "src/neuralnetwork/neuralnetwork.h"
#include "src/geneticalgorithm/crossover.h"
#include "src/controlsystem/gameplay.h"
#include <vector>
#include <algorithm> // sort()

class EvolutionControl{
public:
    EvolutionControl();
    ~EvolutionControl();
    
    void create_random_population(int population_size);
    void clear_population();
    
    void train_the_guys(int play_time);

private:
    struct Individual{
        double fit;
        NeuralNetwork* net;
    };

    std::vector<Individual> population;

};

#endif
