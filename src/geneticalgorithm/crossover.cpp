#include "crossover.h"

Crossover::Crossover(){

}

void Crossover::alone(NeuralNetwork* nn, float rand_factor){
    std::srand(std::time(nullptr));
    for(int col = 0; col < nn->num_column(); col++){ // go through the columns
        for(int neu = 0; neu < nn->num_neurons_in_column(col); neu++){ // go through the neurons
            nn->set_neuron_bias(col, neu, nn->get_neuron_bias(col, neu) + simple_rand(rand_factor)); // update the bias
            for(int wgh = 0; wgh < nn->num_inputs_neuron(col, neu); wgh++){ // go through the weights of each neuron
                nn->set_neuron_weight(col, neu, wgh, nn->get_neuron_weight(col, neu, wgh) + simple_rand(rand_factor)); // update the weight
            }
        }
    }
}

// return a simetric random variable between -max and +max
double Crossover::simple_rand(double max){
    return (((double) std::rand() / (double) RAND_MAX) * 2 * max) - max;
}
