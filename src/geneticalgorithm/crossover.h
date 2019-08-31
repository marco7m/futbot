#ifndef CROSSOVER_H
#define CROSSOVER_H

#include "src/neuralnetwork/neuralnetwork.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class Crossover{
public:
    Crossover();

    void alone(NeuralNetwork* nn, float rand_factor);
    
    double simple_rand(double max);
private:

};

#endif
